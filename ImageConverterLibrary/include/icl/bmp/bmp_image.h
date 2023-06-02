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

    [[nodiscard]] std::int32_t getWidth() const noexcept override;
    [[nodiscard]] std::int32_t getHeight() const noexcept override;
    void setHeight( std::int32_t height ) noexcept override;
    void setWidth( std::int32_t width ) noexcept override;
};
} // namespace icl::bmp