#include "MultipartFormData.h"

#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp> 

BEGIN_SDK_NS

namespace model {

MultipartFormData::MultipartFormData()
{
    std::stringstream uuidString;
    uuidString << boost::uuids::random_generator()();
    m_Boundary = uuidString.str();
}

MultipartFormData::~MultipartFormData()
{
}

std::string MultipartFormData::getBoundary()
{
    return m_Boundary;
}

void MultipartFormData::add( std::shared_ptr<HttpContent> content )
{
    m_Contents.push_back( content );
}

void MultipartFormData::writeTo( std::ostream& target )
{
    for ( size_t i = 0; i < m_Contents.size(); i++ )
    {
        std::shared_ptr<HttpContent> content = m_Contents[i];

        // boundary
        target << "\r\n" << "--" << m_Boundary << "\r\n";

        // headers
        target << "Content-Disposition: " << content->getContentDisposition();
        if ( content->getName().size() > 0 )
        {
            target << "; name=\"" << content->getName();
        }
        if ( content->getFileName().size() > 0 )
        {
            target << "; filename=\"" << content->getFileName() << "\"";
        }
        target << "\r\n";

        if ( content->getContentType().size() > 0 )
        {
            target << "Content-Type: " << content->getContentType() << "\r\n";
        }

        target << "\r\n";

        // body
        std::shared_ptr<std::iostream> data = content->getData();
        data->seekg( 0, data->beg );
        target << data->rdbuf();
    }

    target << "\r\n--" << m_Boundary << "--\r\n";
}

}

END_SDK_NS