#pragma once

#include "icl/image.h"
#include "icl/ppm/ppm.h"

namespace icl::ppm
{
class PpmImage final : public Image
{
public:
    PpmImage() = default;
    [[nodiscard]] PpmHeader getHeader() const noexcept;
    void setMagicNumber( const std::string& magic_number );

    [[nodiscard]] std::int32_t getWidth() const noexcept override;
    [[nodiscard]] std::int32_t getHeight() const noexcept override;
    void setHeight( std::int32_t height ) noexcept override;
    void setWidth( std::int32_t width ) noexcept override;

    void setMaxValuePerColor( std::uint8_t max_value_per_color );

private:
    PpmHeader header_;
};
} // namespace icl::ppm