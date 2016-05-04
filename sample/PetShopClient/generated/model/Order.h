/*
 * Order.h
 * 
 * 
 */

#ifndef Order_H_
#define Order_H_

#include "Commons.h"
#include "ModelBase.h"

#include <cpprest/details/basic_types.h>


BEGIN_SDK_NS

namespace model {

/// <summary>
/// 
/// </summary>
class SDK_DECLSPEC Order
	: public ModelBase
{
public:
    Order();
    virtual ~Order();

	/////////////////////////////////////////////
	/// ModelBase overrides
	
    virtual void validate() override;

    virtual web::json::value toJson() const override;
    virtual void fromJson(web::json::value& json) override;

    virtual void toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const override;
    virtual void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) override;
    
 	/////////////////////////////////////////////
	/// Order members
	   
    
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
    int64_t getPetId() const;
    void setPetId(int64_t value);
    bool PetIdIsSet();
    void unsetPetId();
    
    
    /// <summary>
    /// 
    /// </summary>
    int32_t getQuantity() const;
    void setQuantity(int32_t value);
    bool QuantityIsSet();
    void unsetQuantity();
    
    
    /// <summary>
    /// 
    /// </summary>
    utility::datetime getShipDate() const;
    void setShipDate(utility::datetime value);
    bool ShipDateIsSet();
    void unsetShipDate();
    
    
    /// <summary>
    /// Order Status
    /// </summary>
    utility::string_t getStatus() const;
    void setStatus(utility::string_t value);
    bool StatusIsSet();
    void unsetStatus();
    
    
    /// <summary>
    /// 
    /// </summary>
    bool getComplete() const;
    void setComplete(bool value);
    bool CompleteIsSet();
    void unsetComplete();
    
    
    
protected:
    int64_t m_Id;
    bool m_IdIsSet;
    
    int64_t m_PetId;
    bool m_PetIdIsSet;
    
    int32_t m_Quantity;
    bool m_QuantityIsSet;
    
    utility::datetime m_ShipDate;
    bool m_ShipDateIsSet;
    
    utility::string_t m_Status;
    bool m_StatusIsSet;
    
    bool m_Complete;
    bool m_CompleteIsSet;
    
    
};

}

END_SDK_NS

#endif /* Order_H_ */

