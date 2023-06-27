#pragma once

#include "lmath/matrix.h"

namespace lmath
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
    Point3 operator*( const Matrix4& m ) const;
};

} // namespace lmath