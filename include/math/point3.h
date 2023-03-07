#pragma once

namespace math
{

struct Vec2;
struct Vec3;
struct Point2;

struct Point3
{
    float x;
    float y;
    float z;

    explicit Point3( float x = 0 );
    Point3( float x, float y );
    Point3( float x, float y, float z );
    explicit Point3( const Point2& p );
    explicit Point3( const Vec2& v );
    explicit Point3( const Vec3& v );

    Point3 operator+( const Vec3& v ) const;
    Point3 operator-( const Vec3& v ) const;
    Point3 operator+( const Vec2& v ) const;
    Point3 operator-( const Vec2& v ) const;
    Point3 operator+( const Point3& p ) const;
    Point3 operator-( const Point3& p ) const;
    Point3 operator+( const Point2& p ) const;
    Point3 operator-( const Point2& p ) const;
};

} // namespace math