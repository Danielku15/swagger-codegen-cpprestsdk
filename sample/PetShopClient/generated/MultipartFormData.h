/*
 * MultipartFormData.h
 * 
 * This class represents a container for building a application/x-multipart-formdata requests. 
 */

#ifndef MultipartFormData_H_
#define MultipartFormData_H_

#include "Commons.h"
#include "HttpContent.h"

#include <cpprest/details/basic_types.h>
#include <vector>
#include <memory>

BEGIN_SDK_NS

namespace model {

class SDK_DECLSPEC MultipartFormData
{
public:
    MultipartFormData();
    virtual ~MultipartFormData();

    virtual void add( std::shared_ptr<HttpContent> content );
    virtual std::string getBoundary();
    virtual void writeTo( std::ostream& target );
    
protected:
    std::vector<std::shared_ptr<HttpContent>> m_Contents;
    std::string m_Boundary;
};

}

END_SDK_NS

#endif /* MultipartFormData_H_ */