#include "icl/bmp/bmp_image.h"

namespace icl::bmp
{
Header BmpImage::getHeader() const noexcept
{
    return *header_;
}

BmpImage::BmpImage()
{
    header_ = std::make_shared< Header >();
}

std::int32_t BmpImage::getWidth() const noexcept
{
    return header_->info_header.width;
}

std::int32_t BmpImage::getHeight() const noexcept
{
    return header_->info_header.height;
}

void BmpImage::setHeight( std::int32_t height ) noexcept
{
    header_->info_header.height = height;
}

void BmpImage::setWidth( std::int32_t width ) noexcept
{
    header_->info_header.width = width;
}
} // namespace icl::bmp