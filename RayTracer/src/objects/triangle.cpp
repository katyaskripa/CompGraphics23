#include "objects/triangle.h"

#include "lmath/matrix.h"

namespace obj
{
Triangle::Triangle( const lmath::Point3& v0,
                    const lmath::Point3& v1,
                    const lmath::Point3& v2,
                    const bool clockwise )
    : v0( v0 )
    , v1( v1 )
    , v2( v2 )
    , clockwise( clockwise )
{
}

bool Triangle::hit( const render::Ray& ray, float tmin, float tmax, render::HitRecord& hit ) const
{
    const lmath::Vec3 edge2{ v0, v2 };
    const auto h{ ray.direction.crossProduct( edge2 ) };

    const lmath::Vec3 edge1{ v0, v1 };
    const auto a{ edge1.dotProduct( h ) };

    if ( a > -tmin && a < tmin )
    {
        return false;
    }

    const auto f{ 1.0F / a };
    const lmath::Vec3 s{ v0, ray.origin };
    const auto u{ f * s.dotProduct( h ) };

    if ( u < 0.0F || u > 1.0F )
    {
        return false;
    }

    const auto q{ s.crossProduct( edge1 ) };
    const auto v{ f * ray.direction.dotProduct( q ) };

    if ( v < 0.0F || u + v > 1.0F )
    {
        return false;
    }

    const auto t{ f * edge2.dotProduct( q ) };

    if ( t > tmin && t < tmax )
    {
        hit.intersection = ray.positionAt( t );
        hit.distance     = t;
        hit.normal       = getNormal( lmath::Point3{} );

        return true;
    }

    return false;
}

lmath::Normal Triangle::getNormal( const lmath::Point3& p ) const
{
    const lmath::Vec3 edge1{ v0, v1 };
    const lmath::Vec3 edge2{ v0, v2 };
    auto normal{ edge1.crossProduct( edge2 ).normalize() };
    if ( clockwise )
    {
        normal.scale( -1.0F );
    }

    return { normal };
}

void Triangle::translate( const lmath::Vec3& translation )
{
    lmath::Matrix4 transform{ 1.0f };
    transform = transform.translate( translation );
    v0        = v0 * transform;
    v1        = v1 * transform;
    v2        = v2 * transform;
}

bool Triangle::firstHit( const render::Ray& ray,
                         float tmin,
                         float tmax,
                         render::HitRecord& hit ) const
{
    return this->hit( ray, tmin, tmax, hit );
}

void Triangle::scale( const lmath::Vec3& scaling )
{
    lmath::Matrix4 transform{ 1.0f };
    transform = transform.scale( scaling );
    v0        = v0 * transform;
    v1        = v1 * transform;
    v2        = v2 * transform;
}

void Triangle::rotate( const float angle, const lmath::Vec3& axis )
{
    lmath::Matrix4 transform{ 1.0f };
    transform = transform.rotate( angle, axis );
    v0        = v0 * transform;
    v1        = v1 * transform;
    v2        = v2 * transform;
}
} // namespace obj