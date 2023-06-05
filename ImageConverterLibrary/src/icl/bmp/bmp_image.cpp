#include "icl/bmp/bmp_image.h"

namespace icl::bmp
{
BmpImage::BmpImage()
{
    header_ = std::make_shared< Header >();
}

Header BmpImage::getHeader() const noexcept
{
    return *header_;
}

std::int32_t BmpImage::getWidth() const noexcept
{
    return header_->width;
}

std::int32_t BmpImage::getHeight() const noexcept
{
    return header_->height;
}

void BmpImage::setHeight( std::int32_t height ) noexcept
{
    header_->height = height;
}

void BmpImage::setWidth( std::int32_t width ) noexcept
{
    header_->width = width;
}

void BmpImage::setFileSize( std::uint32_t file_size ) noexcept
{
    header_->file_size = file_size;
}
} // namespace icl::bmp