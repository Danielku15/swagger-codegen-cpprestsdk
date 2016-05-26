#include "ApiBase.h"


namespace swagger {

namespace petshop {

namespace api {


using namespace swagger::petshop::model;

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
    return pplx::task<web::http::http_response>([=]()
    {
        return web::http::http_response();
    });
}


}

}

}
