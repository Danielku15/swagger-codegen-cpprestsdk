/*
 * PetApi.h
 * 
 * 
 */
 
#ifndef PetApi_H_
#define PetApi_H_

#include "Commons.h"
#include "ApiBase.h"

#include "Pet.h"
#include <cpprest/details/basic_types.h>
#include "ApiResponse.h"
#include "HttpContent.h"


BEGIN_SDK_NS

namespace api {

USE_SDK_NS(model)

class SDK_DECLSPEC PetApi
	: public ApiBase
{
public:
    PetApi( std::shared_ptr<ApiConfiguration> configuration );
    virtual ~PetApi();
    
    /// <summary>
    /// Add a new pet to the store
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="body">Pet object that needs to be added to the store</param>
    pplx::task<void> addPet(std::shared_ptr<Pet> body);
    
    /// <summary>
    /// Deletes a pet
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="petId">Pet id to delete</param>/// <param name="apiKey"> (optional)</param>
    pplx::task<void> deletePet(int64_t petId, utility::string_t apiKey);
    
    /// <summary>
    /// Finds Pets by status
    /// </summary>
    /// <remarks>
    /// Multiple status values can be provided with comma separated strings
    /// </remarks>
    /// <param name="status">Status values that need to be considered for filter</param>
    pplx::task<std::vector<std::shared_ptr<Pet>>> findPetsByStatus(std::vector<utility::string_t> status);
    
    /// <summary>
    /// Finds Pets by tags
    /// </summary>
    /// <remarks>
    /// Muliple tags can be provided with comma separated strings. Use tag1, tag2, tag3 for testing.
    /// </remarks>
    /// <param name="tags">Tags to filter by</param>
    pplx::task<std::vector<std::shared_ptr<Pet>>> findPetsByTags(std::vector<utility::string_t> tags);
    
    /// <summary>
    /// Find pet by ID
    /// </summary>
    /// <remarks>
    /// Returns a single pet
    /// </remarks>
    /// <param name="petId">ID of pet to return</param>
    pplx::task<std::shared_ptr<Pet>> getPetById(int64_t petId);
    
    /// <summary>
    /// Update an existing pet
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="body">Pet object that needs to be added to the store</param>
    pplx::task<void> updatePet(std::shared_ptr<Pet> body);
    
    /// <summary>
    /// Updates a pet in the store with form data
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="petId">ID of pet that needs to be updated</param>/// <param name="name">Updated name of the pet (optional)</param>/// <param name="status">Updated status of the pet (optional)</param>
    pplx::task<void> updatePetWithForm(int64_t petId, utility::string_t name, utility::string_t status);
    
    /// <summary>
    /// uploads an image
    /// </summary>
    /// <remarks>
    /// 
    /// </remarks>
    /// <param name="petId">ID of pet to update</param>/// <param name="additionalMetadata">Additional data to pass to server (optional)</param>/// <param name="file">file to upload (optional)</param>
    pplx::task<std::shared_ptr<ApiResponse>> uploadFile(int64_t petId, utility::string_t additionalMetadata, std::shared_ptr<HttpContent> file);
    
};
    
}

END_SDK_NS

#endif /* PetApi_H_ */


