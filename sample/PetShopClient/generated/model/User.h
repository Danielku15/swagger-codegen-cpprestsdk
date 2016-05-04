/*
 * User.h
 * 
 * 
 */

#ifndef User_H_
#define User_H_

#include "Commons.h"
#include "ModelBase.h"

#include <cpprest/details/basic_types.h>


BEGIN_SDK_NS

namespace model {

class SDK_DECLSPEC User
	: public ModelBase
{
public:
    User();
    virtual ~User();

	/////////////////////////////////////////////
	/// ModelBase overrides
	
    virtual void validate() override;

    virtual web::json::value toJson() const override;
    virtual void fromJson(web::json::value& json) override;

    virtual void toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const override;
    virtual void fromMultiPart(web::json::value& val, const std::string& namePrefix) override;
    
 	/////////////////////////////////////////////
	/// User members
	   
    
    /*
     * 
     */ 
    int64_t getId() const;
    void setId(int64_t value);
    bool IdIsSet();
    void unsetId();
    
    
    /*
     * 
     */ 
    utility::string_t getUsername() const;
    void setUsername(utility::string_t value);
    bool UsernameIsSet();
    void unsetUsername();
    
    
    /*
     * 
     */ 
    utility::string_t getFirstName() const;
    void setFirstName(utility::string_t value);
    bool FirstNameIsSet();
    void unsetFirstName();
    
    
    /*
     * 
     */ 
    utility::string_t getLastName() const;
    void setLastName(utility::string_t value);
    bool LastNameIsSet();
    void unsetLastName();
    
    
    /*
     * 
     */ 
    utility::string_t getEmail() const;
    void setEmail(utility::string_t value);
    bool EmailIsSet();
    void unsetEmail();
    
    
    /*
     * 
     */ 
    utility::string_t getPassword() const;
    void setPassword(utility::string_t value);
    bool PasswordIsSet();
    void unsetPassword();
    
    
    /*
     * 
     */ 
    utility::string_t getPhone() const;
    void setPhone(utility::string_t value);
    bool PhoneIsSet();
    void unsetPhone();
    
    
    /*
     * User Status
     */ 
    int32_t getUserStatus() const;
    void setUserStatus(int32_t value);
    bool UserStatusIsSet();
    void unsetUserStatus();
    
    
    
protected:
    int64_t m_Id;
    bool m_IdIsSet;
    
    utility::string_t m_Username;
    bool m_UsernameIsSet;
    
    utility::string_t m_FirstName;
    bool m_FirstNameIsSet;
    
    utility::string_t m_LastName;
    bool m_LastNameIsSet;
    
    utility::string_t m_Email;
    bool m_EmailIsSet;
    
    utility::string_t m_Password;
    bool m_PasswordIsSet;
    
    utility::string_t m_Phone;
    bool m_PhoneIsSet;
    
    int32_t m_UserStatus;
    bool m_UserStatusIsSet;
    
    
};

}

END_SDK_NS

#endif /* User_H_ */

