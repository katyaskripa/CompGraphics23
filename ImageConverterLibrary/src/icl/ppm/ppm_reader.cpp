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

        if ( !( boost::iequals( format, "p3" ) || boost::iequals( format, "p6" ) ) )
        {
            loge( "Unsupported ppm file. This program supports only p3 and p6 format!" );
            return {};
        }

        std::uint64_t height{}, width{};
        std::uint32_t max_value_per_color{};
        while ( ( input_file.peek() != '\n' ) && ( input_file.peek() != ' ' )
                && ( input_file >> height ) )
            ;
        input_file.seekg( 1, std::ios::cur );

        while ( ( input_file.peek() != '\n' ) && ( input_file.peek() != ' ' )
                && ( input_file >> width ) )
            ;
        input_file.seekg( 1, std::ios::cur );

        while ( ( input_file.peek() != '\n' ) && ( input_file >> max_value_per_color ) )
            ;
        input_file.seekg( 1, std::ios::cur );

        while ( !input_file.eof() )
        {
            Pixel pixel;
            input_file >> pixel;
            result->insertPixel( pixel );
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

std::shared_ptr< Image > PpmImageReader::ReadFromImage( const icl::Image& image ) const
{
    return {};
}
} // namespace icl::ppm