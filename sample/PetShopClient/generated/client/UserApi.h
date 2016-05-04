/*
 * UserApi.h
 * 
 * 
 */
 
#ifndef UserApi_H_
#define UserApi_H_

#include "Commons.h"
#include "ApiBase.h"

#include "User.h"
#include <vector>
#include <cpprest/details/basic_types.h>

BEGIN_SDK_NS

namespace api {

USE_SDK_NS(model)

class SDK_DECLSPEC UserApi
	: public ApiBase
{
public:
    UserApi();
    virtual ~UserApi();
    
    /// <summary>
    /// Create user
    /// </summary>
    /// <remarks>
    /// This can only be done by the logged in user.
    /// </remarks>
    /// <param name="body">Created user object</param>
    void createUser(std::shared_ptr<User> body);
    
    /// <summary>
    /// Creates list of users with given input array
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="body">List of user object</param>
    void createUsersWithArrayInput(std::vector<std::shared_ptr<User>> body);
    
    /// <summary>
    /// Creates list of users with given input array
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="body">List of user object</param>
    void createUsersWithListInput(std::vector<std::shared_ptr<User>> body);
    
    /// <summary>
    /// Delete user
    /// </summary>
    /// <remarks>
    /// This can only be done by the logged in user.
    /// </remarks>
    /// <param name="username">The name that needs to be deleted</param>
    void deleteUser(utility::string_t username);
    
    /// <summary>
    /// Get user by user name
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="username">The name that needs to be fetched. Use user1 for testing. </param>
    std::shared_ptr<User> getUserByName(utility::string_t username);
    
    /// <summary>
    /// Logs user into the system
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="username">The user name for login</param>/// <param name="password">The password for login in clear text</param>
    utility::string_t loginUser(utility::string_t username, utility::string_t password);
    
    /// <summary>
    /// Logs out current logged in user session
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    
    void logoutUser();
    
    /// <summary>
    /// Updated user
    /// </summary>
    /// <remarks>
    /// This can only be done by the logged in user.
    /// </remarks>
    /// <param name="username">name that need to be updated</param>/// <param name="body">Updated user object</param>
    void updateUser(utility::string_t username, std::shared_ptr<User> body);
    

    
    /// <summary>
    /// Create user
    /// </summary>
    /// <remarks>
    /// This can only be done by the logged in user.
    /// </remarks>
    /// <param name="body">Created user object</param>
    pplx::task<void> createUserAsync(std::shared_ptr<User> body);
    
    /// <summary>
    /// Creates list of users with given input array
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="body">List of user object</param>
    pplx::task<void> createUsersWithArrayInputAsync(std::vector<std::shared_ptr<User>> body);
    
    /// <summary>
    /// Creates list of users with given input array
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="body">List of user object</param>
    pplx::task<void> createUsersWithListInputAsync(std::vector<std::shared_ptr<User>> body);
    
    /// <summary>
    /// Delete user
    /// </summary>
    /// <remarks>
    /// This can only be done by the logged in user.
    /// </remarks>
    /// <param name="username">The name that needs to be deleted</param>
    pplx::task<void> deleteUserAsync(utility::string_t username);
    
    /// <summary>
    /// Get user by user name
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="username">The name that needs to be fetched. Use user1 for testing. </param>
    pplx::task<std::shared_ptr<User>> getUserByNameAsync(utility::string_t username);
    
    /// <summary>
    /// Logs user into the system
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="username">The user name for login</param>/// <param name="password">The password for login in clear text</param>
    pplx::task<utility::string_t> loginUserAsync(utility::string_t username, utility::string_t password);
    
    /// <summary>
    /// Logs out current logged in user session
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    
    pplx::task<void> logoutUserAsync();
    
    /// <summary>
    /// Updated user
    /// </summary>
    /// <remarks>
    /// This can only be done by the logged in user.
    /// </remarks>
    /// <param name="username">name that need to be updated</param>/// <param name="body">Updated user object</param>
    pplx::task<void> updateUserAsync(utility::string_t username, std::shared_ptr<User> body);
    
};
    
}

END_SDK_NS

#endif /* UserApi_H_ */

