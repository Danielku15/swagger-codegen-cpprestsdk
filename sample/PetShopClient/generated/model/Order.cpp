

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
     
	if(m_IdIsSet)
    {
        val[U("id")] = ModelBase::toJson(m_Id);
    }
    if(m_PetIdIsSet)
    {
        val[U("petId")] = ModelBase::toJson(m_PetId);
    }
    if(m_QuantityIsSet)
    {
        val[U("quantity")] = ModelBase::toJson(m_Quantity);
    }
    if(m_ShipDateIsSet)
    {
        val[U("shipDate")] = ModelBase::toJson(m_ShipDate);
                
    }
    if(m_StatusIsSet)
    {
        val[U("status")] = ModelBase::toJson(m_Status);
                
    }
    if(m_CompleteIsSet)
    {
        val[U("complete")] = ModelBase::toJson(m_Complete);
    }
    

    return val;
}

void Order::fromJson(web::json::value& val)
{
    if(val.has_field(U("id")))
    {
        setId(ModelBase::int64_tFromJson(val[U("id")]));
    }
    if(val.has_field(U("petId")))
    {
        setPetId(ModelBase::int64_tFromJson(val[U("petId")]));
    }
    if(val.has_field(U("quantity")))
    {
        setQuantity(ModelBase::int32_tFromJson(val[U("quantity")]));
    }
    if(val.has_field(U("shipDate")))
    {
        setShipDate(ModelBase::dateFromJson(val[U("shipDate")]));
                
    }
    if(val.has_field(U("status")))
    {
        setStatus(ModelBase::stringFromJson(val[U("status")]));
                
    }
    if(val.has_field(U("complete")))
    {
        setComplete(ModelBase::boolFromJson(val[U("complete")]));
    }
    
}

void Order::toMultipart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix) const
{
	if(m_IdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "id", m_Id));
    }
    if(m_PetIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "petId", m_PetId));
    }
    if(m_QuantityIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "quantity", m_Quantity));
    }
    if(m_ShipDateIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "shipDate", m_ShipDate));
                
    }
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "status", m_Status));
                
    }
    if(m_CompleteIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + "complete", m_Complete));
    }
    
}

void Order::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const std::string& namePrefix)
{
    if(multipart->hasContent("id"))
    {
        setId(ModelBase::int64_tFromHttpContent(multipart->getContent("id")));
    }
    if(multipart->hasContent("petId"))
    {
        setPetId(ModelBase::int64_tFromHttpContent(multipart->getContent("petId")));
    }
    if(multipart->hasContent("quantity"))
    {
        setQuantity(ModelBase::int32_tFromHttpContent(multipart->getContent("quantity")));
    }
    if(multipart->hasContent("shipDate"))
    {
        setShipDate(ModelBase::dateFromHttpContent(multipart->getContent("shipDate")));
                
    }
    if(multipart->hasContent("status"))
    {
        setStatus(ModelBase::stringFromHttpContent(multipart->getContent("status")));
                
    }
    if(multipart->hasContent("complete"))
    {
        setComplete(ModelBase::boolFromHttpContent(multipart->getContent("complete")));
    }
    
}
    
   
int64_t Order::getId() const
{
	return m_Id;
}
void Order::setId(int64_t value)
{
	m_Id = value;
}
 
bool Order::IdIsSet() 
{
    return m_IdIsSet;
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
 
bool Order::PetIdIsSet() 
{
    return m_PetIdIsSet;
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
 
bool Order::QuantityIsSet() 
{
    return m_QuantityIsSet;
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
 
bool Order::ShipDateIsSet() 
{
    return m_ShipDateIsSet;
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
 
bool Order::StatusIsSet() 
{
    return m_StatusIsSet;
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
 
bool Order::CompleteIsSet() 
{
    return m_CompleteIsSet;
}
void Order::unsetComplete() 
{
    m_CompleteIsSet = false;
}



}

END_SDK_NS


