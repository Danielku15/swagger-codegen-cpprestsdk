# Swagger Codegen for the cpprestsdk library

# This code generator was integrated into swagger-codegen where it is maintained and extended. This repository only remains for history purposes. 

## Overview
This is a client generation library for Swagger Codegen focusing on generating clients for APIs written using ASP.net Web API.
As client library the [cpprestsdk](https://github.com/Microsoft/cpprestsdk) (former known as Catalina) developer by Microsoft is used and therefore a prerequesite. 
  
## What's Swagger?
The goal of Swagger is to define a standard, language-agnostic interface to REST APIs which allows both humans and computers to discover and understand the capabilities of the service without access to source code, documentation, or through network traffic inspection. When properly defined via Swagger, a consumer can understand and interact with the remote service with a minimal amount of implementation logic. Similar to what interfaces have done for lower-level programming, Swagger removes the guesswork in calling the service.


Check out [OpenAPI-Spec](https://github.com/OAI/OpenAPI-Specification) for additional information about the Swagger project, including additional libraries with support for other languages and more. 

## Details about generated classes

* All model classes can be serialized as JSON and as multipart/form-data. 
* All reference types are kept as std::shared_ptr instances which reduces the number of copy steps and allows better passing of models across the API boundaries without worrying about memory leaks or access violations. 
* For non required properties an additional unset method is provided to completely exclude them from the serialization. 
* Collection type properties have no setters. use the getter to access the collection itself and modify it via this reference.
* When serializing objects to multipart/form-data arrays are stored as JSON. 
* When serializing model properties of type file as JSON they are generated with the following schema: 

```
{
    "ContentDisposition": "form-data",
    "ContentType": "application/zip",
    "FileName": "MyFile.zip",
    "InputStream": "Base64EncodedBytes"
}
```
