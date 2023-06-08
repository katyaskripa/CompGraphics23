#include "icl/ppm/ppm_writer.h"

#include <fmtlog/fmtlog.h>
#include <fstream>

#include "icl/ppm/ppm.h"
#include "icl/ppm/ppm_image.h"

namespace icl::ppm
{
void PpmImageWriter::WriteImageToFile( const std::shared_ptr< Image > image,
                                       const std::string& filepath ) const
{
    std::ofstream output_file{ filepath };
    if ( !output_file.is_open() )
    {
        loge( "Cannot open file to output data: {}", filepath );
        return;
    }

    const auto header{ std::dynamic_pointer_cast< PpmImage >( image )->getHeader() };
    output_file << header.magic_number << "\n"
                << header.width << ' ' << header.height << '\n'
                << header.max_value_per_color << '\n';
    for ( const auto pixel : image->getData() )
    {
        output_file << std::to_string( pixel.r ) << ' ' << std::to_string( pixel.g ) << ' '
                    << std::to_string( pixel.b ) << ' ';
    }

    output_file.close();
}
} // namespace icl::ppm