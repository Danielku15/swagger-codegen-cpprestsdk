

#include "Category.h"

BEGIN_SDK_NS

namespace model {

Category::Category()
{
}

Category::~Category()
{
}

void Category::validate() 
{
}

web::json::value Category::toJson() const
{
     web::json::value val;
     
	
    
	
    
	

    return val;
}

void Category::fromJson(web::json::value& json)
{
	
}

void Category::toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const
{
}

void Category::fromMultiPart(web::json::value& val, const std::string& namePrefix)
{
}
    
   
int64_t Category::getId() const
{
	return m_Id;
}
void Category::setId(int64_t value)
{
	m_Id = value;
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
 
void Category::unsetName() 
{
    m_NameIsSet = false;
}



}

END_SDK_NS


