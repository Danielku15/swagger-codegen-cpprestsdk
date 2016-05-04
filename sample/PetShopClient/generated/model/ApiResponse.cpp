

#include "ApiResponse.h"

BEGIN_SDK_NS

namespace model {

ApiResponse::ApiResponse()
{
}

ApiResponse::~ApiResponse()
{
}

void ApiResponse::validate() 
{
}

web::json::value ApiResponse::toJson() const
{
     web::json::value val;
     
	
    
	
    
	
    
	

    return val;
}

void ApiResponse::fromJson(web::json::value& json)
{
	
}

void ApiResponse::toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const
{
}

void ApiResponse::fromMultiPart(web::json::value& val, const std::string& namePrefix)
{
}
    
   
int32_t ApiResponse::getCode() const
{
	return m_Code;
}
void ApiResponse::setCode(int32_t value)
{
	m_Code = value;
}
 
void ApiResponse::unsetCode() 
{
    m_CodeIsSet = false;
}

utility::string_t ApiResponse::getType() const
{
	return m_Type;
}
void ApiResponse::setType(utility::string_t value)
{
	m_Type = value;
}
 
void ApiResponse::unsetType() 
{
    m_TypeIsSet = false;
}

utility::string_t ApiResponse::getMessage() const
{
	return m_Message;
}
void ApiResponse::setMessage(utility::string_t value)
{
	m_Message = value;
}
 
void ApiResponse::unsetMessage() 
{
    m_MessageIsSet = false;
}



}

END_SDK_NS


