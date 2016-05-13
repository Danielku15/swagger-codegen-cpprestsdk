

#include "Category.h"


namespace swagger {

namespace petshop {

namespace model {


Category::Category()
{
}

Category::~Category()
{
}

void Category::validate() 
{
    // TODO: implement validation
}

web::json::value Category::toJson() const
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

void Category::fromJson(web::json::value& val)
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

void Category::toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const
{
	if(m_IdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "id", m_Id));
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "name", m_Name));
                
    }
    
}

void Category::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix)
{
    if(multipart->hasContent("id"))
    {
        setId(ModelBase::int64_tFromHttpContent(multipart->getContent("id")));
    }
    if(multipart->hasContent("name"))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent("name")));
                
    }
    
}
    
   
int64_t Category::getId() const
{
	return m_Id;
}
void Category::setId(int64_t value)
{
	m_Id = value;
}
 
bool Category::IdIsSet() 
{
    return m_IdIsSet;
}
void Category::unsetId() 
{
    m_IdIsSet = false;
}

utility::string_t Category::getName() const
{
	return m_Name;
}
void Category::setName(utility::string_t value)
{
	m_Name = value;
}
 
bool Category::NameIsSet() 
{
    return m_NameIsSet;
}
void Category::unsetName() 
{
    m_NameIsSet = false;
}




}

}

}



