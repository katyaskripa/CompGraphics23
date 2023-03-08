#include "objects/disk.h"

namespace obj
{

Disk::Disk( const float radius, const lmath::Normal& normal, const lmath::Point3& position )
    : radius( radius )
    , normal( normal )
    , position( position )
{
}

bool Disk::hit( const render::Ray& ray,
                const float tmin,
                const float tmax,
                render::HitRecord& hit ) const
{
    const lmath::Vec3 origin{ ray.origin, position };

    const auto denominator{ ray.direction.dotProduct( normal ) };
    const auto t{ origin.dotProduct( normal ) / denominator };

    if ( t < tmax && t > tmin )
    {
        hit.intersection = ray.origin + ( ray.direction * t );
        hit.normal       = normal;
        hit.distance     = t;

        const lmath::Vec3 distance{ hit.intersection, position };
        const auto distance2{ distance.dotProduct( distance ) };
        return distance2 <= ( radius * radius );
    }

    return false;
}

lmath::Normal Disk::getNormal( const lmath::Point3& p ) const
{
    return normal;
}

} // namespace obj
