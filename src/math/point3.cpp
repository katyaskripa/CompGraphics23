#include "math/point3.h"

#include "math/point2.h"
#include "math/vec2.h"
#include "math/vec3.h"

namespace math
{

Point3::Point3( const float x ) : x( x ), y( x ), z( x ) { }

Point3::Point3( const float x, const float y ) : x( x ), y( y ), z( 0 ) { }

Point3::Point3( const float x, const float y, const float z ) : x( x ), y( y ), z( z ) { }

Point3::Point3( const Point2& p ) : x( p.x ), y( p.y ), z( 0 ) { }

Point3::Point3( const Vec2& v ) : x( v.x ), y( v.y ), z( 0 ) { }

Point3::Point3( const Vec3& v ) : x( v.x ), y( v.y ), z( v.z ) { }

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

Point3 Point3::operator+( const Point3& p ) const
{
    return { x + p.x, y + p.y, z + p.z };
}

Point3 Point3::operator-( const Point3& p ) const
{
    return { x - p.x, y - p.y, z - p.z };
}

Point3 Point3::operator+( const Point2& p ) const
{
    return { x + p.x, y + p.y, z };
}

Point3 Point3::operator-( const Point2& p ) const
{
    return { x - p.x, y - p.y, z };
}

} // namespace math
