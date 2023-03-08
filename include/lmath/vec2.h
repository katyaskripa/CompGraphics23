#pragma once

namespace lmath
{

struct Point2;
struct Point3;
struct Vec3;

struct Vec2
{
    float x;
    float y;

    explicit Vec2( float x = 0 );
    Vec2( float x, float y );
    explicit Vec2( const Vec3& v );
    Vec2( const Point2& p1, const Point2& p2 );

    void scale( const float s );
    [[nodiscard]] Vec2 normalize() const;
    [[nodiscard]] float dotProduct( const Vec2& v ) const;
    [[nodiscard]] float getLength() const;
    [[nodiscard]] float crossProduct( const Vec2& v ) const;

    Vec2 operator+( const Vec2& v ) const;
    Vec3 operator+( const Vec3& v ) const;
    Vec2 operator-( const Vec2& v ) const;
    Vec2 operator*( const float s ) const;

    static float getAngle( const Vec2& v1, const Vec2& v2 );
};

} // namespace lmath
