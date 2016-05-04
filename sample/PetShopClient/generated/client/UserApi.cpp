

#include "UserApi.h"

BEGIN_SDK_NS

namespace api {

UserApi::UserApi( std::shared_ptr<ApiConfiguration> configuration )
    : ApiBase(configuration)
{
}

UserApi::~UserApi()
{
}


void UserApi::createUser(std::shared_ptr<User> body)
{
    auto task = createUserAsync(body);
    
    task.wait();
    
}

void UserApi::createUsersWithArrayInput(std::vector<std::shared_ptr<User>> body)
{
    auto task = createUsersWithArrayInputAsync(body);
    
    task.wait();
    
}

void UserApi::createUsersWithListInput(std::vector<std::shared_ptr<User>> body)
{
    auto task = createUsersWithListInputAsync(body);
    
    task.wait();
    
}

void UserApi::deleteUser(utility::string_t username)
{
    auto task = deleteUserAsync(username);
    
    task.wait();
    
}

std::shared_ptr<User> UserApi::getUserByName(utility::string_t username)
{
    auto task = getUserByNameAsync(username);
    
    return task.get();
    
}

utility::string_t UserApi::loginUser(utility::string_t username, utility::string_t password)
{
    auto task = loginUserAsync(username, password);
    
    return task.get();
    
}

void UserApi::logoutUser()
{
    auto task = logoutUserAsync();
    
    task.wait();
    
}

void UserApi::updateUser(utility::string_t username, std::shared_ptr<User> body)
{
    auto task = updateUserAsync(username, body);
    
    task.wait();
    
}



pplx::task<void> UserApi::createUserAsync(std::shared_ptr<User> body)
{
    return pplx::task<void> ();
}

pplx::task<void> UserApi::createUsersWithArrayInputAsync(std::vector<std::shared_ptr<User>> body)
{
    return pplx::task<void> ();
}

pplx::task<void> UserApi::createUsersWithListInputAsync(std::vector<std::shared_ptr<User>> body)
{
    return pplx::task<void> ();
}

pplx::task<void> UserApi::deleteUserAsync(utility::string_t username)
{
    return pplx::task<void> ();
}

pplx::task<std::shared_ptr<User>> UserApi::getUserByNameAsync(utility::string_t username)
{
    return pplx::task<std::shared_ptr<User>> ();
}

pplx::task<utility::string_t> UserApi::loginUserAsync(utility::string_t username, utility::string_t password)
{
    return pplx::task<utility::string_t> ();
}

pplx::task<void> UserApi::logoutUserAsync()
{
    return pplx::task<void> ();
}

pplx::task<void> UserApi::updateUserAsync(utility::string_t username, std::shared_ptr<User> body)
{
    return pplx::task<void> ();
}



}

END_SDK_NS


