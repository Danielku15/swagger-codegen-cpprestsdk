#include "Tests.h"
#include <model/Pet.h>

BOOST_AUTO_TEST_SUITE(PetTests)

BOOST_AUTO_TEST_CASE(testToJsonFull)
{
	swagger::petshop::model::Pet pet;
	pet.setId(1);
	pet.setName(U("Test"));
	pet.getPhotoUrls().push_back(U("url1"));
	pet.getPhotoUrls().push_back(U("url2"));

	{
		auto cat = std::make_shared<swagger::petshop::model::Category>();
		cat->setId(2);
		cat->setName(U("Cat"));
		pet.setCategory(cat);
	}
	{
		auto tag1 = std::make_shared<swagger::petshop::model::Tag>();
		tag1->setId(3);
		tag1->setName(U("Tag1"));

		auto tag2 = std::make_shared<swagger::petshop::model::Tag>();
		tag2->setId(4);
		tag2->setName(U("Tag2"));

		pet.getTags().push_back(tag1);
		pet.getTags().push_back(tag2);
	}

	pet.setStatus(U("available"));

	web::json::value json = pet.toJson();
	auto jsonString = json.serialize();

	std::wcout << jsonString << std::endl;

	BOOST_CHECK_EQUAL(U("{\"category\":{\"id\":2,\"name\":\"Cat\"},\"id\":1,\"name\":\"Test\",\"photoUrls\":[\"url1\",\"url2\"],\"status\":\"available\",\"tags\":[{\"id\":3,\"name\":\"Tag1\"},{\"id\":4,\"name\":\"Tag2\"}]}"), jsonString);
}

BOOST_AUTO_TEST_CASE(testToJsonNoCat)
{
	swagger::petshop::model::Pet pet;
	pet.setId(1);
	pet.setName(U("Test"));
	pet.getPhotoUrls().push_back(U("url1"));
	pet.getPhotoUrls().push_back(U("url2"));

	{
		auto tag1 = std::make_shared<swagger::petshop::model::Tag>();
		tag1->setId(3);
		tag1->setName(U("Tag1"));

		auto tag2 = std::make_shared<swagger::petshop::model::Tag>();
		tag2->setId(4);
		tag2->setName(U("Tag2"));

		pet.getTags().push_back(tag1);
		pet.getTags().push_back(tag2);
	}

	pet.setStatus(U("available"));

	web::json::value json = pet.toJson();
	auto jsonString = json.serialize();

	std::wcout << jsonString << std::endl;

	BOOST_CHECK_EQUAL(U("{\"id\":1,\"name\":\"Test\",\"photoUrls\":[\"url1\",\"url2\"],\"status\":\"available\",\"tags\":[{\"id\":3,\"name\":\"Tag1\"},{\"id\":4,\"name\":\"Tag2\"}]}"), jsonString);
}
BOOST_AUTO_TEST_CASE(testFromJsonFull)
{
	web::json::value json = web::json::value::parse(U("{\"category\":{\"id\":2,\"name\":\"Cat\"},\"id\":1,\"name\":\"Test\",\"photoUrls\":[\"url1\",\"url2\"],\"status\":\"available\",\"tags\":[{\"id\":3,\"name\":\"Tag1\"},{\"id\":4,\"name\":\"Tag2\"}]}"));

	swagger::petshop::model::Pet pet;
	pet.fromJson(json);

	BOOST_CHECK(pet.idIsSet());
	BOOST_CHECK_EQUAL(pet.getId(), 1);
	BOOST_CHECK_EQUAL(pet.getName(), U("Test"));
	BOOST_CHECK_EQUAL(pet.getPhotoUrls().size(), 2);
	BOOST_CHECK_EQUAL(pet.getPhotoUrls()[0], U("url1"));
	BOOST_CHECK_EQUAL(pet.getPhotoUrls()[1], U("url2"));

	BOOST_CHECK(pet.getCategory() != nullptr);
	BOOST_CHECK_EQUAL(pet.getCategory()->getId(), 2);
	BOOST_CHECK_EQUAL(pet.getCategory()->getName(), U("Cat"));

	BOOST_CHECK_EQUAL(pet.getTags().size(), 2);
	BOOST_CHECK_EQUAL(pet.getTags()[0]->getId(), 3);
	BOOST_CHECK_EQUAL(pet.getTags()[0]->getName(), U("Tag1"));
	BOOST_CHECK_EQUAL(pet.getTags()[1]->getId(), 4);
	BOOST_CHECK_EQUAL(pet.getTags()[1]->getName(), U("Tag2"));

	BOOST_CHECK_EQUAL(pet.getStatus(), U("available"));
	pet.setStatus(U("available"));
}

BOOST_AUTO_TEST_CASE(testFromJsonNoCat)
{
	web::json::value json = web::json::value::parse(U("{\"id\":1,\"name\":\"Test\",\"photoUrls\":[\"url1\",\"url2\"],\"status\":\"available\",\"tags\":[{\"id\":3,\"name\":\"Tag1\"},{\"id\":4,\"name\":\"Tag2\"}]}"));

	swagger::petshop::model::Pet pet;
	pet.fromJson(json);

	BOOST_CHECK(pet.idIsSet());
	BOOST_CHECK_EQUAL(pet.getId(), 1);
	BOOST_CHECK_EQUAL(pet.getName(), U("Test"));
	BOOST_CHECK_EQUAL(pet.getPhotoUrls().size(), 2);
	BOOST_CHECK_EQUAL(pet.getPhotoUrls()[0], U("url1"));
	BOOST_CHECK_EQUAL(pet.getPhotoUrls()[1], U("url2"));

	BOOST_CHECK(pet.getCategory() == nullptr);

	BOOST_CHECK_EQUAL(pet.getTags().size(), 2);
	BOOST_CHECK_EQUAL(pet.getTags()[0]->getId(), 3);
	BOOST_CHECK_EQUAL(pet.getTags()[0]->getName(), U("Tag1"));
	BOOST_CHECK_EQUAL(pet.getTags()[1]->getId(), 4);
	BOOST_CHECK_EQUAL(pet.getTags()[1]->getName(), U("Tag2"));

	BOOST_CHECK_EQUAL(pet.getStatus(), U("available"));
	pet.setStatus(U("available"));
}

BOOST_AUTO_TEST_SUITE_END()
