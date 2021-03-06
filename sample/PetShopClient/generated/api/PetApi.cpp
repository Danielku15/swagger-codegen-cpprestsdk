

#include "PetApi.h"
#include "IHttpBody.h"
#include "JsonBody.h"
#include "MultipartFormData.h"

#include <unordered_set>

#include <boost/algorithm/string/replace.hpp>


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
    
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( U("application/xml") );
    responseHttpContentTypes.insert( U("application/json") );
    
    
    utility::string_t responseHttpContentType;
    
    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 || responseHttpContentTypes.find(U("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = U("application/json");
    }
    // multipart formdata 
    else if( responseHttpContentTypes.find(U("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = U("multipart/form-data");
    }
    else
    {
        throw ApiException(400, U("PetApi->addPet does not produce any supported media type"));
    }    
    
    headerParams[U("Accept")] = responseHttpContentType;
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( U("application/json") );
    consumeHttpContentTypes.insert( U("application/xml") );
    
    
    

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;
   
    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(U("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = U("application/json");

        
        web::json::value json;
 
        json = ModelBase::toJson(body);
        
        
        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
        
        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = U("multipart/form-data");
        
        
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);
        
        if(body.get())
        {
            body->toMultipart(multipart, U("body"));
        }
        

        httpBody = multipart;
        requestHttpContentType += U("; boundary=") + multipart->getBoundary();
        
    }
    else
    {
        throw ApiException(415, U("PetApi->addPet does not consume any supported media type"));
    }    
    
    
    // authentication (petstore_auth) required
    
    
    
    // oauth2 authentication is added automatically as part of the http_client_config
    
    
    
    return m_ApiClient->callApi(path, U("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
		// 1xx - informational : OK
		// 2xx - successful	   : OK
		// 3xx - redirection   : OK 
		// 4xx - client error  : not OK
		// 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
				, U("error calling addPet: ") + response.reason_phrase()
				, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}
        
        // check response content type
        if(response.headers().has(U("Content-Type")))
        {
            utility::string_t contentType = response.headers()[U("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , U("error calling addPet: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }
        
        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        return void();
        
    });            
}

pplx::task<void> PetApi::deletePet(int64_t petId, utility::string_t apiKey)
{
    
    
    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = U("/pet/{petId}");
    boost::replace_all(path, U("{") U("petId") U("}"), ApiClient::parameterToString(petId));
    
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( U("application/xml") );
    responseHttpContentTypes.insert( U("application/json") );
    
    
    utility::string_t responseHttpContentType;
    
    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 || responseHttpContentTypes.find(U("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = U("application/json");
    }
    // multipart formdata 
    else if( responseHttpContentTypes.find(U("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = U("multipart/form-data");
    }
    else
    {
        throw ApiException(400, U("PetApi->deletePet does not produce any supported media type"));
    }    
    
    headerParams[U("Accept")] = responseHttpContentType;
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    
    
    
    {
        
    }
    
    {
        headerParams[U("api_key")] = ApiClient::parameterToString(apiKey);
        
    }
    

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;
   
    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(U("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = U("application/json");

        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = U("multipart/form-data");
        
        
    }
    else
    {
        throw ApiException(415, U("PetApi->deletePet does not consume any supported media type"));
    }    
    
    
    // authentication (petstore_auth) required
    
    
    
    // oauth2 authentication is added automatically as part of the http_client_config
    
    
    
    return m_ApiClient->callApi(path, U("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
		// 1xx - informational : OK
		// 2xx - successful	   : OK
		// 3xx - redirection   : OK 
		// 4xx - client error  : not OK
		// 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
				, U("error calling deletePet: ") + response.reason_phrase()
				, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}
        
        // check response content type
        if(response.headers().has(U("Content-Type")))
        {
            utility::string_t contentType = response.headers()[U("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , U("error calling deletePet: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }
        
        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        return void();
        
    });            
}

pplx::task<std::vector<std::shared_ptr<Pet>>> PetApi::findPetsByStatus(std::vector<utility::string_t> status)
{
    
    
    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = U("/pet/findByStatus");
    
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( U("application/xml") );
    responseHttpContentTypes.insert( U("application/json") );
    
    
    utility::string_t responseHttpContentType;
    
    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 || responseHttpContentTypes.find(U("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = U("application/json");
    }
    // multipart formdata 
    else if( responseHttpContentTypes.find(U("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = U("multipart/form-data");
    }
    else
    {
        throw ApiException(400, U("PetApi->findPetsByStatus does not produce any supported media type"));
    }    
    
    headerParams[U("Accept")] = responseHttpContentType;
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    
    
    
    {
        queryParams[U("status")] = ApiClient::parameterToArrayString<utility::string_t>(status);
        
    }
    

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;
   
    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(U("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = U("application/json");

        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = U("multipart/form-data");
        
        
    }
    else
    {
        throw ApiException(415, U("PetApi->findPetsByStatus does not consume any supported media type"));
    }    
    
    
    // authentication (petstore_auth) required
    
    
    
    // oauth2 authentication is added automatically as part of the http_client_config
    
    
    
    return m_ApiClient->callApi(path, U("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
		// 1xx - informational : OK
		// 2xx - successful	   : OK
		// 3xx - redirection   : OK 
		// 4xx - client error  : not OK
		// 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
				, U("error calling findPetsByStatus: ") + response.reason_phrase()
				, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}
        
        // check response content type
        if(response.headers().has(U("Content-Type")))
        {
            utility::string_t contentType = response.headers()[U("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , U("error calling findPetsByStatus: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }
        
        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::vector<std::shared_ptr<Pet>> result;
        
        
        if(responseHttpContentType == U("application/json"))
        {
            web::json::value json = web::json::value::parse(response);
            
            for( auto& item : json.as_array() )
            {
                std::shared_ptr<Pet> itemObj(new Pet());
                itemObj->fromJson(item);
                result.push_back(itemObj);                
                
            }
            
        }
        // else if(responseHttpContentType == U("multipart/form-data"))
        // {
        // TODO multipart response parsing    
        // }
        else 
        {
			throw ApiException(500
				, U("error calling findPetsByStatus: unsupported response type"));
        }
        
        return result;
        
    });            
}

pplx::task<std::vector<std::shared_ptr<Pet>>> PetApi::findPetsByTags(std::vector<utility::string_t> tags)
{
    
    
    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = U("/pet/findByTags");
    
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( U("application/xml") );
    responseHttpContentTypes.insert( U("application/json") );
    
    
    utility::string_t responseHttpContentType;
    
    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 || responseHttpContentTypes.find(U("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = U("application/json");
    }
    // multipart formdata 
    else if( responseHttpContentTypes.find(U("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = U("multipart/form-data");
    }
    else
    {
        throw ApiException(400, U("PetApi->findPetsByTags does not produce any supported media type"));
    }    
    
    headerParams[U("Accept")] = responseHttpContentType;
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    
    
    
    {
        queryParams[U("tags")] = ApiClient::parameterToArrayString<>(tags);
        
    }
    

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;
   
    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(U("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = U("application/json");

        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = U("multipart/form-data");
        
        
    }
    else
    {
        throw ApiException(415, U("PetApi->findPetsByTags does not consume any supported media type"));
    }    
    
    
    // authentication (petstore_auth) required
    
    
    
    // oauth2 authentication is added automatically as part of the http_client_config
    
    
    
    return m_ApiClient->callApi(path, U("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
		// 1xx - informational : OK
		// 2xx - successful	   : OK
		// 3xx - redirection   : OK 
		// 4xx - client error  : not OK
		// 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
				, U("error calling findPetsByTags: ") + response.reason_phrase()
				, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}
        
        // check response content type
        if(response.headers().has(U("Content-Type")))
        {
            utility::string_t contentType = response.headers()[U("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , U("error calling findPetsByTags: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }
        
        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::vector<std::shared_ptr<Pet>> result;
        
        
        if(responseHttpContentType == U("application/json"))
        {
            web::json::value json = web::json::value::parse(response);
            
            for( auto& item : json.as_array() )
            {
                std::shared_ptr<Pet> itemObj(new Pet());
                itemObj->fromJson(item);
                result.push_back(itemObj);                
                
            }
            
        }
        // else if(responseHttpContentType == U("multipart/form-data"))
        // {
        // TODO multipart response parsing    
        // }
        else 
        {
			throw ApiException(500
				, U("error calling findPetsByStatus: unsupported response type"));
        }
        
        return result;
        
    });            
}

pplx::task<std::shared_ptr<Pet>> PetApi::getPetById(int64_t petId)
{
    
    
    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = U("/pet/{petId}");
    boost::replace_all(path, U("{") U("petId") U("}"), ApiClient::parameterToString(petId));
    
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( U("application/xml") );
    responseHttpContentTypes.insert( U("application/json") );
    
    
    utility::string_t responseHttpContentType;
    
    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 || responseHttpContentTypes.find(U("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = U("application/json");
    }
    // multipart formdata 
    else if( responseHttpContentTypes.find(U("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = U("multipart/form-data");
    }
    else
    {
        throw ApiException(400, U("PetApi->getPetById does not produce any supported media type"));
    }    
    
    headerParams[U("Accept")] = responseHttpContentType;
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    
    
    
    {
        
    }
    

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;
   
    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(U("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = U("application/json");

        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = U("multipart/form-data");
        
        
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
    
    
    
    
    
    
    
    return m_ApiClient->callApi(path, U("GET"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
		// 1xx - informational : OK
		// 2xx - successful	   : OK
		// 3xx - redirection   : OK 
		// 4xx - client error  : not OK
		// 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
				, U("error calling getPetById: ") + response.reason_phrase()
				, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}
        
        // check response content type
        if(response.headers().has(U("Content-Type")))
        {
            utility::string_t contentType = response.headers()[U("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , U("error calling getPetById: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }
        
        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<Pet> result(new Pet());
        
        if(responseHttpContentType == U("application/json"))
        {
            web::json::value json = web::json::value::parse(response);
            
            result->fromJson(json);
        }
        // else if(responseHttpContentType == U("multipart/form-data"))
        // {
        // TODO multipart response parsing    
        // }
        else 
        {
			throw ApiException(500
				, U("error calling findPetsByStatus: unsupported response type"));
        }
        
        return result;
        
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
    
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( U("application/xml") );
    responseHttpContentTypes.insert( U("application/json") );
    
    
    utility::string_t responseHttpContentType;
    
    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 || responseHttpContentTypes.find(U("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = U("application/json");
    }
    // multipart formdata 
    else if( responseHttpContentTypes.find(U("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = U("multipart/form-data");
    }
    else
    {
        throw ApiException(400, U("PetApi->updatePet does not produce any supported media type"));
    }    
    
    headerParams[U("Accept")] = responseHttpContentType;
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( U("application/json") );
    consumeHttpContentTypes.insert( U("application/xml") );
    
    
    

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;
   
    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(U("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = U("application/json");

        
        web::json::value json;
 
        json = ModelBase::toJson(body);
        
        
        httpBody = std::shared_ptr<IHttpBody>( new JsonBody( json ) );
        
        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = U("multipart/form-data");
        
        
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);
        
        if(body.get())
        {
            body->toMultipart(multipart, U("body"));
        }
        

        httpBody = multipart;
        requestHttpContentType += U("; boundary=") + multipart->getBoundary();
        
    }
    else
    {
        throw ApiException(415, U("PetApi->updatePet does not consume any supported media type"));
    }    
    
    
    // authentication (petstore_auth) required
    
    
    
    // oauth2 authentication is added automatically as part of the http_client_config
    
    
    
    return m_ApiClient->callApi(path, U("PUT"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
		// 1xx - informational : OK
		// 2xx - successful	   : OK
		// 3xx - redirection   : OK 
		// 4xx - client error  : not OK
		// 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
				, U("error calling updatePet: ") + response.reason_phrase()
				, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}
        
        // check response content type
        if(response.headers().has(U("Content-Type")))
        {
            utility::string_t contentType = response.headers()[U("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , U("error calling updatePet: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }
        
        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        return void();
        
    });            
}

pplx::task<void> PetApi::updatePetWithForm(int64_t petId, utility::string_t name, utility::string_t status)
{
    
    
    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = U("/pet/{petId}");
    boost::replace_all(path, U("{") U("petId") U("}"), ApiClient::parameterToString(petId));
    
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( U("application/xml") );
    responseHttpContentTypes.insert( U("application/json") );
    
    
    utility::string_t responseHttpContentType;
    
    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 || responseHttpContentTypes.find(U("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = U("application/json");
    }
    // multipart formdata 
    else if( responseHttpContentTypes.find(U("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = U("multipart/form-data");
    }
    else
    {
        throw ApiException(400, U("PetApi->updatePetWithForm does not produce any supported media type"));
    }    
    
    headerParams[U("Accept")] = responseHttpContentType;
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( U("application/x-www-form-urlencoded") );
    
    
    
    {
        
    }
    
    {
        formParams[ U("name") ] = ApiClient::parameterToString(name);
        
    }
    
    {
        formParams[ U("status") ] = ApiClient::parameterToString(status);
        
    }
    

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;
   
    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(U("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = U("application/json");

        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = U("multipart/form-data");
        
        
    }
    else
    {
        throw ApiException(415, U("PetApi->updatePetWithForm does not consume any supported media type"));
    }    
    
    
    // authentication (petstore_auth) required
    
    
    
    // oauth2 authentication is added automatically as part of the http_client_config
    
    
    
    return m_ApiClient->callApi(path, U("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
		// 1xx - informational : OK
		// 2xx - successful	   : OK
		// 3xx - redirection   : OK 
		// 4xx - client error  : not OK
		// 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
				, U("error calling updatePetWithForm: ") + response.reason_phrase()
				, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}
        
        // check response content type
        if(response.headers().has(U("Content-Type")))
        {
            utility::string_t contentType = response.headers()[U("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , U("error calling updatePetWithForm: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }
        
        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        return void();
        
    });            
}

pplx::task<std::shared_ptr<ApiResponse>> PetApi::uploadFile(int64_t petId, utility::string_t additionalMetadata, std::shared_ptr<HttpContent> file)
{
    
    
    std::shared_ptr<ApiConfiguration> apiConfiguration( m_ApiClient->getConfiguration() );
    utility::string_t path = U("/pet/{petId}/uploadImage");
    boost::replace_all(path, U("{") U("petId") U("}"), ApiClient::parameterToString(petId));
    
    
    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams( apiConfiguration->getDefaultHeaders() );
    std::map<utility::string_t, utility::string_t> formParams;
    std::map<utility::string_t, std::shared_ptr<HttpContent>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert( U("application/json") );
    
    
    utility::string_t responseHttpContentType;
    
    // use JSON if possible
    if ( responseHttpContentTypes.size() == 0 || responseHttpContentTypes.find(U("application/json")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = U("application/json");
    }
    // multipart formdata 
    else if( responseHttpContentTypes.find(U("multipart/form-data")) != responseHttpContentTypes.end() )
    {
        responseHttpContentType = U("multipart/form-data");
    }
    else
    {
        throw ApiException(400, U("PetApi->uploadFile does not produce any supported media type"));
    }    
    
    headerParams[U("Accept")] = responseHttpContentType;
    
    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert( U("multipart/form-data") );
    
    
    
    {
        
    }
    
    {
        formParams[ U("additionalMetadata") ] = ApiClient::parameterToString(additionalMetadata);
        
    }
    if (file != nullptr)
    {
        fileParams[ U("file") ] = file;
        
    }
    

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;
   
    // use JSON if possible
    if ( consumeHttpContentTypes.size() == 0 || consumeHttpContentTypes.find(U("application/json")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = U("application/json");

        
    }
    // multipart formdata 
    else if( consumeHttpContentTypes.find(U("multipart/form-data")) != consumeHttpContentTypes.end() )
    {
        requestHttpContentType = U("multipart/form-data");
        
        
    }
    else
    {
        throw ApiException(415, U("PetApi->uploadFile does not consume any supported media type"));
    }    
    
    
    // authentication (petstore_auth) required
    
    
    
    // oauth2 authentication is added automatically as part of the http_client_config
    
    
    
    return m_ApiClient->callApi(path, U("POST"), queryParams, httpBody, headerParams, formParams, fileParams, requestHttpContentType)
    .then([=](web::http::http_response response)
    {
		// 1xx - informational : OK
		// 2xx - successful	   : OK
		// 3xx - redirection   : OK 
		// 4xx - client error  : not OK
		// 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
				, U("error calling uploadFile: ") + response.reason_phrase()
				, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}
        
        // check response content type
        if(response.headers().has(U("Content-Type")))
        {
            utility::string_t contentType = response.headers()[U("Content-Type")];
            if( contentType.find(responseHttpContentType) == std::string::npos )
            {
                throw ApiException(500
                    , U("error calling uploadFile: unexpected response type: ") + contentType
                    , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
            }
        }
        
        return response.extract_string();
    })
    .then([=](utility::string_t response)
    {
        std::shared_ptr<ApiResponse> result(new ApiResponse());
        
        if(responseHttpContentType == U("application/json"))
        {
            web::json::value json = web::json::value::parse(response);
            
            result->fromJson(json);
        }
        // else if(responseHttpContentType == U("multipart/form-data"))
        // {
        // TODO multipart response parsing    
        // }
        else 
        {
			throw ApiException(500
				, U("error calling findPetsByStatus: unsupported response type"));
        }
        
        return result;
        
    });            
}



}

}

}



