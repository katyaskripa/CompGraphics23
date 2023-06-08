#pragma once

#include <cstdint>

namespace icl::bmp
{
constexpr auto kBmpFileType{ 0x4D42 };
constexpr auto kBmpDataOffset{ 54 };
constexpr auto kBmpHeaderSize{ 40 };

#pragma pack( push, 1 )
struct BmpHeader
{
    std::uint16_t file_type{ kBmpFileType };
    std::uint32_t file_size{};
    std::uint32_t reserved{};
    std::uint32_t data_offset{ kBmpDataOffset };
    std::uint32_t header_size{ kBmpHeaderSize };
    std::int32_t width{};
    std::int32_t height{};
    std::uint16_t planes{ 1 };
    std::uint16_t bit_per_pixel{ 24 };
    std::uint32_t compression{};
    std::uint32_t image_size{};
    std::int32_t x_pixels_per_meter{};
    std::int32_t y_pixels_per_meter{};
    std::uint32_t total_colors{};
    std::uint32_t important_colors{};
};
#pragma pack( pop )
} // namespace icl::bmp