#include "Tests.h"
#include <model/Pet.h>
#include <ApiClient.h>
#include <api/PetApi.h>

BOOST_AUTO_TEST_SUITE(PetApiTests)

BOOST_AUTO_TEST_CASE(testFindByStatus)
{
	auto config = std::make_shared<swagger::petshop::api::ApiConfiguration>();
	config->setBaseUrl(U("http://petstore.swagger.io/v2"));
		
	auto client = std::make_shared<swagger::petshop::api::ApiClient>(config);

	swagger::petshop::api::PetApi api(client);

	std::vector<utility::string_t> status;
	status.push_back(U("available"));

	api.findPetsByStatus(status)
	.then([](std::vector<std::shared_ptr<swagger::petshop::model::Pet>> pets)
	{
		BOOST_CHECK_GT(pets.size(), 1);
		for( auto& pet : pets)
		{
			std::cout << "[" << pet->getId() << "] ";
			std::wcout << pet->getName() << std::endl;
		}		
	})
	.wait();
}

BOOST_AUTO_TEST_CASE(testGetPetById)
{
	auto config = std::make_shared<swagger::petshop::api::ApiConfiguration>();
	config->setBaseUrl(U("http://petstore.swagger.io/v2"));
		
	auto client = std::make_shared<swagger::petshop::api::ApiClient>(config);

	swagger::petshop::api::PetApi api(client);

	std::vector<utility::string_t> status;
	status.push_back(U("available"));

	api.getPetById(504799)
	.then([](std::shared_ptr<swagger::petshop::model::Pet> pet)
	{
		std::cout << "[" << pet->getId() << "] ";
		std::wcout << pet->getName() << std::endl;
	})
	.wait();
}
BOOST_AUTO_TEST_SUITE_END()
