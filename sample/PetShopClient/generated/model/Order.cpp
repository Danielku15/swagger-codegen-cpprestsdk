

#include "Order.h"


namespace swagger {

namespace petshop {

namespace model {


Order::Order()
{
}

Order::~Order()
{
}

void Order::validate() 
{
    // TODO: implement validation
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

void Order::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const
{
	if(m_IdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("id"), m_Id));
    }
    if(m_PetIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("petId"), m_PetId));
    }
    if(m_QuantityIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("quantity"), m_Quantity));
    }
    if(m_ShipDateIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("shipDate"), m_ShipDate));
                
    }
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("status"), m_Status));
                
    }
    if(m_CompleteIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + U("complete"), m_Complete));
    }
    
}

void Order::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix)
{
    if(multipart->hasContent(U("id")))
    {
        setId(ModelBase::int64_tFromHttpContent(multipart->getContent(U("id"))));
    }
    if(multipart->hasContent(U("petId")))
    {
        setPetId(ModelBase::int64_tFromHttpContent(multipart->getContent(U("petId"))));
    }
    if(multipart->hasContent(U("quantity")))
    {
        setQuantity(ModelBase::int32_tFromHttpContent(multipart->getContent(U("quantity"))));
    }
    if(multipart->hasContent(U("shipDate")))
    {
        setShipDate(ModelBase::dateFromHttpContent(multipart->getContent(U("shipDate"))));
                
    }
    if(multipart->hasContent(U("status")))
    {
        setStatus(ModelBase::stringFromHttpContent(multipart->getContent(U("status"))));
                
    }
    if(multipart->hasContent(U("complete")))
    {
        setComplete(ModelBase::boolFromHttpContent(multipart->getContent(U("complete"))));
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

}

}



