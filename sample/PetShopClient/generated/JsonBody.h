/*
 * JsonBody.h
 * 
 * This is a JSON http body which can be submitted via http 
 */

#ifndef JsonBody_H_
#define JsonBody_H_

#include "Commons.h"
#include "IHttpBody.h"

#include <cpprest/json.h> 


namespace swagger {

namespace petshop {

namespace model {


class PETSHOP_DECLSPEC JsonBody
    : public IHttpBody
{
public:
    JsonBody( const web::json::value& value );
    virtual ~JsonBody();

    void writeTo( std::ostream& target ) override;
    
protected:
    web::json::value m_Json;
};


}

}

}


#endif /* JsonBody_H_ */