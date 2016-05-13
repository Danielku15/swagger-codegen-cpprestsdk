/*
 * IHttpBody.h
 * 
 * This is the interface for contents that can be sent to a remote HTTP server. 
 */

#ifndef IHttpBody_H_
#define IHttpBody_H_

#include "Commons.h"

#include <memory>

#include <cpprest/details/basic_types.h> 



namespace swagger {

namespace petshop {

namespace model {


class PETSHOP_DECLSPEC IHttpBody
{
public:
    virtual ~IHttpBody() { }

    virtual void writeTo( std::ostream& stream ) = 0;
};


}

}

}


#endif /* IHttpBody_H_ */