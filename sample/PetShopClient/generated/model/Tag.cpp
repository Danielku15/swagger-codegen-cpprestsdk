

#include "Tag.h"


namespace swagger {

namespace petshop {

namespace model {


Tag::Tag()
{
}

Tag::~Tag()
{
}

void Tag::validate() 
{
    // TODO: implement validation
}

web::json::value Tag::toJson() const
{
    web::json::value val;
     
	if(m_IdIsSet)
    {
        val[U("id")] = ModelBase::toJson(m_Id);
    }
    if(m_NameIsSet)
    {
        val[U("name")] = ModelBase::toJson(m_Name);
    }
    

    return val;
}

void Tag::fromJson(web::json::value& val)
{
    if(val.has_field(U("id")))
    {
        setId(ModelBase::int64_tFromJson(val[U("id")]));
    }
    if(val.has_field(U("name")))
    {
        setName(ModelBase::stringFromJson(val[U("name")]));
                
    }
    
}

void Tag::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const
{
	if(m_IdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("id"), m_Id));
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("name"), m_Name));
                
    }
    
}

void Tag::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix)
{
    if(multipart->hasContent(U("id")))
    {
        setId(ModelBase::int64_tFromHttpContent(multipart->getContent(U("id"))));
    }
    if(multipart->hasContent(U("name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(U("name"))));
                
    }
    
}
    
   
int64_t Tag::getId() const
{
	return m_Id;
}
void Tag::setId(int64_t value)
{
	m_Id = value;
}
 
bool Tag::IdIsSet() 
{
    return m_IdIsSet;
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
 
bool Tag::NameIsSet() 
{
    return m_NameIsSet;
}
void Tag::unsetName() 
{
    m_NameIsSet = false;
}




}

}

}



