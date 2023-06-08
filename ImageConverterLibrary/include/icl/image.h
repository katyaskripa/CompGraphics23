#pragma once

#include <cstdint>
#include <fstream>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace icl
{

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

    [[nodiscard]] virtual std::int32_t getWidth() const noexcept  = 0;
    [[nodiscard]] virtual std::int32_t getHeight() const noexcept = 0;
    virtual void setHeight( std::int32_t height ) noexcept        = 0;
    virtual void setWidth( std::int32_t width ) noexcept          = 0;

    [[nodiscard]] Pixel getPixel( std::size_t x, std::size_t y ) const;
    [[nodiscard]] std::vector< Pixel > getData() const noexcept;
    void setPixel( std::size_t x, std::size_t y, Pixel pixel );
    void insertPixel( Pixel pixel );
    void setData( const std::vector< Pixel >& data ) noexcept;
    void setData( std::vector< Pixel >&& data ) noexcept;

protected:
    std::vector< Pixel > data_;
};

} // namespace icl
