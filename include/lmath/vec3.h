#pragma once

namespace lmath
{

struct Point2;
struct Point3;
struct Vec2;

struct Vec3
{
    float x;
    float y;
    float z;

    explicit Vec3( float x = 0 );
    Vec3( float x, float y );
    Vec3( float x, float y, float z );
    explicit Vec3( const Vec2& v );
    Vec3( const Point3& p1, const Point3& p2 );

    void scale( const float s );
    [[nodiscard]] Vec3 normalize() const;
    [[nodiscard]] float dotProduct( const Vec3& v ) const;
    [[nodiscard]] float getLength() const;
    [[nodiscard]] Vec3 crossProduct( const Vec3& v ) const;

    Vec3 operator+( const Vec3& v ) const;
    Vec3 operator+( const Vec2& v ) const;
    Vec3 operator-( const Vec3& v ) const;
    Vec3 operator-( const Vec2& v ) const;
    Vec3 operator*( const float s ) const;

    static float getAngle( const Vec3& v1, const Vec3& v2 );
};

using Normal = Vec3;

} // namespace lmath