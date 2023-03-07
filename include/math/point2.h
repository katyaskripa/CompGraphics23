#pragma once

namespace math
{

struct Point3;
struct Vec2;
struct Vec3;

struct Point2
{
    float x;
    float y;

    explicit Point2( float x = 0 );
    Point2( float x, float y );
    explicit Point2( const Point3& p );
    explicit Point2( const Vec2& v );
    explicit Point2( const Vec3& v );

    Point2 operator+( const Vec2& v ) const;
};

} // namespace math
