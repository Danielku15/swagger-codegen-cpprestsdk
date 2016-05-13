

#include "User.h"


namespace swagger {

namespace petshop {

namespace model {


User::User()
{
}

User::~User()
{
}

void User::validate() 
{
    // TODO: implement validation
}

web::json::value User::toJson() const
{
    web::json::value val;
     
	if(m_IdIsSet)
    {
        val[U("id")] = ModelBase::toJson(m_Id);
    }
    if(m_UsernameIsSet)
    {
        val[U("username")] = ModelBase::toJson(m_Username);
    }
    if(m_FirstNameIsSet)
    {
        val[U("firstName")] = ModelBase::toJson(m_FirstName);
    }
    if(m_LastNameIsSet)
    {
        val[U("lastName")] = ModelBase::toJson(m_LastName);
    }
    if(m_EmailIsSet)
    {
        val[U("email")] = ModelBase::toJson(m_Email);
    }
    if(m_PasswordIsSet)
    {
        val[U("password")] = ModelBase::toJson(m_Password);
    }
    if(m_PhoneIsSet)
    {
        val[U("phone")] = ModelBase::toJson(m_Phone);
    }
    if(m_UserStatusIsSet)
    {
        val[U("userStatus")] = ModelBase::toJson(m_UserStatus);
    }
    

    return val;
}

void User::fromJson(web::json::value& val)
{
    if(val.has_field(U("id")))
    {
        setId(ModelBase::int64_tFromJson(val[U("id")]));
    }
    if(val.has_field(U("username")))
    {
        setUsername(ModelBase::stringFromJson(val[U("username")]));
                
    }
    if(val.has_field(U("firstName")))
    {
        setFirstName(ModelBase::stringFromJson(val[U("firstName")]));
                
    }
    if(val.has_field(U("lastName")))
    {
        setLastName(ModelBase::stringFromJson(val[U("lastName")]));
                
    }
    if(val.has_field(U("email")))
    {
        setEmail(ModelBase::stringFromJson(val[U("email")]));
                
    }
    if(val.has_field(U("password")))
    {
        setPassword(ModelBase::stringFromJson(val[U("password")]));
                
    }
    if(val.has_field(U("phone")))
    {
        setPhone(ModelBase::stringFromJson(val[U("phone")]));
                
    }
    if(val.has_field(U("userStatus")))
    {
        setUserStatus(ModelBase::int32_tFromJson(val[U("userStatus")]));
    }
    
}

void User::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const
{
	if(m_IdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("id"), m_Id));
    }
    if(m_UsernameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("username"), m_Username));
                
    }
    if(m_FirstNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("firstName"), m_FirstName));
                
    }
    if(m_LastNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("lastName"), m_LastName));
                
    }
    if(m_EmailIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("email"), m_Email));
                
    }
    if(m_PasswordIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("password"), m_Password));
                
    }
    if(m_PhoneIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("phone"), m_Phone));
                
    }
    if(m_UserStatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("userStatus"), m_UserStatus));
    }
    
}

void User::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix)
{
    if(multipart->hasContent(U("id")))
    {
        setId(ModelBase::int64_tFromHttpContent(multipart->getContent(U("id"))));
    }
    if(multipart->hasContent(U("username")))
    {
        setUsername(ModelBase::stringFromHttpContent(multipart->getContent(U("username"))));
                
    }
    if(multipart->hasContent(U("firstName")))
    {
        setFirstName(ModelBase::stringFromHttpContent(multipart->getContent(U("firstName"))));
                
    }
    if(multipart->hasContent(U("lastName")))
    {
        setLastName(ModelBase::stringFromHttpContent(multipart->getContent(U("lastName"))));
                
    }
    if(multipart->hasContent(U("email")))
    {
        setEmail(ModelBase::stringFromHttpContent(multipart->getContent(U("email"))));
                
    }
    if(multipart->hasContent(U("password")))
    {
        setPassword(ModelBase::stringFromHttpContent(multipart->getContent(U("password"))));
                
    }
    if(multipart->hasContent(U("phone")))
    {
        setPhone(ModelBase::stringFromHttpContent(multipart->getContent(U("phone"))));
                
    }
    if(multipart->hasContent(U("userStatus")))
    {
        setUserStatus(ModelBase::int32_tFromHttpContent(multipart->getContent(U("userStatus"))));
    }
    
}
    
   
int64_t User::getId() const
{
	return m_Id;
}
void User::setId(int64_t value)
{
	m_Id = value;
}
 
bool User::IdIsSet() 
{
    return m_IdIsSet;
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
 
bool User::UsernameIsSet() 
{
    return m_UsernameIsSet;
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
 
bool User::FirstNameIsSet() 
{
    return m_FirstNameIsSet;
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
 
bool User::LastNameIsSet() 
{
    return m_LastNameIsSet;
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
 
bool User::EmailIsSet() 
{
    return m_EmailIsSet;
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
 
bool User::PasswordIsSet() 
{
    return m_PasswordIsSet;
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
 
bool User::PhoneIsSet() 
{
    return m_PhoneIsSet;
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
 
bool User::UserStatusIsSet() 
{
    return m_UserStatusIsSet;
}
void User::unsetUserStatus() 
{
    m_UserStatusIsSet = false;
}




}

}

}



