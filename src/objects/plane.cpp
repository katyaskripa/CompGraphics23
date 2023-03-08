#include "objects/plane.h"

namespace obj
{

Plane::Plane( const lmath::Normal& normal, const lmath::Point3& position )
    : normal( normal )
    , position( position )
{
}

bool Plane::hit( const render::Ray& ray,
                 const float tmin,
                 const float tmax,
                 render::HitRecord& hit ) const
{
    const lmath::Vec3 origin{ ray.origin, position };

    const auto denominator{ ray.direction.dotProduct( normal ) };
    const auto t{ origin.dotProduct( normal ) / denominator };

    if ( t < tmax && t > tmin )
    {
        hit.distance     = t;
        hit.intersection = ray.origin + ( ray.direction * t );
        hit.normal       = normal;
        return true;
    }

    return false;
}

lmath::Normal Plane::getNormal( const lmath::Point3& p ) const
{
    return normal;
}

} // namespace obj
