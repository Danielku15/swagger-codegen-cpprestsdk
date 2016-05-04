/*
 * ApiBase.h
 * 
 * This is the base class for all API classes
 */

#ifndef ApiBase_H_
#define ApiBase_H_

#include "Commons.h"

#include <cpprest/details/basic_types.h>
#include <cpprest/json.h> 

BEGIN_SDK_NS

namespace api {

class SDK_DECLSPEC ApiBase
{
public:
    ApiBase();
    virtual ~ApiBase();
};

}

END_SDK_NS

#endif /* ApiBase_H_ */