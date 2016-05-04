/*
 * ApiConfiguration.h
 * 
 * This class represents a single item of a multipart-formdata request. 
 */

#ifndef ApiConfiguration_H_
#define ApiConfiguration_H_

#include "Commons.h"

#include <cpprest/details/basic_types.h> 

BEGIN_SDK_NS

namespace api {

class SDK_DECLSPEC ApiConfiguration
{
public:
    ApiConfiguration();
    virtual ~ApiConfiguration();
    
    utility::string_t getBaseUrl() const;
    void setBaseUrl( const utility::string_t value );

protected:
    utility::string_t m_BaseUrl;
};

}

END_SDK_NS

#endif /* ApiConfiguration_H_ */