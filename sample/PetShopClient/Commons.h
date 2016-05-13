#ifndef Commons_H_
#define Commons_H_

#pragma warning (disable: 4251)
#pragma warning (disable: 4275)

#ifdef PETSHOPCLIENT_EXPORTS
#define PETSHOP_DECLSPEC __declspec(dllexport)
#else
#define PETSHOP_DECLSPEC __declspec(dllimport)
#endif

#endif /* Commons_H_ */