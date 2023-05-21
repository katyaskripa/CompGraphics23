#pragma once

namespace lmath
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
    Point3 operator+( const Vec3& v ) const;
    Point2 operator-( const Vec2& v ) const;
};

} // namespace lmath
