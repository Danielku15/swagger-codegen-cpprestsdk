

#include "Order.h"

BEGIN_SDK_NS

namespace model {

Order::Order()
{
}

Order::~Order()
{
}

void Order::validate() 
{
}

web::json::value Order::toJson() const
{
     web::json::value val;
     
	
    
	
    
	
    
	
    
	
    
	
    
	

    return val;
}

void Order::fromJson(web::json::value& json)
{
	
}

void Order::toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const
{
}

void Order::fromMultiPart(web::json::value& val, const std::string& namePrefix)
{
}
    
   
int64_t Order::getId() const
{
	return m_Id;
}
void Order::setId(int64_t value)
{
	m_Id = value;
}
 
void Order::unsetId() 
{
    m_IdIsSet = false;
}

int64_t Order::getPetId() const
{
	return m_PetId;
}
void Order::setPetId(int64_t value)
{
	m_PetId = value;
}
 
void Order::unsetPetId() 
{
    m_PetIdIsSet = false;
}

int32_t Order::getQuantity() const
{
	return m_Quantity;
}
void Order::setQuantity(int32_t value)
{
	m_Quantity = value;
}
 
void Order::unsetQuantity() 
{
    m_QuantityIsSet = false;
}

utility::datetime Order::getShipDate() const
{
	return m_ShipDate;
}
void Order::setShipDate(utility::datetime value)
{
	m_ShipDate = value;
}
 
void Order::unsetShipDate() 
{
    m_ShipDateIsSet = false;
}

utility::string_t Order::getStatus() const
{
	return m_Status;
}
void Order::setStatus(utility::string_t value)
{
	m_Status = value;
}
 
void Order::unsetStatus() 
{
    m_StatusIsSet = false;
}

bool Order::getComplete() const
{
	return m_Complete;
}
void Order::setComplete(bool value)
{
	m_Complete = value;
}
 
void Order::unsetComplete() 
{
    m_CompleteIsSet = false;
}



}

END_SDK_NS


