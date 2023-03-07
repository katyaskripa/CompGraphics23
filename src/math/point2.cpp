#include "math/point2.h"

#include "math/point3.h"
#include "math/vec2.h"
#include "math/vec3.h"

namespace math
{

Point2::Point2( const float x ) : x( x ), y( x ) { }

Point2::Point2( const float x, const float y ) : x( x ), y( y ) { }

Point2::Point2( const Point3& p ) : x( p.x ), y( p.y ) { }

Point2::Point2( const Vec2& v ) : x( v.x ), y( v.y ) { }

Point2::Point2( const Vec3& v ) : x( v.x ), y( v.y ) { }

Point2 Point2::operator+( const Vec2& v ) const
{
    return { x + v.x, y + v.y };
}

Point3 Point2::operator+( const Vec3& v ) const
{
    return { x + v.x, y + v.y, v.z };
}

Point2 Point2::operator-( const Vec2& v ) const
{
    return { x - v.x, y - v.y };
}

Point2 Point2::operator+( const Point2& p ) const
{
    return { x + p.x, y + p.y };
}

Point3 Point2::operator+( const Point3& p ) const
{
    return p + *this;
}

Point2 Point2::operator-( const Point2& p ) const
{
    return { x - p.x, y - p.y };
}

} // namespace math
