#include "icl/ppm/ppm_image.h"

namespace icl::ppm
{
Header PpmImage::getHeader() const noexcept
{
    return *header_;
}

PpmImage::PpmImage()
{
    header_ = std::make_shared< Header >();
}

void PpmImage::setMagicNumber( const std::string& magic_number )
{
    header_->magic_number = magic_number;
}
void PpmImage::setHeight( const std::uint64_t height )
{
    header_->height = height;
}
void PpmImage::setWidth( const std::uint64_t width )
{
    header_->width = width;
}
void PpmImage::setMaxValuePerColor( const std::uint8_t max_value_per_color )
{
    header_->max_value_per_color = max_value_per_color;
}
void PpmImage::insertPixel( const Pixel pixel )
{
    data_.emplace_back( pixel );
}
} // namespace icl::ppm
