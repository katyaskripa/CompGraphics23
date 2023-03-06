#pragma once

namespace math
{
struct Vec2;
struct Vec3;

struct Point2
{
    float x;
    float y;

    Point2 operator+( const Vec2& v ) const;
};

struct Point3
{
    float x;
    float y;
    float z;

    Point3 operator+( const Vec3& v ) const;
};

struct Vec2
{
    float x;
    float y;

    void scale(const float s);
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

struct Vec3
{
    float x;
    float y;
    float z;

    void scale(const float s);
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
} // namespace math