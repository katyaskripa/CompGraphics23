#pragma once

#include <string>

#include "image.h"

namespace icl
{

class ImageReader
{
public:
    virtual ~ImageReader() = default;

    [[nodiscard]] virtual Image ReadFromFile( const std::string& filepath ) const = 0;
    [[nodiscard]] virtual Image ReadFromImage( const Image& image ) const         = 0;
};

} // namespace icl