/*
 * ApiException.h
 * 
 * This is the exception being thrown in case the api call was not successful
 */

#ifndef ApiException_H_
#define ApiException_H_

#include "Commons.h"

#include <memory> 
#include <map>

#include <cpprest/details/basic_types.h>



namespace swagger {

namespace petshop {

namespace api {


class PETSHOP_DECLSPEC ApiException
    : public std::exception
{
public:
    ApiException( uint32_t statusCode
        , const utility::string_t& message
        , std::shared_ptr<std::istream> content = nullptr );
    ApiException( uint32_t statusCode
        , const utility::string_t& message
        , std::map<utility::string_t, utility::string_t>& headers
        , std::shared_ptr<std::istream> content = nullptr );
    virtual ~ApiException();
    
    uint32_t getStatusCode() const;
    utility::string_t getMessage() const;
    std::map<utility::string_t, utility::string_t>& getHeaders();
    std::shared_ptr<std::istream> getContent() const;
    
    virtual const char* what() const throw();
    
protected:
    uint32_t m_StatusCode;
    utility::string_t m_Message;
    std::shared_ptr<std::istream> m_Content;    
    std::map<utility::string_t, utility::string_t> m_Headers;
};


}

}

}


#endif /* ApiBase_H_ */