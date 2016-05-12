

#include "StoreApi.h"
#include "IHttpBody.h"
#include "JsonBody.h"
#include "MultipartFormData.h"

#include <unordered_set>

BEGIN_SDK_NS

USE_SDK_NS(model)

namespace api {

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
    
    
    
    
    
    
    return pplx::task<void> ();
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
    
    
    
    
    
    
    
    // authentication (api_key) required
    
    
    {
        utility::string_t apiKey = m_Configuration->getApiKey(U("api_key"));
        if ( apiKey.size() > 0 )
        {
            headerParams[U("api_key")] = apiKey;
        }
    }
    
    
    
    
    
    
    
    return pplx::task<std::map<utility::string_t, int32_t>> ();
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
    
    
    
    
    
    
    return pplx::task<std::shared_ptr<Order>> ();
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
    
    // use JSON if possible
    if ( consumeHttpContentTypes.find(U("application/json")) != consumeHttpContentTypes.end() )
    {
        web::json::value json;
 
        
        json = body.get() ? body->toJson() : web::json::value::null();
        
        
        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
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
    
    
    
    
    return pplx::task<std::shared_ptr<Order>> ();
}



}

END_SDK_NS


