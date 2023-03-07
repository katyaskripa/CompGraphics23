#pragma once

namespace math
{

struct Vec2;

struct Point2
{
    float x;
    float y;

    Point2 operator+( const Vec2& v ) const;
};

} // namespace math
