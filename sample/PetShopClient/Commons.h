#ifndef Commons_H_
#define Commons_H_

#pragma warning (disable: 4251)

#ifdef PETSHOPCLIENT_EXPORTS
#define SDK_DECLSPEC __declspec(dllexport)
#else
#define SDK_DECLSPEC __declspec(dllimport)
#endif

#define BEGIN_SDK_NS namespace petshop { 
#define END_SDK_NS }

#endif /* Commons_H_ */