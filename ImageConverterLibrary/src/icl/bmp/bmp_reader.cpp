#include "icl/bmp/bmp_reader.h"

namespace icl::bmp
{

std::shared_ptr< Image > BmpImageReader::ReadFromFile( const std::string& filepath ) const
{
    return {};
}

std::shared_ptr< Image > BmpImageReader::ReadFromImage( const icl::Image& image ) const
{
    return {};
}

} // namespace icl::bmp