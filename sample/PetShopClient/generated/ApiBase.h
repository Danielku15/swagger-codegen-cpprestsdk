/*
 * ApiBase.h
 * 
 * This is the base class for all API classes
 */

#ifndef ApiBase_H_
#define ApiBase_H_

#include "Commons.h"
#include "ApiConfiguration.h"
#include "ApiException.h"

#include <cpprest/details/basic_types.h>
#include <memory> 
#include <vector> 


BEGIN_SDK_NS

namespace api {

class SDK_DECLSPEC ApiBase
{
public:
    ApiBase( std::shared_ptr<ApiConfiguration> configuration );
    virtual ~ApiBase();
    
    static utility::string_t parameterToString(utility::string_t value);
    static utility::string_t parameterToString(int32_t value);
    static utility::string_t parameterToString(int64_t value);
    
    template<class T>
    static utility::string_t parameterToArrayString(std::vector<T> value)
    {
        utility::stringstream_t ss;
        
        int i = 0;
        for( size_t i = 0; i < value.size(); i++)
        {
            if( i > 0) ss << U(", ");
            ss << ApiBase::parameterToString(value[i]);
        }

        return ss.str();        
    }
    
protected:
    std::shared_ptr<ApiConfiguration> m_Configuration;
};

}

END_SDK_NS

#endif /* ApiBase_H_ */