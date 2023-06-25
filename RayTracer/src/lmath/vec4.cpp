#include "lmath/vec4.h"

#include <cmath>

#include "lmath/matrix.h"
#include "lmath/point4.h"

namespace lmath
{

Vec4::Vec4( float x ) : x{ x }, y{ x }, z{ x } { }

Vec4::Vec4( float x, float y ) : x{ x }, y{ y }, z{ 0 } { }

Vec4::Vec4( float x, float y, float z ) : x{ x }, y{ y }, z{ z } { }

Vec4::Vec4( const Point4& p1, const Point4& p2 )
    : x{ p2.x - p1.x }
    , y{ p2.y - p1.y }
    , z{ p2.z - p1.z }
    , w{ p2.w - p1.w }
{
}

Vec4 Vec4::operator+( const Vec4& v ) const
{
    return { x + v.x, y + v.y, z + v.z, w + v.w };
}

Vec4 Vec4::operator-( const Vec4& v ) const
{
    return { x - v.x, y - v.y, z - v.z, w - v.w };
}

void Vec4::scale( const float s )
{
    x *= s;
    y *= s;
    z *= s;
    w *= s;
}

float Vec4::dotProduct( const Vec4& v ) const
{
    return x * v.x + y * v.y + z * v.z + w * v.w;
}

Vec4 Vec4::normalize() const
{
    const auto length{ getLength() };
    return { x / length, y / length, z / length, w / length };
}

float Vec4::getLength() const
{
    return std::sqrt( x * x + y * y + z * z + w * w );
}

float Vec4::getAngle( const Vec4& v1, const Vec4& v2 )
{
    const auto dot_product{ v1.dotProduct( v2 ) };

    const auto len_sq1{ v1.x * v1.x + v1.y * v1.y + v1.z * v1.z + v1.w * v1.w };
    const auto len_sq2{ v2.x * v2.x + v2.y * v2.y + v2.z * v2.z + v2.w * v2.w };

    return std::acos( dot_product / std::sqrt( len_sq1 * len_sq2 ) );
}

Vec4 Vec4::operator*( const float s ) const
{
    return { x * s, y * s, z * s, w * s };
}

Vec4 Vec4::neg() const
{
    return *this * -1.0f;
}

Vec4 Vec4::operator*( const Matrix4& m ) const
{
    const auto& data{ m.getData() };

    // clang-format off
    return
    {
        x * data[0] + y * data[4] + z * data[8] + w * data[12],
        x * data[1] + y * data[5] + z * data[9] + w * data[13],
        x * data[2] + y * data[6] + z * data[10] + w * data[14],
        x * data[3] + y * data[7] + z * data[11] + w * data[15]
    };
    // clang-format on
}
Vec4::Vec4( float x, float y, float z, float w ) : x{ x }, y{ y }, z{ z }, w{ w } { }

} // namespace lmath