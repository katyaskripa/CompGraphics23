#include "math/math.h"

#include <cmath>

namespace math
{
Point2 Point2::operator+( const Vec2& v ) const
{
    return { x + v.x, y + v.y };
}

Point3 Point3::operator+( const Vec3& v ) const
{
    return { x + v.x, y + v.y, z + v.z };
}

Vec2 Vec2::operator+( const Vec2& v ) const
{
    return { x + v.x, y + v.y };
}

Vec2 Vec2::operator-( const Vec2& v ) const
{
    return { x - v.x, y - v.y };
}

Vec3 Vec2::operator+( const Vec3& v ) const
{
    return v + *this;
}

float Vec2::dotProduct( const Vec2& v ) const
{
    return x * v.x + y * v.y;
}

float Vec2::getAngle( const Vec2& v1, const Vec2& v2 )
{
    const auto dot_product{ v1.dotProduct( v2 ) };
    const auto determinant{ v1.x * v2.y - v1.y * v2.x };

    return std::atan2( determinant, dot_product );
}

Vec2 Vec2::normalize() const
{
    const auto length{ getLength() };
    return { x / length, y / length };
}

float Vec2::getLength() const
{
    return std::sqrt( x * x + y * y );
}

float Vec2::crossProduct( const Vec2& v ) const
{
    return x * v.y - y * v.x;
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

float Vec3::dotProduct( const Vec3& v ) const
{
    return x * v.x + y + v.y + z + v.z;
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

} // namespace math