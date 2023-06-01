#pragma once

#include <string>

#include "icl/image.h"

namespace icl
{
struct Header
{
    std::string magic_number;
    std::uint64_t width{};
    std::uint64_t height{};
    std::uint32_t max_value_per_color{};
};
} // namespace icl
