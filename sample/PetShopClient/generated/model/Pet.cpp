

#include "Pet.h"


namespace swagger {

namespace petshop {

namespace model {


Pet::Pet()
{
    m_Id = 0L;
    m_IdIsSet = false;
    m_CategoryIsSet = false;
    m_Name = U("");
    m_TagsIsSet = false;
    m_Status = U("");
    m_StatusIsSet = false;
    
}

Pet::~Pet()
{
}

void Pet::validate() 
{
    // TODO: implement validation
}

web::json::value Pet::toJson() const
{
    web::json::value val = web::json::value::object();
     
	if(m_IdIsSet)
    {
        val[U("id")] = ModelBase::toJson(m_Id);
    }
    if(m_CategoryIsSet)
    {
        val[U("category")] = ModelBase::toJson(m_Category);
    }
    val[U("name")] = ModelBase::toJson(m_Name);
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_PhotoUrls )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        val[U("photoUrls")] = web::json::value::array(jsonArray);
        
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Tags )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0) 
        {
            val[U("tags")] = web::json::value::array(jsonArray);
        }
        
    }
    if(m_StatusIsSet)
    {
        val[U("status")] = ModelBase::toJson(m_Status);
    }
    

    return val;
}

void Pet::fromJson(web::json::value& val)
{
    if(val.has_field(U("id")))
    {
        setId(ModelBase::int64_tFromJson(val[U("id")]));
    }
    if(val.has_field(U("category")))
    {
        if(!val[U("category")].is_null()) 
        {
            std::shared_ptr<Category> newItem(new Category());
            newItem->fromJson(val[U("category")]);
            setCategory( newItem );
        }
                
    }
    setName(ModelBase::stringFromJson(val[U("name")]));
    {
        m_PhotoUrls.clear();
        std::vector<web::json::value> jsonArray;
        
        for( auto& item : val[U("photoUrls")].as_array() )
        {
            m_PhotoUrls.push_back(ModelBase::stringFromJson(item));
            
        }
        
    }
    {
        m_Tags.clear();
        std::vector<web::json::value> jsonArray;
        if(val.has_field(U("tags")))
        {
        
        for( auto& item : val[U("tags")].as_array() )
        {
            
            if(item.is_null()) 
            {
                m_Tags.push_back( std::shared_ptr<Tag>(nullptr) );
            }
            else
            {
                std::shared_ptr<Tag> newItem(new Tag());
                newItem->fromJson(item);
                m_Tags.push_back( newItem );
            }
            
        }
         
        }
        
    }
    if(val.has_field(U("status")))
    {
        setStatus(ModelBase::stringFromJson(val[U("status")]));
                
    }
    
}

void Pet::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_CategoryIsSet)
    {
        if (m_Category.get())
        {
            m_Category->toMultipart(multipart, U("category."));
        }
                
    }
    multipart->add(ModelBase::toHttpContent(namePrefix + U("name"), m_Name));
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_PhotoUrls )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        multipart->add(ModelBase::toHttpContent(namePrefix + U("photoUrls"), web::json::value::array(jsonArray), U("application/json")));
        
    }
    {
        std::vector<web::json::value> jsonArray;
        for( auto& item : m_Tags )
        {
            jsonArray.push_back(ModelBase::toJson(item));
        }
        
        if(jsonArray.size() > 0) 
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + U("tags"), web::json::value::array(jsonArray), U("application/json")));
        }
        
    }
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("status"), m_Status));
                
    }
    
}

void Pet::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(U("category")))
    {
        if(multipart->hasContent(U("category")))
        {
            std::shared_ptr<Category> newItem(new Category());
            newItem->fromMultiPart(multipart, U("category."));
            setCategory( newItem );
        }
                
    }
    setName(ModelBase::stringFromHttpContent(multipart->getContent(U("name"))));
    {
        m_PhotoUrls.clear();
        
        
        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(U("photoUrls"))));
        for( auto& item : jsonArray.as_array() )
        {
            m_PhotoUrls.push_back(ModelBase::stringFromJson(item));
            
        }
        
    }
    {
        m_Tags.clear();
        if(multipart->hasContent(U("tags")))
        {            
        
        
        web::json::value jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(U("tags"))));
        for( auto& item : jsonArray.as_array() )
        {
            
            if(item.is_null()) 
            {
                m_Tags.push_back( std::shared_ptr<Tag>(nullptr) );
            }
            else
            {
                std::shared_ptr<Tag> newItem(new Tag());
                newItem->fromJson(item);
                m_Tags.push_back( newItem );
            }
            
        }
         
        }
        
    }
    if(multipart->hasContent(U("status")))
    {
        setStatus(ModelBase::stringFromHttpContent(multipart->getContent(U("status"))));
                
    }
    
}
    
   
int64_t Pet::getId() const
{
	return m_Id;
}
void Pet::setId(int64_t value)
{
	m_Id = value;
    m_IdIsSet = true;
}
 
bool Pet::idIsSet() const
{
    return m_IdIsSet;
}
void Pet::unsetId() 
{
    m_IdIsSet = false;
}

std::shared_ptr<Category> Pet::getCategory() const
{
	return m_Category;
}
void Pet::setCategory(std::shared_ptr<Category> value)
{
	m_Category = value;
    m_CategoryIsSet = true;
}
 
bool Pet::categoryIsSet() const
{
    return m_CategoryIsSet;
}
void Pet::unsetCategory() 
{
    m_CategoryIsSet = false;
}

utility::string_t Pet::getName() const
{
	return m_Name;
}
void Pet::setName(utility::string_t value)
{
	m_Name = value;
    
}
 

std::vector<utility::string_t>& Pet::getPhotoUrls()
{
	return m_PhotoUrls;
}
 

std::vector<std::shared_ptr<Tag>>& Pet::getTags()
{
	return m_Tags;
}
 
bool Pet::tagsIsSet() const
{
    return m_TagsIsSet;
}
void Pet::unsetTags() 
{
    m_TagsIsSet = false;
}

utility::string_t Pet::getStatus() const
{
	return m_Status;
}
void Pet::setStatus(utility::string_t value)
{
	m_Status = value;
    m_StatusIsSet = true;
}
 
bool Pet::statusIsSet() const
{
    return m_StatusIsSet;
}
void Pet::unsetStatus() 
{
    m_StatusIsSet = false;
}




}

}

}



