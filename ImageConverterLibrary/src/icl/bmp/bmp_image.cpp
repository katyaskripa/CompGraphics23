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
} // namespace icl::bmp