#pragma once

#include "object.h"

namespace objects
{

struct Disk : Object
{
    float radius = 1.0f;
    lmath::Normal normal;
    lmath::Point3 position;

    Disk( float radius, const lmath::Normal& normal, const lmath::Point3& position );

    bool
    hit( const render::Ray& ray, float tmin, float tmax, render::HitRecord& hit ) const override;

    [[nodiscard]] lmath::Normal getNormal( const lmath::Point3& p ) const override;
};

} // namespace objects
