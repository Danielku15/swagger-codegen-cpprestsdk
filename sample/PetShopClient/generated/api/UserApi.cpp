

#include "UserApi.h"
#include "IHttpBody.h"
#include "JsonBody.h"
#include "MultipartFormData.h"

#include <unordered_set>

BEGIN_SDK_NS

USE_SDK_NS(model)

namespace api {

UserApi::UserApi( std::shared_ptr<ApiConfiguration> configuration )
    : ApiBase(configuration)
{
}

UserApi::~UserApi()
{
}


pplx::task<void> UserApi::createUser(std::shared_ptr<User> body)
{
    
    // verify the required parameter 'body' is set
    if (body == nullptr)
    {
        throw ApiException(400, U("Missing required parameter 'body' when calling UserApi->createUser"));
    }
    
    
    utility::string_t path = U("/user");
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
        throw ApiException(415, U("UserApi->createUser does not consume any supported media type"));
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
        return void();
    });            
}

pplx::task<void> UserApi::createUsersWithArrayInput(std::vector<std::shared_ptr<User>> body)
{
    
    
    utility::string_t path = U("/user/createWithArray");
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
 
        
        {
            std::vector<web::json::value> jsonArray;
            for( auto& item : body )
            {
                jsonArray.push_back( item.get() ? item->toJson() : web::json::value::null() );
                
            }
            json = web::json::value::array(jsonArray);
        }
        
        
        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
        
        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        httpContentType = U("multipart/form-data");
        
        
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);
        
        {
            std::vector<web::json::value> jsonArray;
            for( auto& item : body )
            {
                jsonArray.push_back( item.get() ? item->toJson() : web::json::value::null() );
                
            }
            multipart->add(ModelBase::toHttpContent("body", web::json::value::array(jsonArray), "application/json"));
        }
        

        httpBody = multipart;
        
    }
    else
    {
        throw ApiException(415, U("UserApi->createUsersWithArrayInput does not consume any supported media type"));
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
        return void();
    });            
}

pplx::task<void> UserApi::createUsersWithListInput(std::vector<std::shared_ptr<User>> body)
{
    
    
    utility::string_t path = U("/user/createWithList");
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
 
        
        {
            std::vector<web::json::value> jsonArray;
            for( auto& item : body )
            {
                jsonArray.push_back( item.get() ? item->toJson() : web::json::value::null() );
                
            }
            json = web::json::value::array(jsonArray);
        }
        
        
        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
        
        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        httpContentType = U("multipart/form-data");
        
        
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);
        
        {
            std::vector<web::json::value> jsonArray;
            for( auto& item : body )
            {
                jsonArray.push_back( item.get() ? item->toJson() : web::json::value::null() );
                
            }
            multipart->add(ModelBase::toHttpContent("body", web::json::value::array(jsonArray), "application/json"));
        }
        

        httpBody = multipart;
        
    }
    else
    {
        throw ApiException(415, U("UserApi->createUsersWithListInput does not consume any supported media type"));
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
        return void();
    });            
}

pplx::task<void> UserApi::deleteUser(utility::string_t username)
{
    
    
    utility::string_t path = U("/user/{username}");
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
        pathParams[U("username")] = ApiBase::parameterToString(username);
        
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
        throw ApiException(415, U("UserApi->deleteUser does not consume any supported media type"));
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

pplx::task<std::shared_ptr<User>> UserApi::getUserByName(utility::string_t username)
{
    
    
    utility::string_t path = U("/user/{username}");
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
        pathParams[U("username")] = ApiBase::parameterToString(username);
        
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
        throw ApiException(415, U("UserApi->getUserByName does not consume any supported media type"));
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
        return std::shared_ptr<User>();
    });            
}

pplx::task<utility::string_t> UserApi::loginUser(utility::string_t username, utility::string_t password)
{
    
    
    utility::string_t path = U("/user/login");
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
        queryParams[U("username")] = ApiBase::parameterToString(username);
        
    }
    
    {
        queryParams[U("password")] = ApiBase::parameterToString(password);
        
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
        throw ApiException(415, U("UserApi->loginUser does not consume any supported media type"));
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
        return utility::string_t();
    });            
}

pplx::task<void> UserApi::logoutUser()
{
    
    
    utility::string_t path = U("/user/logout");
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

        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        httpContentType = U("multipart/form-data");
        
        
    }
    else
    {
        throw ApiException(415, U("UserApi->logoutUser does not consume any supported media type"));
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
        return void();
    });            
}

pplx::task<void> UserApi::updateUser(utility::string_t username, std::shared_ptr<User> body)
{
    
    // verify the required parameter 'body' is set
    if (body == nullptr)
    {
        throw ApiException(400, U("Missing required parameter 'body' when calling UserApi->updateUser"));
    }
    
    
    utility::string_t path = U("/user/{username}");
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
        pathParams[U("username")] = ApiBase::parameterToString(username);
        
    }
    

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
        throw ApiException(415, U("UserApi->updateUser does not consume any supported media type"));
    }    
    
    
    
    return ApiBase::callApi(path, U("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, pathParams, httpContentType)
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

}

END_SDK_NS


