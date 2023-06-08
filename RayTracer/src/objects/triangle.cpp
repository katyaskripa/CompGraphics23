#include "objects/triangle.h"

namespace obj
{
Triangle::Triangle( const lmath::Point3& v0, const lmath::Point3& v1, const lmath::Point3& v2 )
    : v0( v0 )
    , v1( v1 )
    , v2( v2 )
{
}

bool Triangle::hit( const render::Ray& ray, float tmin, float tmax, render::HitRecord& hit ) const
{
    // Unimplemented
    return false;
}

lmath::Normal Triangle::getNormal( const lmath::Point3& p ) const
{
    // Unimplemented
    return lmath::Normal();
}
} // namespace obj