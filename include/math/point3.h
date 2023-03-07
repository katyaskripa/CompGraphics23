#pragma once

namespace math
{

struct Vec3;

struct Point3
{
    float x;
    float y;
    float z;

    Point3 operator+( const Vec3& v ) const;
};

} // namespace math