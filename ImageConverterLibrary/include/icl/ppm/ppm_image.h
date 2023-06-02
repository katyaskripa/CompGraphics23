#pragma once

#include "icl/image.h"
#include "icl/ppm/ppm.h"

namespace icl::ppm
{
class PpmImage final : public Image
{
public:
    PpmImage();
    [[nodiscard]] Header getHeader() const noexcept override;
    void setMagicNumber( const std::string& magic_number );

    [[nodiscard]] std::int32_t getWidth() const noexcept override;
    [[nodiscard]] std::int32_t getHeight() const noexcept override;
    void setHeight( std::int32_t height ) noexcept override;
    void setWidth( std::int32_t width ) noexcept override;

    void setMaxValuePerColor( std::uint8_t max_value_per_color );
};
} // namespace icl::ppm