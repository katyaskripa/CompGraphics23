#include "icl/ppm/ppm_reader.h"

#include <fstream>

#include <boost/algorithm/string.hpp>
#include <fmtlog/fmtlog.h>

#include "icl/ppm/ppm.h"
#include "icl/ppm/ppm_image.h"

namespace icl::ppm
{
std::shared_ptr< Image > PpmImageReader::ReadFromFile( const std::string& filepath ) const
{
    try
    {
        auto result{ std::make_shared< PpmImage >() };

        std::ifstream input_file{ filepath };
        if ( !input_file.is_open() )
        {
            loge( "Error while trying to read file: {}", filepath );
            return {};
        }

        std::string format;
        while ( ( input_file.peek() != '\n' ) && ( input_file >> format ) )
            ;
        input_file.seekg( 1, std::ios::cur );

        if ( !boost::iequals( format, "p3" ) )
        {
            loge( "Unsupported ppm file. This program supports only p3 format!" );
            return {};
        }

        std::int32_t width{};
        while ( ( input_file.peek() != '\n' ) && ( input_file.peek() != ' ' )
                && ( input_file >> width ) )
            ;
        input_file.seekg( 1, std::ios::cur );

        std::int32_t height{};
        while ( ( input_file.peek() != '\n' ) && ( input_file.peek() != ' ' )
                && ( input_file >> height ) )
            ;
        input_file.seekg( 1, std::ios::cur );

        std::uint32_t max_value_per_color{};
        while ( ( input_file.peek() != '\n' ) && ( input_file >> max_value_per_color ) )
            ;

        result->setMagicNumber( format );
        result->setWidth( width );
        result->setHeight( height );
        result->setMaxValuePerColor( max_value_per_color );

        const auto jump_over_spaces{ [ &input_file ]()
                                     {
                                         while ( ( ( input_file.peek() == '\n' )
                                                   || ( input_file.peek() == ' ' )
                                                   || ( input_file.peek() == '\t' ) )
                                                 && !input_file.eof() )
                                         {
                                             input_file.seekg( 1, std::ios::cur );
                                         }
                                     } };

        jump_over_spaces();
        while ( !input_file.eof() )
        {
            std::string r, g, b;

            input_file >> r;
            jump_over_spaces();
            input_file >> g;
            jump_over_spaces();
            input_file >> b;

            Pixel pixel{ static_cast< std::uint8_t >( std::stoi( r ) ),
                         static_cast< std::uint8_t >( std::stoi( g ) ),
                         static_cast< std::uint8_t >( std::stoi( b ) ) };

            result->insertPixel( pixel );

            jump_over_spaces();
        }

        input_file.close();

        return result;
    }
    catch ( const std::exception& ex )
    {
        loge( "While reading ppm file got an error: {}", ex.what() );
    }
    catch ( ... )
    {
        loge( "While reading ppm file got an error: unknown exception" );
    }
    return {};
}

std::shared_ptr< Image >
PpmImageReader::ReadFromImage( const std::shared_ptr< Image >& image ) const
{
    auto result{ std::make_shared< PpmImage >() };
    result->setMagicNumber( "P3" );
    result->setWidth( image->getWidth() );
    result->setHeight( image->getHeight() );
    result->setMaxValuePerColor( 255 );
    result->setData( image->getData() );
    return result;
}
} // namespace icl::ppm