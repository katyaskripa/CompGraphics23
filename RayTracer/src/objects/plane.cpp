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
        hit.intersection = ray.positionAt( t );
        hit.normal       = normal.neg();
        return true;
    }

    return false;
}

lmath::Normal Plane::getNormal( const lmath::Point3& p ) const
{
    return normal;
}

void Plane::translate( const lmath::Vec3& translation )
{
    position = position + translation;
}

bool Plane::firstHit( const render::Ray& ray, float tmin, float tmax, render::HitRecord& hit ) const
{
    return this->hit( ray, tmin, tmax, hit );
}

} // namespace obj
