
# This is a sample api mustache template.  It is representing a ficticous 
# language and won't be usable or compile to anything without lots of changes.
# Use it as an example.  You can access the variables in the generator object
# like such:

# use the package from the `apiPackage` variable
package: 

# operations block
classname: PetClient

# loop over each operation in the API:

# each operation has an `operationId`:
operationId: addPet

# and parameters:
body: Pet


# each operation has an `operationId`:
operationId: deletePet

# and parameters:
petId: int64_t
apiKey: utility::string_t


# each operation has an `operationId`:
operationId: findPetsByStatus

# and parameters:
status: std::vector&lt;utility::string_t&gt;


# each operation has an `operationId`:
operationId: findPetsByTags

# and parameters:
tags: std::vector&lt;utility::string_t&gt;


# each operation has an `operationId`:
operationId: getPetById

# and parameters:
petId: int64_t


# each operation has an `operationId`:
operationId: updatePet

# and parameters:
body: Pet


# each operation has an `operationId`:
operationId: updatePetWithForm

# and parameters:
petId: int64_t
name: utility::string_t
status: utility::string_t


# each operation has an `operationId`:
operationId: uploadFile

# and parameters:
petId: int64_t
additionalMetadata: utility::string_t
file: std::shared_ptr&lt;HttpContent&gt;


# end of operations block
