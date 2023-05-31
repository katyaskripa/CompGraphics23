#pragma once

#include <cstdint>
#include <vector>

namespace icl
{

struct Image
{
    virtual ~Image() = default;
    virtual std::vector<std::uint8_t> GetData() const noexcept {
        return data_;
    }

    std::vector<std::uint8_t> data_;
};

} // namespace icl