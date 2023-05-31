#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace icl
{

class ImageFormat
{
public:
    enum Format
    {
        kUndefined,
        kBmp,
        kPpm
    };

    ImageFormat( const std::string& type );
    operator std::string() const;
    operator int() const;

private:
    static std::map< Format, std::string > strings_map_;
    Format type_;
};

struct Image
{
    virtual ~Image() = default;
    virtual std::vector< std::uint8_t > GetData() const noexcept { return data_; }

    std::vector< std::uint8_t > data_;
};

} // namespace icl
