/*
 * Category.h
 * 
 * 
 */

#ifndef Category_H_
#define Category_H_

#include "Commons.h"
#include "ModelBase.h"

#include <cpprest/details/basic_types.h>


BEGIN_SDK_NS

namespace model {

/// <summary>
/// 
/// </summary>
class SDK_DECLSPEC Category
	: public ModelBase
{
public:
    Category();
    virtual ~Category();

	/////////////////////////////////////////////
	/// ModelBase overrides
	
    virtual void validate() override;

    virtual web::json::value toJson() const override;
    virtual void fromJson(web::json::value& json) override;

    virtual void toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const override;
    virtual void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) override;
    
 	/////////////////////////////////////////////
	/// Category members
	   
    
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

END_SDK_NS

#endif /* Category_H_ */

