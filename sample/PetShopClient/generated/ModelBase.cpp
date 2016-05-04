#include "ModelBase.h"

BEGIN_SDK_NS

namespace model {

ModelBase::ModelBase()
{
}
ModelBase::~ModelBase()
{
}

web::json::value ModelBase::toJson( const utility::string_t& value )
{
	return web::json::value::string(value);
}
web::json::value ModelBase::toJson( const utility::datetime& value )
{
    return web::json::value::string(value.to_string(utility::datetime::ISO_8601));
}
web::json::value ModelBase::toJson( int32_t value )
{
    return web::json::value::number(value);
}
web::json::value ModelBase::toJson( int64_t value )
{
	return web::json::value::number(value);
}
web::json::value ModelBase::toJson( double value )
{
    return web::json::value::number(value);
}

// base64 encoding/decoding based on : https://en.wikibooks.org/wiki/Algorithm_Implementation/Miscellaneous/Base64#C.2B.2B
const static char Base64Chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
const static char Base64PadChar = '=';
web::json::value ModelBase::toJson( std::shared_ptr<HttpContent> content )
{
    std::shared_ptr<std::iostream> value = content->getData();
    value->seekg( 0, value->end );
    size_t length = value->tellg();
    value->seekg( 0, value->beg );
    utility::string_t base64;
    base64.reserve( ((length / 3) + (length % 3 > 0)) * 4 );
    char read[3] = { 0 };
    uint32_t temp;
    for ( size_t idx = 0; idx < length / 3; idx++ )
    {
        value->read( read, 3 );
        temp = (read[0]) << 16;
        temp += (read[1]) << 8;
        temp += (read[2]);
        base64.append( 1, Base64Chars[(temp & 0x00FC0000) >> 18] );
        base64.append( 1, Base64Chars[(temp & 0x0003F000) >> 12] );
        base64.append( 1, Base64Chars[(temp & 0x00000FC0) >> 6] );
        base64.append( 1, Base64Chars[(temp & 0x0000003F)] );
    }
    switch ( length % 3 )
    {
        case 1:
            value->read( read, 1 );
            temp = read[0] << 16; 
            base64.append( 1, Base64Chars[(temp & 0x00FC0000) >> 18] );
            base64.append( 1, Base64Chars[(temp & 0x0003F000) >> 12] );
            base64.append( 2, Base64PadChar );
            break;
        case 2:
            value->read( read, 2 );
            temp = read[0] << 16; 
            temp += read[1] << 8;
            base64.append( 1, Base64Chars[(temp & 0x00FC0000) >> 18] );
            base64.append( 1, Base64Chars[(temp & 0x0003F000) >> 12] );
            base64.append( 1, Base64Chars[(temp & 0x00000FC0) >> 6] );
            base64.append( 1, Base64PadChar );
            break;
    }
    return web::json::value::string( base64 );
}

std::shared_ptr<HttpContent> ModelBase::toMultipart( const std::string& name, const utility::string_t& value, const std::string& contentType)
{
    std::shared_ptr<HttpContent> content(new HttpContent);
    content->setName( name );
    content->setContentDisposition( "form-data" );
    content->setContentType( contentType );
    content->setData( std::shared_ptr<std::iostream>( new std::stringstream( ModelBase::wstringToString(value) ) ) );
    return content;
}
std::shared_ptr<HttpContent> ModelBase::toMultipart( const std::string& name, const utility::datetime& value, const std::string& contentType )
{
    std::shared_ptr<HttpContent> content( new HttpContent );
    content->setName( name );
    content->setContentDisposition( "form-data" );
    content->setContentType( contentType );
    content->setData( std::shared_ptr<std::iostream>( new std::stringstream( ModelBase::wstringToString(value.to_string(utility::datetime::ISO_8601) ) ) ) );
    return content;
}
std::shared_ptr<HttpContent> ModelBase::toMultipart( const std::string& name, std::shared_ptr<HttpContent> value )
{
    std::shared_ptr<HttpContent> content( new HttpContent );
    content->setName( name );
    content->setContentDisposition( value->getContentDisposition() );
    content->setContentType( value->getContentType() );
    content->setData( value->getData() );
    content->setFileName( value->getFileName() );
    return content;
}
std::shared_ptr<HttpContent> ModelBase::toMultipart( const std::string& name, const web::json::value& value, const std::string& contentType )
{
    std::shared_ptr<HttpContent> content( new HttpContent );
    content->setName( name );
    content->setContentDisposition( "form-data" );
    content->setContentType( contentType );
    content->setData( std::shared_ptr<std::iostream>( new std::stringstream( ModelBase::wstringToString(value.serialize()) ) ) );
    return content;
}
std::shared_ptr<HttpContent> ModelBase::toMultipart( const std::string& name, int32_t value, const std::string& contentType )
{
    std::shared_ptr<HttpContent> content( new HttpContent );
    content->setName( name );
    content->setContentDisposition( "form-data" );
    content->setContentType( contentType );
    content->setData( std::shared_ptr<std::iostream>( new std::stringstream( std::to_string( value ) ) ) );
    return content;
}
std::shared_ptr<HttpContent> ModelBase::toMultipart( const std::string& name, int64_t value, const std::string& contentType )
{
    std::shared_ptr<HttpContent> content( new HttpContent );
    content->setName( name );
    content->setContentDisposition( "form-data" );
    content->setContentType( contentType );
    content->setData( std::shared_ptr<std::iostream>( new std::stringstream( std::to_string( value ) ) ) );
    return content;
}
std::shared_ptr<HttpContent> ModelBase::toMultipart( const std::string& name, double value, const std::string& contentType )
{
    std::shared_ptr<HttpContent> content( new HttpContent );
    content->setName( name );
    content->setContentDisposition( "form-data" );
    content->setContentType( contentType );
    content->setData( std::shared_ptr<std::iostream>( new std::stringstream( std::to_string( value ) ) ) );
    return content;
}

std::shared_ptr<HttpContent> ModelBase::streamFromBase64( const web::json::value& value )
{
  	std::shared_ptr<HttpContent> content;
    std::shared_ptr<std::iostream> result(new std::stringstream);
    content->setData(result);
    
    utility::string_t encoded = value.as_string();

    char outBuf[3] = { 0 };
    uint32_t temp = 0;

    utility::string_t::const_iterator cursor = encoded.begin();
    while ( cursor < encoded.end() )
    {
        for ( size_t quantumPosition = 0; quantumPosition < 4; quantumPosition++ )
        {
            temp <<= 6;
            if ( *cursor >= 0x41 && *cursor <= 0x5A )   
            {
                temp |= *cursor - 0x41;		              
            }
            else if ( *cursor >= 0x61 && *cursor <= 0x7A )
            {
                temp |= *cursor - 0x47;
            }
            else if ( *cursor >= 0x30 && *cursor <= 0x39 )
            {
                temp |= *cursor + 0x04;
            }
            else if ( *cursor == 0x2B )
            {
                temp |= 0x3E; //change to 0x2D for URL alphabet
            }
            else if ( *cursor == 0x2F )
            {
                temp |= 0x3F; //change to 0x5F for URL alphabet
            }
            else if ( *cursor == Base64PadChar ) //pad
            {
                switch ( encoded.end() - cursor )
                {
                    case 1: //One pad character
                        outBuf[0] = (temp >> 16) & 0x000000FF;
                        outBuf[1] = (temp >> 8) & 0x000000FF;
                        result->write( outBuf, 2 );
                        return content;
                    case 2: //Two pad characters
                        outBuf[0] = (temp >> 10) & 0x000000FF;
                        result->write( outBuf, 1 );
                        return content;
                    default:
                        throw web::json::json_exception( U( "Invalid Padding in Base 64!" ) );
                }
            }
            else
            {
                throw web::json::json_exception( U( "Non-Valid Character in Base 64!" ) );
            }
            cursor++;
        }

        outBuf[0] = (temp >> 16) & 0x000000FF;
        outBuf[1] = (temp >> 8) & 0x000000FF;
        outBuf[2] = (temp) & 0x000000FF;
        result->write( outBuf, 3 );
    }

    return content;

}
std::string ModelBase::wstringToString( const std::wstring& value )
{
    char const* p = reinterpret_cast<char const*>(&value[0]);
    std::size_t size = value.size() * sizeof( value.front() );
    return std::string(p, size);
}

}

END_SDK_NS