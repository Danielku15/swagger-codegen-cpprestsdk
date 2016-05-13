#include "ApiException.h"


namespace swagger {

namespace petshop {

namespace api {


ApiException::ApiException( uint32_t statusCode
    , const utility::string_t& message
    , std::shared_ptr<std::istream> content /*= nullptr*/ )
    : m_StatusCode(statusCode)
    , m_Message(message)
    , m_Content(content)
{
}
ApiException::ApiException( uint32_t statusCode
    , const utility::string_t& message
    , std::map<utility::string_t, utility::string_t>& headers
    , std::shared_ptr<std::istream> content /*= nullptr*/ )
    : m_StatusCode(statusCode)
    , m_Message(message)
    , m_Headers(headers)
    , m_Content(content)
{
}

ApiException::~ApiException()
{
}

uint32_t ApiException::getStatusCode() const
{
    return m_StatusCode;
}
utility::string_t ApiException::getMessage() const
{
    return m_Message;
}
std::shared_ptr<std::istream> ApiException::getContent()
{
    return m_Content;
}

std::map<utility::string_t, utility::string_t>& ApiException::getHeaders()
{
    return m_Headers;
}

const char* ApiException::what() const throw()
{
    const char* message = reinterpret_cast<const char*>(&m_Message[0]);
    return message;
}


}

}

}
