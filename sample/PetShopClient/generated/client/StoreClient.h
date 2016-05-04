
# This is a sample api mustache template.  It is representing a ficticous 
# language and won't be usable or compile to anything without lots of changes.
# Use it as an example.  You can access the variables in the generator object
# like such:

# use the package from the `apiPackage` variable
package: 

# operations block
classname: StoreClient

# loop over each operation in the API:

# each operation has an `operationId`:
operationId: deleteOrder

# and parameters:
orderId: int64_t


# each operation has an `operationId`:
operationId: getInventory

# and parameters:


# each operation has an `operationId`:
operationId: getOrderById

# and parameters:
orderId: int64_t


# each operation has an `operationId`:
operationId: placeOrder

# and parameters:
body: Order


# end of operations block
