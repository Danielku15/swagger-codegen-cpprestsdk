

#include "StoreApi.h"
#include "IHttpBody.h"
#include "JsonBody.h"
#include "MultipartFormData.h"

#include <unordered_set>



namespace swagger {

namespace petshop {

namespace api {


using namespace swagger::petshop::model;

StoreApi::StoreApi( std::shared_ptr<ApiConfiguration> configuration )
    : ApiBase(configuration)
{
}

StoreApi::~StoreApi()
{
}


pplx::task<void> StoreApi::deleteOrder(int64_t orderId)
{
    
    
    utility::string_t path = U("/store/order/{orderId}");
    std::map<utility::string_t, utility::string_t> pathParams;
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( m_Configuration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> acceptHttpContentTypes;
    acceptHttpContentTypes.insert( U("application/xml") );
    acceptHttpContentTypes.insert( U("application/json") );
    
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    
    
    
    {
        pathParams[U("orderId")] = ApiBase::parameterToString(orderId);
        
    }
    

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t httpContentType;
   
    // use JSON if possible
    if ( consumeHttpContentTypes.find(U("application/json")) != consumeHttpContentTypes.end() )
    {
        httpContentType = U("application/json");

        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        httpContentType = U("multipart/form-data");
        
        
    }
    else
    {
        throw ApiException(415, U("StoreApi->deleteOrder does not consume any supported media type"));
    }    
    
    
    
    return ApiBase::callApi(path, U("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, pathParams, httpContentType)
    .then([=](web::http::http_response response)
    {
        printf("Received response status code:%u\n", response.status_code());
        return response.extract_string();
    })
    .then([=](utility::string_t result)
    {
        std::wcout << result << std::endl;
        return void();
    });            
}

pplx::task<std::map<utility::string_t, int32_t>> StoreApi::getInventory()
{
    
    
    utility::string_t path = U("/store/inventory");
    std::map<utility::string_t, utility::string_t> pathParams;
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( m_Configuration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> acceptHttpContentTypes;
    acceptHttpContentTypes.insert( U("application/json") );
    
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    
    
    

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t httpContentType;
   
    // use JSON if possible
    if ( consumeHttpContentTypes.find(U("application/json")) != consumeHttpContentTypes.end() )
    {
        httpContentType = U("application/json");

        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        httpContentType = U("multipart/form-data");
        
        
    }
    else
    {
        throw ApiException(415, U("StoreApi->getInventory does not consume any supported media type"));
    }    
    
    
    // authentication (api_key) required
    
    
    {
        utility::string_t apiKey = m_Configuration->getApiKey(U("api_key"));
        if ( apiKey.size() > 0 )
        {
            headerParams[U("api_key")] = apiKey;
        }
    }
    
    
    
    
    
    
    
    return ApiBase::callApi(path, U("GET"), queryParams, httpBody, headerParams, formParams, fileParams, pathParams, httpContentType)
    .then([=](web::http::http_response response)
    {
        printf("Received response status code:%u\n", response.status_code());
        return response.extract_string();
    })
    .then([=](utility::string_t result)
    {
        std::wcout << result << std::endl;
        return std::map<utility::string_t, int32_t>();
    });            
}

pplx::task<std::shared_ptr<Order>> StoreApi::getOrderById(int64_t orderId)
{
    
    
    utility::string_t path = U("/store/order/{orderId}");
    std::map<utility::string_t, utility::string_t> pathParams;
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( m_Configuration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> acceptHttpContentTypes;
    acceptHttpContentTypes.insert( U("application/xml") );
    acceptHttpContentTypes.insert( U("application/json") );
    
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    
    
    
    {
        pathParams[U("orderId")] = ApiBase::parameterToString(orderId);
        
    }
    

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t httpContentType;
   
    // use JSON if possible
    if ( consumeHttpContentTypes.find(U("application/json")) != consumeHttpContentTypes.end() )
    {
        httpContentType = U("application/json");

        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        httpContentType = U("multipart/form-data");
        
        
    }
    else
    {
        throw ApiException(415, U("StoreApi->getOrderById does not consume any supported media type"));
    }    
    
    
    
    return ApiBase::callApi(path, U("GET"), queryParams, httpBody, headerParams, formParams, fileParams, pathParams, httpContentType)
    .then([=](web::http::http_response response)
    {
        printf("Received response status code:%u\n", response.status_code());
        return response.extract_string();
    })
    .then([=](utility::string_t result)
    {
        std::wcout << result << std::endl;
        return std::shared_ptr<Order>();
    });            
}

pplx::task<std::shared_ptr<Order>> StoreApi::placeOrder(std::shared_ptr<Order> body)
{
    
    // verify the required parameter 'body' is set
    if (body == nullptr)
    {
        throw ApiException(400, U("Missing required parameter 'body' when calling StoreApi->placeOrder"));
    }
    
    
    utility::string_t path = U("/store/order");
    std::map<utility::string_t, utility::string_t> pathParams;
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( m_Configuration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> acceptHttpContentTypes;
    acceptHttpContentTypes.insert( U("application/xml") );
    acceptHttpContentTypes.insert( U("application/json") );
    
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    
    
    

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t httpContentType;
   
    // use JSON if possible
    if ( consumeHttpContentTypes.find(U("application/json")) != consumeHttpContentTypes.end() )
    {
        httpContentType = U("application/json");

        
        web::json::value json;
 
        
        json = body.get() ? body->toJson() : web::json::value::null();
        
        
        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
        
        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        httpContentType = U("multipart/form-data");
        
        
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);
        
        if(body.get())
        {
            body->toMultipart(multipart, "body");
        }
        

        httpBody = multipart;
        
    }
    else
    {
        throw ApiException(415, U("StoreApi->placeOrder does not consume any supported media type"));
    }    
    
    
    
    return ApiBase::callApi(path, U("POST"), queryParams, httpBody, headerParams, formParams, fileParams, pathParams, httpContentType)
    .then([=](web::http::http_response response)
    {
        printf("Received response status code:%u\n", response.status_code());
        return response.extract_string();
    })
    .then([=](utility::string_t result)
    {
        std::wcout << result << std::endl;
        return std::shared_ptr<Order>();
    });            
}



}

}

}



