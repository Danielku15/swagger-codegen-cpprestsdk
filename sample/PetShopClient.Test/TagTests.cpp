#include "Tests.h"
#include <model/Tag.h>

BOOST_AUTO_TEST_SUITE(TagTests)

BOOST_AUTO_TEST_CASE(testToJsonFull)
{
	swagger::petshop::model::Tag tag;
	tag.setId(1);
	tag.setName(U("Test"));

	web::json::value json = tag.toJson();

	auto jsonString = json.serialize();

	BOOST_CHECK_EQUAL(U("{\"id\":1,\"name\":\"Test\"}"), jsonString);
}

BOOST_AUTO_TEST_CASE(testToJsonMissingId)
{
	swagger::petshop::model::Tag tag;
	tag.setName(U("Test"));

	web::json::value json = tag.toJson();

	auto jsonString = json.serialize();

	BOOST_CHECK_EQUAL(U("{\"name\":\"Test\"}"), jsonString);
}

BOOST_AUTO_TEST_CASE(testToJsonMissingName)
{
	swagger::petshop::model::Tag tag;
	tag.setId(1);

	web::json::value json = tag.toJson();

	auto jsonString = json.serialize();

	BOOST_CHECK_EQUAL(U("{\"id\":1}"), jsonString);
}

BOOST_AUTO_TEST_CASE(testToJsonEmpty)
{
	swagger::petshop::model::Tag tag;

	web::json::value json = tag.toJson();
	auto jsonString = json.serialize();

	BOOST_CHECK_EQUAL(U("{}"), jsonString);
}

BOOST_AUTO_TEST_CASE(testFromJsonFull)
{
	web::json::value json = web::json::value::parse(U("{\"id\":1,\"name\":\"Test\"}"));

	swagger::petshop::model::Tag tag;
	tag.fromJson(json);

	BOOST_CHECK(tag.idIsSet());
	BOOST_CHECK_EQUAL(tag.getId(), 1);
	BOOST_CHECK(tag.nameIsSet());
	BOOST_CHECK_EQUAL(tag.getName(), U("Test"));
}

BOOST_AUTO_TEST_CASE(testFromJsonMissingId)
{
	web::json::value json = web::json::value::parse(U("{\"name\":\"Test\"}"));

	swagger::petshop::model::Tag tag;
	tag.fromJson(json);

	BOOST_CHECK(!tag.idIsSet());
	BOOST_CHECK_EQUAL(tag.getId(), 0);
	BOOST_CHECK(tag.nameIsSet());
	BOOST_CHECK_EQUAL(tag.getName(), U("Test"));
}

BOOST_AUTO_TEST_CASE(testFromJsonMissingName)
{
	web::json::value json = web::json::value::parse(U("{\"id\":1}"));

	swagger::petshop::model::Tag tag;
	tag.fromJson(json);

	BOOST_CHECK(tag.idIsSet());
	BOOST_CHECK_EQUAL(tag.getId(), 1);
	BOOST_CHECK(!tag.nameIsSet());
	BOOST_CHECK_EQUAL(tag.getName(), U(""));
}

BOOST_AUTO_TEST_CASE(testFromJsonEmpty)
{
	web::json::value json = web::json::value::parse(U("{}"));

	swagger::petshop::model::Tag tag;
	tag.fromJson(json);

	BOOST_CHECK(!tag.idIsSet());
	BOOST_CHECK_EQUAL(tag.getId(), 0);
	BOOST_CHECK(!tag.nameIsSet());
	BOOST_CHECK_EQUAL(tag.getName(), U(""));
}

BOOST_AUTO_TEST_CASE(testToMultipartFull)
{
	swagger::petshop::model::Tag tag;
	tag.setId(1);
	tag.setName(U("Test"));

	std::shared_ptr<swagger::petshop::model::MultipartFormData> multipart = std::make_shared<swagger::petshop::model::MultipartFormData>(U("test"));
	tag.toMultipart(multipart, U("cat"));

	std::stringstream out;
	multipart->writeTo(out);

	std::string result = out.str();
	BOOST_CHECK_EQUAL(
		"\r\n"
		"--test\r\n"
		"Content-Disposition: form-data; name=\"cat.id\"\r\n"
		"\r\n"
		"1\r\n"
		"--test\r\n"
		"Content-Disposition: form-data; name=\"cat.name\"\r\n"
		"\r\n"
		"Test\r\n"
		"--test--\r\n", result);
}

BOOST_AUTO_TEST_CASE(testToMultipartMissingId)
{
	swagger::petshop::model::Tag tag;
	tag.setName(U("Test"));

	std::shared_ptr<swagger::petshop::model::MultipartFormData> multipart = std::make_shared<swagger::petshop::model::MultipartFormData>(U("test"));
	tag.toMultipart(multipart, U("cat"));

	std::stringstream out;
	multipart->writeTo(out);

	std::string result = out.str();
	BOOST_CHECK_EQUAL(
		"\r\n"
		"--test\r\n"
		"Content-Disposition: form-data; name=\"cat.name\"\r\n"
		"\r\n"
		"Test\r\n"
		"--test--\r\n", result);
}

BOOST_AUTO_TEST_CASE(testToMultipartMissingName)
{
	swagger::petshop::model::Tag tag;
	tag.setId(1);

	std::shared_ptr<swagger::petshop::model::MultipartFormData> multipart = std::make_shared<swagger::petshop::model::MultipartFormData>(U("test"));
	tag.toMultipart(multipart, U("cat"));

	std::stringstream out;
	multipart->writeTo(out);

	std::string result = out.str();
	BOOST_CHECK_EQUAL(
		"\r\n"
		"--test\r\n"
		"Content-Disposition: form-data; name=\"cat.id\"\r\n"
		"\r\n"
		"1\r\n"
		"--test--\r\n", result);
}

BOOST_AUTO_TEST_CASE(testToMultipartEmpty)
{
	swagger::petshop::model::Tag tag;

	std::shared_ptr<swagger::petshop::model::MultipartFormData> multipart = std::make_shared<swagger::petshop::model::MultipartFormData>(U("test"));
	tag.toMultipart(multipart, U("cat"));

	std::stringstream out;
	multipart->writeTo(out);

	std::string result = out.str();
	BOOST_CHECK_EQUAL(
		"\r\n"
		"--test--\r\n", result);
}

// TODO: from multipart

BOOST_AUTO_TEST_SUITE_END()