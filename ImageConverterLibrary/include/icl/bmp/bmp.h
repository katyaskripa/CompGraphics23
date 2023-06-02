#pragma once

#include <cstdint>

namespace icl
{
constexpr std::uint32_t kSrgb{ 0x73524742 };
constexpr std::uint16_t kBmpFileTpe{ 0x4D42 };

#pragma pack( push, 1 )
struct BmpFileHeader
{
    std::uint16_t file_type{ kBmpFileTpe };
    std::uint32_t file_size{};
    std::uint16_t reserved1{};
    std::uint16_t reserved2{};
    std::uint32_t offset_data{};
};
#pragma pack( pop )

#pragma pack( push, 1 )
struct BmpInfoHeader
{
    std::uint32_t size{};
    std::int32_t width{};
    std::int32_t height{};

    std::uint16_t planes{ 1 };
    std::uint16_t bit_count{};
    std::uint32_t compression{};
    std::uint32_t size_image{};
    std::int32_t x_pixels_per_meter{};
    std::int32_t y_pixels_per_meter{};
    std::uint32_t colors_used{};
    std::uint32_t colors_important{};
};
#pragma pack( pop )

#pragma pack( push, 1 )
struct BmpColorHeader
{
    std::uint32_t red_mask{ 0x00ff0000 };
    std::uint32_t green_mask{ 0x0000ff00 };
    std::uint32_t blue_mask{ 0x000000ff };
    std::uint32_t alpha_mask{ 0xff000000 };
    std::uint32_t color_space_type{ kSrgb };
    std::uint32_t unused[ 16 ]{};
};
#pragma pack( pop )

struct Header
{
    BmpFileHeader file_header;
    BmpInfoHeader info_header;
    BmpColorHeader color_header;
};
} // namespace icl