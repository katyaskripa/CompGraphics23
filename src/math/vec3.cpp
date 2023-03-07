#include "math/vec3.h"

#include <cmath>

#include "math/vec2.h"

namespace math
{

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

void Vec3::scale(const float s){
    x *= s;
    y *= s;
    z *= s;
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

Vec3 Vec3::operator*( const float s ) const {
    return { x * s, y * s, z * s };
    
}

} // namespace math