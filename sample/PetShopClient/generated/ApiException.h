/*
 * ApiException.h
 * 
 * This is the exception being thrown in case the api call was not successful
 */

#ifndef ApiException_H_
#define ApiException_H_

#include "Commons.h"

#include <cpprest/details/basic_types.h>

#include <iostream> 
#include <memory> 
#include <exception>

BEGIN_SDK_NS

namespace api {

class SDK_DECLSPEC ApiException
    : public std::exception
{
public:
    ApiException( uint32_t statusCode, const utility::string_t& message, std::shared_ptr<std::iostream> content = nullptr );
    virtual ~ApiException();
    
    uint32_t getStatusCode() const;
    utility::string_t getMessage() const;
    std::shared_ptr<std::iostream> getContent();
    
    virtual const char* what() const throw();
    
protected:
    uint32_t m_StatusCode;
    utility::string_t m_Message;
    std::shared_ptr<std::iostream> m_Content;    
};

}

END_SDK_NS

#endif /* ApiBase_H_ */