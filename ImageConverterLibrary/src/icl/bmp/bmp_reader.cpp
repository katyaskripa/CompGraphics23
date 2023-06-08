#include "icl/bmp/bmp_reader.h"

#include <fmtlog/fmtlog.h>

#include "icl/bmp/bmp.h"
#include "icl/bmp/bmp_image.h"

namespace icl::bmp
{
std::shared_ptr< Image > BmpImageReader::ReadFromFile( const std::string& filepath ) const
{
    try
    {
        std::ifstream input_file{ filepath, std::ios::binary };
        if ( !input_file.is_open() )
        {
            loge( "Error while trying to read file: {}", filepath );
            return {};
        }

        BmpHeader header;
        input_file.read( reinterpret_cast< char* >( &header ), sizeof( BmpHeader ) );

        if ( header.file_type != kBmpFileType )
        {
            loge( "\"{}\" is not a BMP image", filepath );
            return {};
        }

        if ( header.bit_per_pixel != 24 )
        {
            loge( "Only 24-bit BMP images are supported" );
            return {};
        }

        input_file.seekg( header.data_offset, std::ios::beg );

        const auto padding{ ( 4 - ( header.width * 3 ) % 4 ) % 4 };
        const auto row_size{ header.width * 3 + padding };
        const auto image_size{ row_size * header.height };

        std::vector< std::uint8_t > raw_data( image_size );
        input_file.read( reinterpret_cast< char* >( raw_data.data() ), image_size );

        auto result{ std::make_shared< BmpImage >() };
        result->setWidth( header.width );
        result->setHeight( header.height );

        for ( std::int32_t y{ header.height - 1 }; y >= 0; --y )
        {
            for ( std::int32_t x{ 0 }; x < header.width; ++x )
            {
                const auto index{ ( y * row_size ) + ( x * 3 ) };
                Pixel pixel{ raw_data[ index + 2 ], raw_data[ index + 1 ], raw_data[ index ] };
                result->insertPixel( pixel );
            }
        }

        result->setFileSize( sizeof( BmpHeader ) + result->getData().size() * 3 );

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
BmpImageReader::ReadFromImage( const std::shared_ptr< Image >& image ) const
{
    auto result{ std::make_shared< BmpImage >() };
    result->setWidth( image->getWidth() );
    result->setHeight( image->getHeight() );
    result->setData( image->getData() );
    result->setFileSize( sizeof( BmpHeader ) + result->getData().size() * 3 );
    return result;
}
} // namespace icl::bmp