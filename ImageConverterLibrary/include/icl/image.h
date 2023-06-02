#pragma once

#include <cstdint>
#include <fstream>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace icl
{

struct Header;

struct Pixel
{
    std::uint8_t r{};
    std::uint8_t g{};
    std::uint8_t b{};

    friend std::ifstream& operator>>( std::ifstream& in, Pixel& pixel )
    {
        in >> pixel.r >> pixel.g >> pixel.b;
        return in;
    }
};

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

class Image
{
public:
    virtual ~Image() = default;
    [[nodiscard]] virtual std::vector< std::uint8_t > GetData() const noexcept;
    [[nodiscard]] virtual Header getHeader() const noexcept = 0;

protected:
    std::shared_ptr< Header > header_;
    std::vector< Pixel > data_;
};

} // namespace icl
