/*
 * ApiResponse.h
 * 
 * 
 */

#ifndef ApiResponse_H_
#define ApiResponse_H_

#include "Commons.h"
#include "ModelBase.h"

#include <cpprest/details/basic_types.h>


BEGIN_SDK_NS

namespace model {

class SDK_DECLSPEC ApiResponse
	: public ModelBase
{
public:
    ApiResponse();
    virtual ~ApiResponse();

	/////////////////////////////////////////////
	/// ModelBase overrides
	
    virtual void validate() override;

    virtual web::json::value toJson() const override;
    virtual void fromJson(web::json::value& json) override;

    virtual void toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const override;
    virtual void fromMultiPart(web::json::value& val, const std::string& namePrefix) override;
    
 	/////////////////////////////////////////////
	/// ApiResponse members
	   
    
    /*
     * 
     */ 
    int32_t getCode() const;
    void setCode(int32_t value);
    void unsetCode();
    
    
    /*
     * 
     */ 
    utility::string_t getType() const;
    void setType(utility::string_t value);
    void unsetType();
    
    
    /*
     * 
     */ 
    utility::string_t getMessage() const;
    void setMessage(utility::string_t value);
    void unsetMessage();
    
    
    
protected:
    int32_t m_Code;
    bool m_CodeIsSet;
    
    utility::string_t m_Type;
    bool m_TypeIsSet;
    
    utility::string_t m_Message;
    bool m_MessageIsSet;
    
    
};

}

END_SDK_NS

#endif /* ApiResponse_H_ */

