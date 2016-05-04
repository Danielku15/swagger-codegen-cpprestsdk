

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
     
	if(m_CodeIsSet)
    {
        val[U("code")] = ModelBase::toJson(m_Code);
    }
    if(m_TypeIsSet)
    {
        val[U("type")] = ModelBase::toJson(m_Type);
                
    }
    if(m_MessageIsSet)
    {
        val[U("message")] = ModelBase::toJson(m_Message);
                
    }
    

    return val;
}

void ApiResponse::fromJson(web::json::value& val)
{
    if(val.has_field(U("code")))
    {
        setCode(ModelBase::int32_tFromJson(val[U("code")]));
    }
    if(val.has_field(U("type")))
    {
        setType(ModelBase::stringFromJson(val[U("type")]));
                
    }
    if(val.has_field(U("message")))
    {
        setMessage(ModelBase::stringFromJson(val[U("message")]));
                
    }
    
}

void ApiResponse::toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const
{
	if(m_CodeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "code", m_Code));
    }
    if(m_TypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "type", m_Type));
                
    }
    if(m_MessageIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "message", m_Message));
                
    }
    
}

void ApiResponse::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix)
{
    if(multipart->hasContent("code"))
    {
        setCode(ModelBase::int32_tFromHttpContent(multipart->getContent("code")));
    }
    if(multipart->hasContent("type"))
    {
        setType(ModelBase::stringFromHttpContent(multipart->getContent("type")));
                
    }
    if(multipart->hasContent("message"))
    {
        setMessage(ModelBase::stringFromHttpContent(multipart->getContent("message")));
                
    }
    
}
    
   
int32_t ApiResponse::getCode() const
{
	return m_Code;
}
void ApiResponse::setCode(int32_t value)
{
	m_Code = value;
}
 
bool ApiResponse::CodeIsSet() 
{
    return m_CodeIsSet;
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
 
bool ApiResponse::TypeIsSet() 
{
    return m_TypeIsSet;
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
 
bool ApiResponse::MessageIsSet() 
{
    return m_MessageIsSet;
}
void ApiResponse::unsetMessage() 
{
    m_MessageIsSet = false;
}



}

END_SDK_NS


