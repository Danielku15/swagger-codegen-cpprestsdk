/*
 * StoreApi.h
 * 
 * 
 */
 
#ifndef StoreApi_H_
#define StoreApi_H_

#include "Commons.h"
#include "ApiClient.h"

#include <map>
#include "Order.h"



namespace swagger {

namespace petshop {

namespace api {


using namespace swagger::petshop::model;

class PETSHOP_DECLSPEC StoreApi
{
public:
    StoreApi( std::shared_ptr<ApiClient> apiClient );
    virtual ~StoreApi();
    
    /// <summary>
    /// Delete purchase order by ID
    /// </summary>
    /// <remarks>
    /// For valid response try integer IDs with positive integer value. Negative or non-integer values will generate API errors
    /// </remarks>
    /// <param name="orderId">ID of the order that needs to be deleted</param>
    pplx::task<void> deleteOrder(int64_t orderId);
    
    /// <summary>
    /// Returns pet inventories by status
    /// </summary>
    /// <remarks>
    /// Returns a map of status codes to quantities
    /// </remarks>
    
    pplx::task<std::map<utility::string_t, int32_t>> getInventory();
    
    /// <summary>
    /// Find purchase order by ID
    /// </summary>
    /// <remarks>
    /// For valid response try integer IDs with value &gt;= 1 and &lt;= 10. Other values will generated exceptions
    /// </remarks>
    /// <param name="orderId">ID of pet that needs to be fetched</param>
    pplx::task<std::shared_ptr<Order>> getOrderById(int64_t orderId);
    
    /// <summary>
    /// Place an order for a pet
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="body">order placed for purchasing the pet</param>
    pplx::task<std::shared_ptr<Order>> placeOrder(std::shared_ptr<Order> body);
    
    
protected:
    std::shared_ptr<ApiClient> m_ApiClient;    
};
    

}

}

}


#endif /* StoreApi_H_ */


