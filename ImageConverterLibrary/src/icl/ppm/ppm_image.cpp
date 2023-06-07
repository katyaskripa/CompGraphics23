#include "icl/ppm/ppm_image.h"

namespace icl::ppm
{
PpmHeader PpmImage::getHeader() const noexcept
{
    return header_;
}

void PpmImage::setMagicNumber( const std::string& magic_number )
{
    header_.magic_number = magic_number;
}

void PpmImage::setHeight( std::int32_t height ) noexcept
{
    header_.height = height;
}

void PpmImage::setWidth( std::int32_t width ) noexcept
{
    header_.width = width;
}

void PpmImage::setMaxValuePerColor( const std::uint8_t max_value_per_color )
{
    header_.max_value_per_color = max_value_per_color;
}

std::int32_t PpmImage::getWidth() const noexcept
{
    return static_cast< std::int32_t >( header_.width );
}

std::int32_t PpmImage::getHeight() const noexcept
{
    return static_cast< std::int32_t >( header_.height );
}
} // namespace icl::ppm
