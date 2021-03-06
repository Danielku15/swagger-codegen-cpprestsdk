#include "ApiClient.h"
#include "MultipartFormData.h"
#include "ModelBase.h"


namespace swagger {

namespace petshop {

namespace api {


using namespace swagger::petshop::model;

ApiClient::ApiClient(std::shared_ptr<ApiConfiguration> configuration )
    : m_Configuration(configuration)
{
}
ApiClient::~ApiClient()
{
}

std::shared_ptr<ApiConfiguration> ApiClient::getConfiguration() const
{
    return m_Configuration;
}
void ApiClient::setConfiguration(std::shared_ptr<ApiConfiguration> configuration)
{
    m_Configuration = configuration;
}


utility::string_t ApiClient::parameterToString(utility::string_t value)
{
    return value;
}
utility::string_t ApiClient::parameterToString(int64_t value)
{
    return std::to_wstring(value);
}
utility::string_t ApiClient::parameterToString(int32_t value)
{
    return std::to_wstring(value);
}

pplx::task<web::http::http_response> ApiClient::callApi( 
    const utility::string_t& path, 
    const utility::string_t& method, 
    const std::map<utility::string_t, utility::string_t>& queryParams, 
    const std::shared_ptr<IHttpBody> postBody,
    const std::map<utility::string_t, utility::string_t>& headerParams, 
    const std::map<utility::string_t, utility::string_t>& formParams, 
    const std::map<utility::string_t, std::shared_ptr<HttpContent>>& fileParams,
    const utility::string_t& contentType
) const
{
	if (postBody != nullptr && formParams.size() != 0)
	{
		throw ApiException(400, U("Cannot have body and form params"));
	}

	if (postBody != nullptr && fileParams.size() != 0)
	{
		throw ApiException(400, U("Cannot have body and file params"));
	}

	if (fileParams.size() > 0 && contentType != U("multipart/form-data"))
	{
		throw ApiException(400, U("Operations with file parameters must be called with multipart/form-data"));
	}

	web::http::client::http_client client(m_Configuration->getBaseUrl(), m_Configuration->getHttpConfig());

	web::http::http_request request;
	for ( auto& kvp : headerParams )
	{
		request.headers().add(kvp.first, kvp.second);
	}

	if (fileParams.size() > 0)
	{
		MultipartFormData uploadData;
		for (auto& kvp : formParams)
		{
			uploadData.add(ModelBase::toHttpContent(kvp.first, kvp.second));
		}
		for (auto& kvp : fileParams)
		{
			uploadData.add(ModelBase::toHttpContent(kvp.first, kvp.second));
		}
		std::stringstream data;
		postBody->writeTo(data);
		auto bodyString = data.str();
		auto length = bodyString.size();
		request.set_body(concurrency::streams::bytestream::open_istream(std::move(bodyString)), length, contentType);
	}
	else
	{
		if (postBody != nullptr)
		{
			std::stringstream data;
			postBody->writeTo(data);
			auto bodyString = data.str();
			auto length = bodyString.size();
			request.set_body(concurrency::streams::bytestream::open_istream(std::move(bodyString)), length, contentType);
		}
		else
		{
			web::http::uri_builder formData;
			for (auto& kvp : formParams)
			{
				formData.append_query(kvp.first, kvp.second);
			}
			request.set_body(formData.query(), U("application/x-www-form-urlencoded"));
		}
	}

	web::http::uri_builder builder(path);
	for (auto& kvp : queryParams)
	{
		builder.append_query(kvp.first, kvp.second);
	}
	request.set_request_uri(builder.to_uri());
	request.set_method(method);
	if ( !request.headers().has( web::http::header_names::user_agent ) )
	{
		request.headers().add( web::http::header_names::user_agent, m_Configuration->getUserAgent() );
	}	

	return client.request(request);
}


}

}

}
