#pragma once

namespace lmath
{

struct Point4;
class Matrix4;

struct Vec4
{
    float x{};
    float y{};
    float z{};
    float w{};

    explicit Vec4( float x = 0 );
    Vec4( float x, float y );
    Vec4( float x, float y, float z );
    Vec4( float x, float y, float z, float w );

    Vec4( const Point4& p1, const Point4& p2 );

    void scale( const float s );
    [[nodiscard]] Vec4 neg() const;
    [[nodiscard]] Vec4 normalize() const;
    [[nodiscard]] float dotProduct( const Vec4& v ) const;
    [[nodiscard]] float getLength() const;

    Vec4 operator+( const Vec4& v ) const;
    Vec4 operator-( const Vec4& v ) const;
    Vec4 operator*( const float s ) const;
    Vec4 operator*( const Matrix4& m ) const;

    static float getAngle( const Vec4& v1, const Vec4& v2 );
};

} // namespace lmath