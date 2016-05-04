
# This is a sample api mustache template.  It is representing a ficticous 
# language and won't be usable or compile to anything without lots of changes.
# Use it as an example.  You can access the variables in the generator object
# like such:

# use the package from the `apiPackage` variable
package: 

# operations block
classname: UserClient

# loop over each operation in the API:

# each operation has an `operationId`:
operationId: createUser

# and parameters:
body: User


# each operation has an `operationId`:
operationId: createUsersWithArrayInput

# and parameters:
body: std::vector&lt;std::shared_ptr&lt;User&gt;&gt;


# each operation has an `operationId`:
operationId: createUsersWithListInput

# and parameters:
body: std::vector&lt;std::shared_ptr&lt;User&gt;&gt;


# each operation has an `operationId`:
operationId: deleteUser

# and parameters:
username: utility::string_t


# each operation has an `operationId`:
operationId: getUserByName

# and parameters:
username: utility::string_t


# each operation has an `operationId`:
operationId: loginUser

# and parameters:
username: utility::string_t
password: utility::string_t


# each operation has an `operationId`:
operationId: logoutUser

# and parameters:


# each operation has an `operationId`:
operationId: updateUser

# and parameters:
username: utility::string_t
body: User


# end of operations block
