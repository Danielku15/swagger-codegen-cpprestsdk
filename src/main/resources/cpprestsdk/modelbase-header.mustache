/*
 * ModelBase.h
 * 
 * This is the base class for all model classes
 */

#ifndef ModelBase_H_
#define ModelBase_H_

#include "Commons.h"

#include <cpprest/details/basic_types.h>
#include <cpprest/json.h> 

#include "HttpContent.h"
#include "MultipartFormData.h"

BEGIN_SDK_NS

namespace model {

class SDK_DECLSPEC ModelBase
{
public:
    ModelBase();
    virtual ~ModelBase();

    virtual void validate() = 0;

    virtual web::json::value toJson() const = 0;
    virtual void fromJson(web::json::value& json) = 0;

    virtual void toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const = 0;
    virtual void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) = 0;

    static web::json::value toJson( const utility::string_t& value );
    static web::json::value toJson( const utility::datetime& value );
    static web::json::value toJson( std::shared_ptr<HttpContent> value );
    static web::json::value toJson( int32_t value );
    static web::json::value toJson( int64_t value );
    static web::json::value toJson( double value );
    
    static int64_t int64_tFromJson(web::json::value& val);
    static int32_t int32_tFromJson(web::json::value& val);
    static utility::string_t stringFromJson(web::json::value& val);
    static utility::datetime dateFromJson(web::json::value& val);
    static bool boolFromJson(web::json::value& val);
        
    static std::shared_ptr<HttpContent> toHttpContent( const std::string& name, const utility::string_t& value, const std::string& contentType = "");
    static std::shared_ptr<HttpContent> toHttpContent( const std::string& name, const utility::datetime& value, const std::string& contentType = "" );
    static std::shared_ptr<HttpContent> toHttpContent( const std::string& name, std::shared_ptr<HttpContent> value );
    static std::shared_ptr<HttpContent> toHttpContent( const std::string& name, const web::json::value& value, const std::string& contentType = "application/json" );
    static std::shared_ptr<HttpContent> toHttpContent( const std::string& name, int32_t value, const std::string& contentType = "" );
    static std::shared_ptr<HttpContent> toHttpContent( const std::string& name, int64_t value, const std::string& contentType = "" );
    static std::shared_ptr<HttpContent> toHttpContent( const std::string& name, double value, const std::string& contentType = "" );
    
    static int64_t int64_tFromHttpContent(std::shared_ptr<HttpContent> val);
    static int32_t int32_tFromHttpContent(std::shared_ptr<HttpContent> val);
    static utility::string_t stringFromHttpContent(std::shared_ptr<HttpContent> val);
    static utility::datetime dateFromHttpContent(std::shared_ptr<HttpContent> val);
    static bool boolFromHttpContent(std::shared_ptr<HttpContent> val);
    

    static std::shared_ptr<HttpContent> streamFromBase64( const web::json::value& value );
    static std::string wstringToString( const std::wstring& value );
    static std::wstring stringToWstring( const std::string& value );
};

}

END_SDK_NS

#endif /* ModelBase_H_ */