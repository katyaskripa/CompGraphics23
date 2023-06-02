#include "icl/ppm/ppm_writer.h"

#include <fmtlog/fmtlog.h>
#include <fstream>

#include "icl/ppm/ppm.h"

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

    const auto header{ image->getHeader() };
    output_file << header.magic_number << "\n"
                << header.height << ' ' << header.width << '\n'
                << header.max_value_per_color << '\n';
    for ( const auto item : image->GetData() )
    {
        output_file << std::to_string( item ) << ' ';
    }

    output_file.close();
}
} // namespace icl::ppm