/*
 * ApiConfiguration.h
 * 
 * This class represents a single item of a multipart-formdata request. 
 */

#ifndef ApiConfiguration_H_
#define ApiConfiguration_H_

#include "Commons.h"

#include <map>

#include <cpprest/details/basic_types.h> 


namespace swagger {

namespace petshop {

namespace api {


class PETSHOP_DECLSPEC ApiConfiguration
{
public:
    ApiConfiguration();
    virtual ~ApiConfiguration();
    
    utility::string_t getBaseUrl() const;
    void setBaseUrl( const utility::string_t value );
    
    utility::string_t getUserAgent() const;
    void setUserAgent( const utility::string_t value );
    
    std::map<utility::string_t, utility::string_t>& getDefaultHeaders();
    
    bool hasBasicAuthentication() const;
    utility::string_t getUsername() const;
    utility::string_t getPassword() const;
    
    bool hasAccessToken() const;
    utility::string_t getAccessToken() const;
    
    utility::string_t getApiKey( const utility::string_t& prefix) const;
    void setApiKey( const utility::string_t& prefix, const utility::string_t& apiKey );


protected:
    utility::string_t m_BaseUrl;
    std::map<utility::string_t, utility::string_t> m_DefaultHeaders;
    std::map<utility::string_t, utility::string_t> m_ApiKeys;
    utility::string_t m_UserAgent;
    utility::string_t m_Username;
    utility::string_t m_Password;
    utility::string_t m_AccessToken;
    
};


}

}

}

#endif /* ApiConfiguration_H_ */