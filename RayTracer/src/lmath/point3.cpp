#include "lmath/point3.h"

#include "lmath/point2.h"
#include "lmath/vec2.h"
#include "lmath/vec3.h"

namespace lmath
{

Point3::Point3( const float x ) : x{ x }, y{ x }, z{ x } { }

Point3::Point3( const float x, const float y ) : x{ x }, y{ y }, z{ 0 } { }

Point3::Point3( const float x, const float y, const float z ) : x{ x }, y{ y }, z{ z } { }

Point3::Point3( const Point2& p ) : x{ p.x }, y{ p.y }, z{ 0 } { }

Point3::Point3( const Vec2& v ) : x{ v.x }, y{ v.y }, z{ 0 } { }

Point3::Point3( const Vec3& v ) : x{ v.x }, y{ v.y }, z{ v.z } { }

Point3 Point3::operator+( const Vec3& v ) const
{
    return { x + v.x, y + v.y, z + v.z };
}

Point3 Point3::operator-( const Vec3& v ) const
{
    return { x - v.x, y - v.y, z - v.z };
}

Point3 Point3::operator+( const Vec2& v ) const
{
    return { x + v.x, y + v.y, z };
}

Point3 Point3::operator-( const Vec2& v ) const
{
    return { x - v.x, y - v.y, z };
}

Point3 Point3::operator*( const Matrix4& m ) const
{
    const auto& data{ m.getData() };

    // clang-format off
    return
    {
        x * data[0] + y * data[4] + z * data[8] + data[12],
        x * data[1] + y * data[5] + z * data[9] + data[13],
        x * data[2] + y * data[6] + z * data[10] + data[14],
    };
    // clang-format on
}

} // namespace lmath
