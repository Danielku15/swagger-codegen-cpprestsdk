/*
 * ApiBase.h
 * 
 * This is the base class for all API classes
 */

#ifndef ApiBase_H_
#define ApiBase_H_

#include "Commons.h"
#include "ApiConfiguration.h"
#include "ApiException.h"
#include "IHttpBody.h"
#include "HttpContent.h"

#include <cpprest/details/basic_types.h>
#include <cpprest/http_client.h>
#include <memory> 
#include <vector> 


BEGIN_SDK_NS

namespace api {

USE_SDK_NS(model)

class SDK_DECLSPEC ApiBase
{
public:
    ApiBase( std::shared_ptr<ApiConfiguration> configuration );
    virtual ~ApiBase();
    
    static utility::string_t parameterToString(utility::string_t value);
    static utility::string_t parameterToString(int32_t value);
    static utility::string_t parameterToString(int64_t value);
    
    template<class T>
    static utility::string_t parameterToArrayString(std::vector<T> value)
    {
        utility::stringstream_t ss;
        
        int i = 0;
        for( size_t i = 0; i < value.size(); i++)
        {
            if( i > 0) ss << U(", ");
            ss << ApiBase::parameterToString(value[i]);
        }

        return ss.str();        
    }
    
protected:
    pplx::task<web::http::http_response> callApi( 
        const utility::string_t& path, 
        const utility::string_t& method, 
        const std::map<utility::string_t, utility::string_t> queryParams, 
        const std::shared_ptr<IHttpBody> postBody, 
        const std::map<utility::string_t, utility::string_t> headerParams, 
        const std::map<utility::string_t, utility::string_t> formParams, 
        const std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams, 
        const std::map<utility::string_t, utility::string_t> pathParams, 
        const utility::string_t& contentType
    );

    std::shared_ptr<ApiConfiguration> m_Configuration;
};

}

END_SDK_NS

#endif /* ApiBase_H_ */