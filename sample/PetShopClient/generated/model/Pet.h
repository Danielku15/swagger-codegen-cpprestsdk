/*
 * Pet.h
 * 
 * 
 */

#ifndef Pet_H_
#define Pet_H_

#include "Commons.h"
#include "ModelBase.h"

#include "Tag.h"
#include <cpprest/details/basic_types.h>
#include "Category.h"
#include <vector>



namespace swagger {

namespace petshop {

namespace model {


/// <summary>
/// 
/// </summary>
class PETSHOP_DECLSPEC Pet
	: public ModelBase
{
public:
    Pet();
    virtual ~Pet();

	/////////////////////////////////////////////
	/// ModelBase overrides
	
    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;
    
 	/////////////////////////////////////////////
	/// Pet members
	   
    
    /// <summary>
    /// 
    /// </summary>
    int64_t getId() const;
    void setId(int64_t value);
    bool idIsSet() const;
    void unsetId();
    
    
    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<Category> getCategory() const;
    void setCategory(std::shared_ptr<Category> value);
    bool categoryIsSet() const;
    void unsetCategory();
    
    
    /// <summary>
    /// 
    /// </summary>
    utility::string_t getName() const;
    void setName(utility::string_t value);
    
    
    /// <summary>
    /// 
    /// </summary>
    std::vector<utility::string_t>& getPhotoUrls();
    
    
    /// <summary>
    /// 
    /// </summary>
    std::vector<std::shared_ptr<Tag>>& getTags();
    bool tagsIsSet() const;
    void unsetTags();
    
    
    /// <summary>
    /// pet status in the store
    /// </summary>
    utility::string_t getStatus() const;
    void setStatus(utility::string_t value);
    bool statusIsSet() const;
    void unsetStatus();
    
    
    
protected:
    int64_t m_Id;
    bool m_IdIsSet;
    
    std::shared_ptr<Category> m_Category;
    bool m_CategoryIsSet;
    
    utility::string_t m_Name;
    
    std::vector<utility::string_t> m_PhotoUrls;
    
    std::vector<std::shared_ptr<Tag>> m_Tags;
    bool m_TagsIsSet;
    
    utility::string_t m_Status;
    bool m_StatusIsSet;
    
    
};


}

}

}


#endif /* Pet_H_ */

