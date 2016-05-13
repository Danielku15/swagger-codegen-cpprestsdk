#include "ApiBase.h"

BEGIN_SDK_NS

namespace api {

USE_SDK_NS(model)

ApiBase::ApiBase(std::shared_ptr<ApiConfiguration> configuration )
    : m_Configuration(configuration)
{
}
ApiBase::~ApiBase()
{
}

utility::string_t ApiBase::parameterToString(utility::string_t value)
{
    return value;
}
utility::string_t ApiBase::parameterToString(int64_t value)
{
    return std::to_wstring(value);
}
utility::string_t ApiBase::parameterToString(int32_t value)
{
    return std::to_wstring(value);
}

pplx::task<web::http::http_response> ApiBase::callApi( 
    const utility::string_t& path, 
    const utility::string_t& method, 
    const std::map<utility::string_t, utility::string_t> queryParams, 
    const std::shared_ptr<IHttpBody> postBody, 
    const std::map<utility::string_t, utility::string_t> headerParams, 
    const std::map<utility::string_t, utility::string_t> formParams, 
    const std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams, 
    const std::map<utility::string_t, utility::string_t> pathParams, 
    const utility::string_t& contentType
)
{
    // TODO: make http_client_config part of ApiConfiguration
    web::http::client::http_client_config config;

    web::http::uri_builder builder( m_Configuration->getBaseUrl() );
    web::http::client::http_client client(m_Configuration->getBaseUrl(), config);

    web::http::method httpMethod;

    
    return pplx::task<web::http::http_response>([=]()
    {
        return web::http::http_response();
    });
}


}

END_SDK_NS