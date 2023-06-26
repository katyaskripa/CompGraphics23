#include "objects/sphere.h"

#include <cmath>

namespace obj
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
    const lmath::Vec3 origin{ position, ray.origin };

    const auto a = ray.direction.dotProduct( ray.direction );
    const auto b = 2.0f * origin.dotProduct( ray.direction );
    const auto c = origin.dotProduct( origin ) - radius * radius;

    const auto discriminant{ b * b - 4.0f * a * c };

    if ( discriminant > 0.0f )
    {
        const auto root{ std::sqrt( discriminant ) };
        const auto denominator = ( 2.0f * a );

        auto t{ ( -b - root ) / denominator };
        if ( t < tmax && t > tmin )
        {
            hit.distance     = t;
            hit.intersection = ray.positionAt( t );
            hit.setNormal( ray, getNormal( hit.intersection ) );
            return true;
        }

        t = ( -b + root ) / denominator;
        if ( t < tmax && t > tmin )
        {
            hit.distance     = t;
            hit.intersection = ray.positionAt( t );
            hit.setNormal( ray, getNormal( hit.intersection ) );
            return true;
        }
    }

    return false;
}

lmath::Normal Sphere::getNormal( const lmath::Point3& p ) const
{
    return lmath::Normal( position, p ).normalize();
}

void Sphere::translate( const lmath::Vec3& translation )
{
    position = position + translation;
}

} // namespace obj
