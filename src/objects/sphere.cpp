#include "objects/sphere.h"

#include <cmath>

namespace objects
{

Sphere::Sphere( const float radius, const lmath::Point3& position )
    : radius( radius )
    , position( position )
{
}

bool Sphere::hit( const render::Ray& ray,
                  const float tmin,
                  const float tmax,
                  render::HitRecord& hit ) const
{
    const lmath::Vec3 origin{ ray.origin - position };

    const auto a = ray.direction.dotProduct( ray.direction );
    const auto b = 2.0f * origin.dotProduct( ray.direction );
    const auto c = origin.dotProduct( origin ) - radius * radius;

    const auto discriminant = b * b - 4.0f * a * c;

    if ( discriminant > 0.0f )
    {
        const auto root        = std::sqrt( discriminant );
        const auto denominator = ( 2.0f * a );

        auto t = ( -b - root ) / denominator;
        if ( t < tmax && t > tmin )
        {
            hit.distance     = t;
            hit.intersection = ray.origin + ( ray.direction * t );
            hit.normal       = getNormal( hit.intersection );
            return true;
        }

        t = ( -b + root ) / denominator;
        if ( t < tmax && t > tmin )
        {
            hit.distance     = t;
            hit.intersection = ray.origin + ( ray.direction * t );
            hit.normal       = getNormal( hit.intersection );
            return true;
        }
    }

    return false;
}

lmath::Vec3 Sphere::getNormal( const lmath::Point3& p ) const
{
    return lmath::Vec3( p - position ).normalize();
}

} // namespace objects
