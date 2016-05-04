

#include "Tag.h"

BEGIN_SDK_NS

namespace model {

Tag::Tag()
{
}

Tag::~Tag()
{
}

void Tag::validate() 
{
}

web::json::value Tag::toJson() const
{
    web::json::value val;
     
	val[U("id")] = ModelBase::toJson(m_Id);
    if(m_NameIsSet)
    {
        val[U("name")] = ModelBase::toJson(m_Name);
                
    }
    

    return val;
}

void Tag::fromJson(web::json::value& json)
{
	
}

void Tag::toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const
{
}

void Tag::fromMultiPart(web::json::value& val, const std::string& namePrefix)
{
}
    
   
int64_t Tag::getId() const
{
	return m_Id;
}
void Tag::setId(int64_t value)
{
	m_Id = value;
}
 
void Tag::unsetId() 
{
    m_IdIsSet = false;
}

utility::string_t Tag::getName() const
{
	return m_Name;
}
void Tag::setName(utility::string_t value)
{
	m_Name = value;
}
 
void Tag::unsetName() 
{
    m_NameIsSet = false;
}



}

END_SDK_NS


