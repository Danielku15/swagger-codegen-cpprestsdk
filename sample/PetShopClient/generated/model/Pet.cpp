

#include "Pet.h"

BEGIN_SDK_NS

namespace model {

Pet::Pet()
{
}

Pet::~Pet()
{
}

void Pet::validate() 
{
}

web::json::value Pet::toJson() const
{
    web::json::value val;
     
	val[U("id")] = ModelBase::toJson(m_Id);
    if(m_CategoryIsSet)
    {
        val[U("category")] = m_Category->toJson();
                
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
            jsonArray.push_back( item.get() ? item->toJson() : web::json::value::null() );
            
        }
        val[U("tags")] = web::json::value::array(jsonArray);
    }
    if(m_StatusIsSet)
    {
        val[U("status")] = ModelBase::toJson(m_Status);
                
    }
    

    return val;
}

void Pet::fromJson(web::json::value& json)
{
	
}

void Pet::toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const
{
}

void Pet::fromMultiPart(web::json::value& val, const std::string& namePrefix)
{
}
    
   
int64_t Pet::getId() const
{
	return m_Id;
}
void Pet::setId(int64_t value)
{
	m_Id = value;
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
}
 
void Pet::unsetStatus() 
{
    m_StatusIsSet = false;
}



}

END_SDK_NS


