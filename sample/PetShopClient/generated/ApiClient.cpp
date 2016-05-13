#include "ApiClient.h"


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

std::shared_ptr<ApiConfiguration> ApiClient::getConfiguration()
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
    const std::map<utility::string_t, utility::string_t> queryParams, 
    const std::shared_ptr<IHttpBody> postBody, 
    const std::map<utility::string_t, utility::string_t> headerParams, 
    const std::map<utility::string_t, utility::string_t> formParams, 
    const std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams, 
    const std::map<utility::string_t, utility::string_t> pathParams, 
    const utility::string_t& contentType
)
{
    return pplx::task<web::http::http_response>([=]()
    {
        return web::http::http_response();
    });
}


}

}

}