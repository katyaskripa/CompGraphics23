#pragma once

#include "image_reader.h"

namespace icl
{

class PpmImageReader final : public ImageReader
{
public:
    [[nodiscard]] Image ReadFromFile( const std::string& filepath ) const override;
    [[nodiscard]] Image ReadFromImage( const Image& image ) const override;
};

} // namespace icl
