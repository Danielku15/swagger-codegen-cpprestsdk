@echo off
echo Compiling codegen
del target\cpprestsdk-swagger-codegen-1.0.0.jar
call mvn package
echo Generating
java -DdebugOperations -cp target/cpprestsdk-swagger-codegen-1.0.0.jar;swagger-codegen-cli.jar io.swagger.codegen.SwaggerCodegen generate^
    -l cpprestsdk^
    -i http://petstore.swagger.io/v2/swagger.json^
    -o sample/PetShopClient/generated
pause