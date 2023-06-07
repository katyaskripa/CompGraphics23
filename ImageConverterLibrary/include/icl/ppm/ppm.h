#pragma once

#include <cstdint>
#include <string>

namespace icl::ppm
{
struct PpmHeader
{
    std::string magic_number;
    std::uint64_t width{};
    std::uint64_t height{};
    std::uint32_t max_value_per_color{};
};
} // namespace icl::ppm
