#pragma once

#include "icl/bmp/bmp.h"
#include "icl/bmp/bmp_image.h"
#include "icl/image_reader.h"

namespace icl::bmp
{

class BmpImageReader final : public ImageReader
{
public:
    [[nodiscard]] std::shared_ptr< Image >
    ReadFromFile( const std::string& filepath ) const override;
    [[nodiscard]] std::shared_ptr< Image >
    ReadFromImage( const std::shared_ptr< Image >& image ) const override;
};

} // namespace icl::bmp