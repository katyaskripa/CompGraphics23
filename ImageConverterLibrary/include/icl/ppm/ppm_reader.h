#pragma once

#include "icl/image_reader.h"

namespace icl::ppm
{

class PpmImageReader final : public ImageReader
{
public:
    [[nodiscard]] std::shared_ptr< Image >
    ReadFromFile( const std::string& filepath ) const override;
    [[nodiscard]] std::shared_ptr< Image > ReadFromImage( const Image& image ) const override;
};

} // namespace icl::ppm
