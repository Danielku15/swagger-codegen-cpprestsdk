

#include "PetApi.h"

BEGIN_SDK_NS

namespace api {

PetApi::PetApi()
{
}

PetApi::~PetApi()
{
}


void PetApi::addPet(std::shared_ptr<Pet> body)
{
    auto task = addPetAsync(body);
    
    task.wait();
    
}

void PetApi::deletePet(int64_t petId, utility::string_t apiKey)
{
    auto task = deletePetAsync(petId, apiKey);
    
    task.wait();
    
}

std::vector<std::shared_ptr<Pet>> PetApi::findPetsByStatus(std::vector<utility::string_t> status)
{
    auto task = findPetsByStatusAsync(status);
    
    return task.get();
    
}

std::vector<std::shared_ptr<Pet>> PetApi::findPetsByTags(std::vector<utility::string_t> tags)
{
    auto task = findPetsByTagsAsync(tags);
    
    return task.get();
    
}

std::shared_ptr<Pet> PetApi::getPetById(int64_t petId)
{
    auto task = getPetByIdAsync(petId);
    
    return task.get();
    
}

void PetApi::updatePet(std::shared_ptr<Pet> body)
{
    auto task = updatePetAsync(body);
    
    task.wait();
    
}

void PetApi::updatePetWithForm(int64_t petId, utility::string_t name, utility::string_t status)
{
    auto task = updatePetWithFormAsync(petId, name, status);
    
    task.wait();
    
}

std::shared_ptr<ApiResponse> PetApi::uploadFile(int64_t petId, utility::string_t additionalMetadata, std::shared_ptr<HttpContent> file)
{
    auto task = uploadFileAsync(petId, additionalMetadata, file);
    
    return task.get();
    
}



pplx::task<void> PetApi::addPetAsync(std::shared_ptr<Pet> body)
{
    return pplx::task<void> ();
}

pplx::task<void> PetApi::deletePetAsync(int64_t petId, utility::string_t apiKey)
{
    return pplx::task<void> ();
}

pplx::task<std::vector<std::shared_ptr<Pet>>> PetApi::findPetsByStatusAsync(std::vector<utility::string_t> status)
{
    return pplx::task<std::vector<std::shared_ptr<Pet>>> ();
}

pplx::task<std::vector<std::shared_ptr<Pet>>> PetApi::findPetsByTagsAsync(std::vector<utility::string_t> tags)
{
    return pplx::task<std::vector<std::shared_ptr<Pet>>> ();
}

pplx::task<std::shared_ptr<Pet>> PetApi::getPetByIdAsync(int64_t petId)
{
    return pplx::task<std::shared_ptr<Pet>> ();
}

pplx::task<void> PetApi::updatePetAsync(std::shared_ptr<Pet> body)
{
    return pplx::task<void> ();
}

pplx::task<void> PetApi::updatePetWithFormAsync(int64_t petId, utility::string_t name, utility::string_t status)
{
    return pplx::task<void> ();
}

pplx::task<std::shared_ptr<ApiResponse>> PetApi::uploadFileAsync(int64_t petId, utility::string_t additionalMetadata, std::shared_ptr<HttpContent> file)
{
    return pplx::task<std::shared_ptr<ApiResponse>> ();
}



}

END_SDK_NS


