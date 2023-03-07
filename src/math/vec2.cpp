#include "math/vec2.h"

#include <cmath>

#include "math/vec3.h"

namespace math
{

Vec2 Vec2::operator+( const Vec2& v ) const
{
    return { x + v.x, y + v.y };
}

Vec2 Vec2::operator-( const Vec2& v ) const
{
    return { x - v.x, y - v.y };
}

void Vec2::scale( const float s )
{
    x *= s;
    y *= s;
}

Vec2 Vec2::operator*( const float s ) const
{
    return { x * s, y * s };
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

} // namespace math
