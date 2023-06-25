#include "lmath/vec3.h"

#include <cmath>

#include "lmath/matrix.h"
#include "lmath/point2.h"
#include "lmath/point3.h"
#include "lmath/vec2.h"

namespace lmath
{

Vec3::Vec3( float x ) : x{ x }, y{ x }, z{ x } { }

Vec3::Vec3( float x, float y ) : x{ x }, y{ y }, z{ 0 } { }

Vec3::Vec3( float x, float y, float z ) : x{ x }, y{ y }, z{ z } { }

Vec3::Vec3( const Vec2& v ) : x{ v.x }, y{ v.y }, z{ 0 } { }

Vec3::Vec3( const Point3& p1, const Point3& p2 )
    : x{ p2.x - p1.x }
    , y{ p2.y - p1.y }
    , z{ p2.z - p1.z }
{
}

Vec3 Vec3::operator+( const Vec3& v ) const
{
    return { x + v.x, y + v.y, z + v.z };
}

Vec3 Vec3::operator-( const Vec3& v ) const
{
    return { x - v.x, y - v.y, z - v.z };
}

Vec3 Vec3::operator-( const Vec2& v ) const
{
    return { x - v.x, y - v.y, z };
}

void Vec3::scale( const float s )
{
    x *= s;
    y *= s;
    z *= s;
}

float Vec3::dotProduct( const Vec3& v ) const
{
    return x * v.x + y * v.y + z * v.z;
}

Vec3 Vec3::crossProduct( const Vec3& v ) const
{
    return { y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x };
}

Vec3 Vec3::normalize() const
{
    const auto length{ getLength() };
    return { x / length, y / length, z / length };
}

float Vec3::getLength() const
{
    return std::sqrt( x * x + y * y + z * z );
}

float Vec3::getAngle( const Vec3& v1, const Vec3& v2 )
{
    const auto dot_product{ v1.dotProduct( v2 ) };

    const auto len_sq1{ v1.x * v1.x + v1.y * v1.y + v1.z * v1.z };
    const auto len_sq2{ v2.x * v2.x + v2.y * v2.y + v2.z * v2.z };

    return std::acos( dot_product / std::sqrt( len_sq1 * len_sq2 ) );
}

Vec3 Vec3::operator+( const Vec2& v ) const
{
    return { x + v.x, y + v.y, z };
}

Vec3 Vec3::operator*( const float s ) const
{
    return { x * s, y * s, z * s };
}

Vec3 Vec3::neg() const
{
    return *this * -1.0f;
}

Vec3 Vec3::operator*( const Matrix4& m ) const
{
    const auto& data{ m.getData() };

    // clang-format off
    return
    {
        x * data[0] + y * data[4] + y * data[8],
        x * data[1] + y * data[5] + z * data[9],
        x * data[2] + y * data[6] + z * data[10],
    };
    // clang-format on
}

} // namespace lmath