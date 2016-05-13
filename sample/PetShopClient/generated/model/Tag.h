/*
 * Tag.h
 * 
 * 
 */

#ifndef Tag_H_
#define Tag_H_

#include "Commons.h"
#include "ModelBase.h"

#include <cpprest/details/basic_types.h>



namespace swagger {

namespace petshop {

namespace model {


/// <summary>
/// 
/// </summary>
class PETSHOP_DECLSPEC Tag
	: public ModelBase
{
public:
    Tag();
    virtual ~Tag();

	/////////////////////////////////////////////
	/// ModelBase overrides
	
    virtual void validate() override;

    virtual web::json::value toJson() const override;
    virtual void fromJson(web::json::value& json) override;

    virtual void toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const override;
    virtual void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) override;
    
 	/////////////////////////////////////////////
	/// Tag members
	   
    
    /// <summary>
    /// 
    /// </summary>
    int64_t getId() const;
    void setId(int64_t value);
    bool IdIsSet();
    void unsetId();
    
    
    /// <summary>
    /// 
    /// </summary>
    utility::string_t getName() const;
    void setName(utility::string_t value);
    bool NameIsSet();
    void unsetName();
    
    
    
protected:
    int64_t m_Id;
    bool m_IdIsSet;
    
    utility::string_t m_Name;
    bool m_NameIsSet;
    
    
};


}

}

}


#endif /* Tag_H_ */

