// PetShopClient.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "PetShopClient.h"


// This is an example of an exported variable
PETSHOPCLIENT_API int nPetShopClient=0;

// This is an example of an exported function.
PETSHOPCLIENT_API int fnPetShopClient(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see PetShopClient.h for the class definition
CPetShopClient::CPetShopClient()
{
    return;
}
