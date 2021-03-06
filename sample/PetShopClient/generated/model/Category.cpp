

#include "Category.h"


namespace swagger {

namespace petshop {

namespace model {


Category::Category()
{
    m_Id = 0L;
    m_IdIsSet = false;
    m_Name = U("");
    m_NameIsSet = false;
    
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
    web::json::value val = web::json::value::object();
     
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

void Category::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
	if(namePrefix.size() > 0 && namePrefix[namePrefix.size() - 1] != U('.'))
	{
		namePrefix += U(".");
	}

	if(m_IdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("id"), m_Id));
    }
    if(m_NameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("name"), m_Name));
                
    }
    
}

void Category::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
	if(namePrefix.size() > 0 && namePrefix[namePrefix.size() - 1] != U('.'))
	{
		namePrefix += U(".");
	}

    if(multipart->hasContent(U("id")))
    {
        setId(ModelBase::int64_tFromHttpContent(multipart->getContent(U("id"))));
    }
    if(multipart->hasContent(U("name")))
    {
        setName(ModelBase::stringFromHttpContent(multipart->getContent(U("name"))));
                
    }
    
}
    
   
int64_t Category::getId() const
{
	return m_Id;
}
void Category::setId(int64_t value)
{
	m_Id = value;
    m_IdIsSet = true;
}
 
bool Category::idIsSet() const
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
    m_NameIsSet = true;
}
 
bool Category::nameIsSet() const
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



