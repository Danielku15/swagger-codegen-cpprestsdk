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


BEGIN_SDK_NS

namespace model {

class SDK_DECLSPEC Pet
	: public ModelBase
{
public:
    Pet();
    virtual ~Pet();

	/////////////////////////////////////////////
	/// ModelBase overrides
	
    virtual void validate() override;

    virtual web::json::value toJson() const override;
    virtual void fromJson(web::json::value& json) override;

    virtual void toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const override;
    virtual void fromMultiPart(web::json::value& val, const std::string& namePrefix) override;
    
 	/////////////////////////////////////////////
	/// Pet members
	   
    
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
    std::shared_ptr<Category> getCategory() const;
    void setCategory(std::shared_ptr<Category> value);
    bool CategoryIsSet();
    void unsetCategory();
    
    
    /*
     * 
     */ 
    utility::string_t getName() const;
    void setName(utility::string_t value);
    
    
    /*
     * 
     */ 
    std::vector<utility::string_t>& getPhotoUrls();
    
    
    /*
     * 
     */ 
    std::vector<std::shared_ptr<Tag>>& getTags();
    bool TagsIsSet();
    void unsetTags();
    
    
    /*
     * pet status in the store
     */ 
    utility::string_t getStatus() const;
    void setStatus(utility::string_t value);
    bool StatusIsSet();
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

END_SDK_NS

#endif /* Pet_H_ */

