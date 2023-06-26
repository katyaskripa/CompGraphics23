#pragma once

#include "object.h"

namespace obj
{

struct Sphere : public Object
{
    float radius{ 1.0f };
    lmath::Point3 position{};

    Sphere( float radius, const lmath::Point3& position );

    bool
    hit( const render::Ray& ray, float tmin, float tmax, render::HitRecord& hit ) const override;

    bool firstHit( const render::Ray& ray,
                   float tmin,
                   float tmax,
                   render::HitRecord& hit ) const override;

    [[nodiscard]] lmath::Normal getNormal( const lmath::Point3& p ) const override;

    void translate( const lmath::Vec3& translation ) override;
};

} // namespace obj
