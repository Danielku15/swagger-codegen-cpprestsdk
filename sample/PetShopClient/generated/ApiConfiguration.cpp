#include "ApiConfiguration.h"

BEGIN_SDK_NS

namespace api {

ApiConfiguration::ApiConfiguration()
{
}

ApiConfiguration::~ApiConfiguration()
{
}

utility::string_t ApiConfiguration::getBaseUrl() const
{
    return m_BaseUrl;
}

void ApiConfiguration::setBaseUrl( const utility::string_t value )
{
    m_BaseUrl = value;
}

utility::string_t ApiConfiguration::getUserAgent() const
{
    return m_UserAgent;
}

void ApiConfiguration::setUserAgent( const utility::string_t value )
{
    m_UserAgent = value;
}

std::map<utility::string_t, utility::string_t>& ApiConfiguration::getDefaultHeaders()
{
    return m_DefaultHeaders;
}

bool ApiConfiguration::hasBasicAuthentication() const
{
    return m_Username.size() > 0 && m_Password.size() > 0;
}

utility::string_t ApiConfiguration::getUsername() const
{
    return m_UserAgent;
}

utility::string_t ApiConfiguration::getPassword() const
{
    return m_Password;
}

bool ApiConfiguration::hasAccessToken() const
{
    return m_AccessToken.size() > 0;
}

utility::string_t ApiConfiguration::getAccessToken() const
{
    return m_AccessToken;
}

utility::string_t ApiConfiguration::getApiKey( const utility::string_t& prefix) const
{
    auto result = m_ApiKeys.find(prefix);
    if( result != m_ApiKeys.end() )
    {
        return result->second;
    }
    return U("");
}

void ApiConfiguration::setApiKey( const utility::string_t& prefix, const utility::string_t& apiKey )
{
    m_ApiKeys[prefix] = apiKey;
}

}

END_SDK_NS