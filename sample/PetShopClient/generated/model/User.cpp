

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

void User::toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const
{
	if(m_IdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "id", m_Id));
    }
    if(m_UsernameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "username", m_Username));
                
    }
    if(m_FirstNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "firstName", m_FirstName));
                
    }
    if(m_LastNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "lastName", m_LastName));
                
    }
    if(m_EmailIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "email", m_Email));
                
    }
    if(m_PasswordIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "password", m_Password));
                
    }
    if(m_PhoneIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "phone", m_Phone));
                
    }
    if(m_UserStatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "userStatus", m_UserStatus));
    }
    
}

void User::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix)
{
    if(multipart->hasContent("id"))
    {
        setId(ModelBase::int64_tFromHttpContent(multipart->getContent("id")));
    }
    if(multipart->hasContent("username"))
    {
        setUsername(ModelBase::stringFromHttpContent(multipart->getContent("username")));
                
    }
    if(multipart->hasContent("firstName"))
    {
        setFirstName(ModelBase::stringFromHttpContent(multipart->getContent("firstName")));
                
    }
    if(multipart->hasContent("lastName"))
    {
        setLastName(ModelBase::stringFromHttpContent(multipart->getContent("lastName")));
                
    }
    if(multipart->hasContent("email"))
    {
        setEmail(ModelBase::stringFromHttpContent(multipart->getContent("email")));
                
    }
    if(multipart->hasContent("password"))
    {
        setPassword(ModelBase::stringFromHttpContent(multipart->getContent("password")));
                
    }
    if(multipart->hasContent("phone"))
    {
        setPhone(ModelBase::stringFromHttpContent(multipart->getContent("phone")));
                
    }
    if(multipart->hasContent("userStatus"))
    {
        setUserStatus(ModelBase::int32_tFromHttpContent(multipart->getContent("userStatus")));
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

END_SDK_NS


