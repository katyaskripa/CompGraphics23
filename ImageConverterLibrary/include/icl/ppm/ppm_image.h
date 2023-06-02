#pragma once

#include "icl/image.h"
#include "icl/ppm/ppm.h"

namespace icl::ppm
{
class PpmImage : public Image
{
public:
    PpmImage();
    [[nodiscard]] Header getHeader() const noexcept override;
    void setMagicNumber( const std::string& magic_number );
    void setHeight( std::uint64_t height );
    void setWidth( std::uint64_t width );
    void setMaxValuePerColor( std::uint8_t max_value_per_color );
    void insertPixel( Pixel pixel );
};
} // namespace icl::ppm