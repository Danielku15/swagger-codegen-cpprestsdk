/*
 * HttpContent.h
 * 
 * This class represents a single item of a multipart-formdata request. 
 */

#ifndef HttpContent_H_
#define HttpContent_H_

#include "Commons.h"

#include <cpprest/details/basic_types.h>
#include <memory>

BEGIN_SDK_NS

namespace model {

class SDK_DECLSPEC HttpContent
{
public:
    HttpContent();
    virtual ~HttpContent();

    virtual std::string getContentDisposition();
    virtual void setContentDisposition( const std::string& value );

    virtual std::string getName();
    virtual void setName( const std::string& value );

    virtual std::string getFileName();
    virtual void setFileName( const std::string& value );

    virtual std::string getContentType();
    virtual void setContentType( const std::string& value );

    virtual std::shared_ptr<std::iostream> getData();
    virtual void setData( std::shared_ptr<std::iostream> value );
    
protected:
	// NOTE: no utility::string_t here because those strings can only contain ascii
    std::string m_ContentDisposition;
    std::string m_Name;
    std::string m_FileName;
    std::string m_ContentType;
    std::shared_ptr<std::iostream> m_Data;
};

}

END_SDK_NS

#endif /* HttpContent_H_ */