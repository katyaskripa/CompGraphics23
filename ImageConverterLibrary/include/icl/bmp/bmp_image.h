#pragma once

#include "icl/bmp/bmp.h"
#include "icl/image.h"

namespace icl::bmp
{
class BmpImage : public Image
{
public:
    BmpImage();
    [[nodiscard]] Header getHeader() const noexcept override;
};
} // namespace icl::bmp