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
		std::cout << std::to_string(pets.size()) << std::endl;
	})
	.wait();
}
BOOST_AUTO_TEST_SUITE_END()
