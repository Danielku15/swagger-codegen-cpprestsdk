

#include "User.h"

BEGIN_SDK_NS

namespace model {

User::User()
{
}

User::~User()
{
}

void User::validate() 
{
}

web::json::value User::toJson() const
{
     web::json::value val;
     
	
    
	
    
	
    
	
    
	
    
	
    
	
    
	
    
	

    return val;
}

void User::fromJson(web::json::value& json)
{
	
}

void User::toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const
{
}

void User::fromMultiPart(web::json::value& val, const std::string& namePrefix)
{
}
    
   
int64_t User::getId() const
{
	return m_Id;
}
void User::setId(int64_t value)
{
	m_Id = value;
}
 
void User::unsetId() 
{
    m_IdIsSet = false;
}

utility::string_t User::getUsername() const
{
	return m_Username;
}
void User::setUsername(utility::string_t value)
{
	m_Username = value;
}
 
void User::unsetUsername() 
{
    m_UsernameIsSet = false;
}

utility::string_t User::getFirstName() const
{
	return m_FirstName;
}
void User::setFirstName(utility::string_t value)
{
	m_FirstName = value;
}
 
void User::unsetFirstName() 
{
    m_FirstNameIsSet = false;
}

utility::string_t User::getLastName() const
{
	return m_LastName;
}
void User::setLastName(utility::string_t value)
{
	m_LastName = value;
}
 
void User::unsetLastName() 
{
    m_LastNameIsSet = false;
}

utility::string_t User::getEmail() const
{
	return m_Email;
}
void User::setEmail(utility::string_t value)
{
	m_Email = value;
}
 
void User::unsetEmail() 
{
    m_EmailIsSet = false;
}

utility::string_t User::getPassword() const
{
	return m_Password;
}
void User::setPassword(utility::string_t value)
{
	m_Password = value;
}
 
void User::unsetPassword() 
{
    m_PasswordIsSet = false;
}

utility::string_t User::getPhone() const
{
	return m_Phone;
}
void User::setPhone(utility::string_t value)
{
	m_Phone = value;
}
 
void User::unsetPhone() 
{
    m_PhoneIsSet = false;
}

int32_t User::getUserStatus() const
{
	return m_UserStatus;
}
void User::setUserStatus(int32_t value)
{
	m_UserStatus = value;
}
 
void User::unsetUserStatus() 
{
    m_UserStatusIsSet = false;
}



}

END_SDK_NS


