#ifndef Commons_H_
#define Commons_H_

#pragma warning (disable: 4251)
#pragma warning (disable: 4275)

#ifdef PETSHOPCLIENT_EXPORTS
#define SDK_DECLSPEC __declspec(dllexport)
#else
#define SDK_DECLSPEC __declspec(dllimport)
#endif

#define BEGIN_SDK_NS namespace petshop { 
#define END_SDK_NS }
#define USE_SDK_NS(NS) using namespace petshop::NS;

#endif /* Commons_H_ */