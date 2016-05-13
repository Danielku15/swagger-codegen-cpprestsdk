

#include "PetApi.h"
#include "IHttpBody.h"
#include "JsonBody.h"
#include "MultipartFormData.h"

#include <unordered_set>



namespace swagger {

namespace petshop {

namespace api {


using namespace swagger::petshop::model;

PetApi::PetApi( std::shared_ptr<ApiClient> apiClient )
    : m_ApiClient(apiClient)
{
}

PetApi::~PetApi()
{
}


pplx::task<void> PetApi::addPet(std::shared_ptr<Pet> body)
{
    
    // verify the required parameter 'body' is set
    if (body == nullptr)
    {
        throw ApiException(400, U("Missing required parameter 'body' when calling PetApi->addPet"));
    }
    
    
    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = U("/pet");
    std::map<utility::string_t, utility::string_t> pathParams;
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> acceptHttpContentTypes;
    acceptHttpContentTypes.insert( U("application/xml") );
    acceptHttpContentTypes.insert( U("application/json") );
    
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( U("application/json") );
    consumeHttpContentTypes.insert( U("application/xml") );
    
    
    

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t httpContentType;
   
    // use JSON if possible
    if ( consumeHttpContentTypes.find(U("application/json")) != consumeHttpContentTypes.end() )
    {
        httpContentType = U("application/json");

        
        web::json::value json;
 
        json = ModelBase::toJson(body);
        
        
        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
        
        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        httpContentType = U("multipart/form-data");
        
        
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);
        
        if(body.get())
        {
            body->toMultipart(multipart, U("body"));
        }
        

        httpBody = multipart;
        
    }
    else
    {
        throw ApiException(415, U("PetApi->addPet does not consume any supported media type"));
    }    
    
    
    // authentication (petstore_auth) required
    
    
    
    // oauth2 authentication is added automatically as part of the http_client_config
    
    
    
    return m_ApiClient->callApi(path, U("POST"), queryParams, httpBody, headerParams, formParams, fileParams, pathParams, httpContentType)
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

pplx::task<void> PetApi::deletePet(int64_t petId, utility::string_t apiKey)
{
    
    
    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = U("/pet/{petId}");
    std::map<utility::string_t, utility::string_t> pathParams;
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> acceptHttpContentTypes;
    acceptHttpContentTypes.insert( U("application/xml") );
    acceptHttpContentTypes.insert( U("application/json") );
    
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    
    
    
    {
        pathParams[U("petId")] = ApiClient::parameterToString(petId);
        
    }
    
    {
        headerParams[U("api_key")] = ApiClient::parameterToString(apiKey);
        
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
        throw ApiException(415, U("PetApi->deletePet does not consume any supported media type"));
    }    
    
    
    // authentication (petstore_auth) required
    
    
    
    // oauth2 authentication is added automatically as part of the http_client_config
    
    
    
    return m_ApiClient->callApi(path, U("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, pathParams, httpContentType)
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

pplx::task<std::vector<std::shared_ptr<Pet>>> PetApi::findPetsByStatus(std::vector<utility::string_t> status)
{
    
    
    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = U("/pet/findByStatus");
    std::map<utility::string_t, utility::string_t> pathParams;
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> acceptHttpContentTypes;
    acceptHttpContentTypes.insert( U("application/xml") );
    acceptHttpContentTypes.insert( U("application/json") );
    
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    
    
    
    {
        queryParams[U("status")] = ApiClient::parameterToArrayString<utility::string_t>(status);
        
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
        throw ApiException(415, U("PetApi->findPetsByStatus does not consume any supported media type"));
    }    
    
    
    // authentication (petstore_auth) required
    
    
    
    // oauth2 authentication is added automatically as part of the http_client_config
    
    
    
    return m_ApiClient->callApi(path, U("GET"), queryParams, httpBody, headerParams, formParams, fileParams, pathParams, httpContentType)
    .then([=](web::http::http_response response)
    {
        printf("Received response status code:%u\n", response.status_code());
        return response.extract_string();
    })
    .then([=](utility::string_t result)
    {
        std::wcout << result << std::endl;
        return std::vector<std::shared_ptr<Pet>>();
    });            
}

pplx::task<std::vector<std::shared_ptr<Pet>>> PetApi::findPetsByTags(std::vector<utility::string_t> tags)
{
    
    
    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = U("/pet/findByTags");
    std::map<utility::string_t, utility::string_t> pathParams;
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> acceptHttpContentTypes;
    acceptHttpContentTypes.insert( U("application/xml") );
    acceptHttpContentTypes.insert( U("application/json") );
    
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    
    
    
    {
        queryParams[U("tags")] = ApiClient::parameterToArrayString<>(tags);
        
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
        throw ApiException(415, U("PetApi->findPetsByTags does not consume any supported media type"));
    }    
    
    
    // authentication (petstore_auth) required
    
    
    
    // oauth2 authentication is added automatically as part of the http_client_config
    
    
    
    return m_ApiClient->callApi(path, U("GET"), queryParams, httpBody, headerParams, formParams, fileParams, pathParams, httpContentType)
    .then([=](web::http::http_response response)
    {
        printf("Received response status code:%u\n", response.status_code());
        return response.extract_string();
    })
    .then([=](utility::string_t result)
    {
        std::wcout << result << std::endl;
        return std::vector<std::shared_ptr<Pet>>();
    });            
}

pplx::task<std::shared_ptr<Pet>> PetApi::getPetById(int64_t petId)
{
    
    
    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = U("/pet/{petId}");
    std::map<utility::string_t, utility::string_t> pathParams;
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> acceptHttpContentTypes;
    acceptHttpContentTypes.insert( U("application/xml") );
    acceptHttpContentTypes.insert( U("application/json") );
    
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    
    
    
    {
        pathParams[U("petId")] = ApiClient::parameterToString(petId);
        
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
        throw ApiException(415, U("PetApi->getPetById does not consume any supported media type"));
    }    
    
    
    // authentication (api_key) required
    
    
    {
        utility::string_t apiKey = apiConfiguration->getApiKey(U("api_key"));
        if ( apiKey.size() > 0 )
        {
            headerParams[U("api_key")] = apiKey;
        }
    }
    
    
    
    
    
    
    
    return m_ApiClient->callApi(path, U("GET"), queryParams, httpBody, headerParams, formParams, fileParams, pathParams, httpContentType)
    .then([=](web::http::http_response response)
    {
        printf("Received response status code:%u\n", response.status_code());
        return response.extract_string();
    })
    .then([=](utility::string_t result)
    {
        std::wcout << result << std::endl;
        return std::shared_ptr<Pet>();
    });            
}

pplx::task<void> PetApi::updatePet(std::shared_ptr<Pet> body)
{
    
    // verify the required parameter 'body' is set
    if (body == nullptr)
    {
        throw ApiException(400, U("Missing required parameter 'body' when calling PetApi->updatePet"));
    }
    
    
    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = U("/pet");
    std::map<utility::string_t, utility::string_t> pathParams;
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> acceptHttpContentTypes;
    acceptHttpContentTypes.insert( U("application/xml") );
    acceptHttpContentTypes.insert( U("application/json") );
    
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( U("application/json") );
    consumeHttpContentTypes.insert( U("application/xml") );
    
    
    

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t httpContentType;
   
    // use JSON if possible
    if ( consumeHttpContentTypes.find(U("application/json")) != consumeHttpContentTypes.end() )
    {
        httpContentType = U("application/json");

        
        web::json::value json;
 
        json = ModelBase::toJson(body);
        
        
        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
        
        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        httpContentType = U("multipart/form-data");
        
        
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);
        
        if(body.get())
        {
            body->toMultipart(multipart, U("body"));
        }
        

        httpBody = multipart;
        
    }
    else
    {
        throw ApiException(415, U("PetApi->updatePet does not consume any supported media type"));
    }    
    
    
    // authentication (petstore_auth) required
    
    
    
    // oauth2 authentication is added automatically as part of the http_client_config
    
    
    
    return m_ApiClient->callApi(path, U("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, pathParams, httpContentType)
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

pplx::task<void> PetApi::updatePetWithForm(int64_t petId, utility::string_t name, utility::string_t status)
{
    
    
    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = U("/pet/{petId}");
    std::map<utility::string_t, utility::string_t> pathParams;
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> acceptHttpContentTypes;
    acceptHttpContentTypes.insert( U("application/xml") );
    acceptHttpContentTypes.insert( U("application/json") );
    
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( U("application/x-www-form-urlencoded") );
    
    
    
    {
        pathParams[U("petId")] = ApiClient::parameterToString(petId);
        
    }
    
    {
        formParams[ U("name") ] = ApiClient::parameterToString(name);
        
    }
    
    {
        formParams[ U("status") ] = ApiClient::parameterToString(status);
        
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
        throw ApiException(415, U("PetApi->updatePetWithForm does not consume any supported media type"));
    }    
    
    
    // authentication (petstore_auth) required
    
    
    
    // oauth2 authentication is added automatically as part of the http_client_config
    
    
    
    return m_ApiClient->callApi(path, U("POST"), queryParams, httpBody, headerParams, formParams, fileParams, pathParams, httpContentType)
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

pplx::task<std::shared_ptr<ApiResponse>> PetApi::uploadFile(int64_t petId, utility::string_t additionalMetadata, std::shared_ptr<HttpContent> file)
{
    
    
    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = U("/pet/{petId}/uploadImage");
    std::map<utility::string_t, utility::string_t> pathParams;
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> acceptHttpContentTypes;
    acceptHttpContentTypes.insert( U("application/json") );
    
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( U("multipart/form-data") );
    
    
    
    {
        pathParams[U("petId")] = ApiClient::parameterToString(petId);
        
    }
    
    {
        formParams[ U("additionalMetadata") ] = ApiClient::parameterToString(additionalMetadata);
        
    }
    if (file != nullptr)
    {
        fileParams[ U("file") ] = file;
        
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
        throw ApiException(415, U("PetApi->uploadFile does not consume any supported media type"));
    }    
    
    
    // authentication (petstore_auth) required
    
    
    
    // oauth2 authentication is added automatically as part of the http_client_config
    
    
    
    return m_ApiClient->callApi(path, U("POST"), queryParams, httpBody, headerParams, formParams, fileParams, pathParams, httpContentType)
    .then([=](web::http::http_response response)
    {
        printf("Received response status code:%u\n", response.status_code());
        return response.extract_string();
    })
    .then([=](utility::string_t result)
    {
        std::wcout << result << std::endl;
        return std::shared_ptr<ApiResponse>();
    });            
}



}

}

}



