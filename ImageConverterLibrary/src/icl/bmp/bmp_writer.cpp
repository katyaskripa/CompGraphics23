#include "icl/bmp/bmp_writer.h"

#include <fmtlog/fmtlog.h>

#include "icl/bmp/bmp.h"

namespace icl::bmp
{
void BmpImageWriter::WriteImageToFile( const std::shared_ptr< Image > image,
                                       const std::string& filepath ) const
{
    std::ofstream output_file{ filepath, std::ios::binary };
    if ( !output_file.is_open() )
    {
        loge( "Cannot open file to output data: {}", filepath );
        return;
    }

    const auto header{ image->getHeader() };
    output_file.write( reinterpret_cast< const char* >( &header ), sizeof( Header ) );

    for ( const auto& pixel : image->getData() )
    {
        output_file.write( reinterpret_cast< const char* >( &pixel.b ), sizeof( uint8_t ) );
        output_file.write( reinterpret_cast< const char* >( &pixel.g ), sizeof( uint8_t ) );
        output_file.write( reinterpret_cast< const char* >( &pixel.r ), sizeof( uint8_t ) );
    }

    output_file.close();
}
} // namespace icl::bmp