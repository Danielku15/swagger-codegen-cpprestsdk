

#include "StoreApi.h"

BEGIN_SDK_NS

namespace api {

StoreApi::StoreApi( std::shared_ptr<ApiConfiguration> configuration )
    : ApiBase(configuration)
{
}

StoreApi::~StoreApi()
{
}


void StoreApi::deleteOrder(int64_t orderId)
{
    auto task = deleteOrderAsync(orderId);
    
    task.wait();
    
}

std::map<utility::string_t, int32_t> StoreApi::getInventory()
{
    auto task = getInventoryAsync();
    
    return task.get();
    
}

std::shared_ptr<Order> StoreApi::getOrderById(int64_t orderId)
{
    auto task = getOrderByIdAsync(orderId);
    
    return task.get();
    
}

std::shared_ptr<Order> StoreApi::placeOrder(std::shared_ptr<Order> body)
{
    auto task = placeOrderAsync(body);
    
    return task.get();
    
}



pplx::task<void> StoreApi::deleteOrderAsync(int64_t orderId)
{
    return pplx::task<void> ();
}

pplx::task<std::map<utility::string_t, int32_t>> StoreApi::getInventoryAsync()
{
    return pplx::task<std::map<utility::string_t, int32_t>> ();
}

pplx::task<std::shared_ptr<Order>> StoreApi::getOrderByIdAsync(int64_t orderId)
{
    return pplx::task<std::shared_ptr<Order>> ();
}

pplx::task<std::shared_ptr<Order>> StoreApi::placeOrderAsync(std::shared_ptr<Order> body)
{
    return pplx::task<std::shared_ptr<Order>> ();
}



}

END_SDK_NS


