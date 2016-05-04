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
    m_ContentLookup[content->getName()] = content;
}

bool MultipartFormData::hasContent(const std::string& name) const
{
    return m_ContentLookup.find(name) != m_ContentLookup.end();
}

std::shared_ptr<HttpContent> MultipartFormData::getContent(const std::string& name) const
{
    auto result = m_ContentLookup.find(name);
    if(result == m_ContentLookup.end())
    {
        return std::shared_ptr<HttpContent>(nullptr);
    }
    return result->second;
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