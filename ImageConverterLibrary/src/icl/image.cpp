#include "icl/image.h"

#include <map>
#include <string>

#include <boost/algorithm/string.hpp>
#include <fmtlog/fmtlog.h>

namespace
{
constexpr auto kBmpStr{ "bmp" };
constexpr auto kPpmStr{ "ppm" };
} // namespace

namespace icl
{
std::map< ImageFormat::Format, std::string > ImageFormat::strings_map_{
    { ImageFormat::Format::kBmp, kBmpStr },
    { ImageFormat::Format::kPpm, kPpmStr }
};

ImageFormat::operator std::string() const
{
    return strings_map_.at( type_ );
}

ImageFormat::operator int() const
{
    return type_;
}

ImageFormat::ImageFormat( const std::string& type )
{
    for ( auto itType{ strings_map_.begin() }; itType != strings_map_.end(); ++itType )
    {
        if ( boost::iequals( itType->second, type ) )
        {
            type_ = itType->first;
            return;
        }
    }
    type_ = kUndefined;
}

std::vector< std::uint8_t > Image::GetData() const noexcept
{
    std::vector< std::uint8_t > result;
    for ( const auto& pixel : data_ )
    {
        result.emplace_back( pixel.r );
        result.emplace_back( pixel.g );
        result.emplace_back( pixel.b );
    }
    return result;
}

void Image::insertPixel( const Pixel pixel )
{
    data_.emplace_back( pixel );
}

Pixel Image::getPixel( std::size_t x, std::size_t y ) const
{
    return data_[ y * getWidth() + x ];
}

void Image::setPixel( std::size_t x, std::size_t y, Pixel pixel )
{
    data_[ y * getWidth() + x ] = pixel;
}
} // namespace icl
