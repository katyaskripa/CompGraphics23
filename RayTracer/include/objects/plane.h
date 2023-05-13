#pragma once

#include "object.h"

namespace obj
{

struct Plane : Object
{
    lmath::Normal normal{};
    lmath::Point3 position{};

    Plane( const lmath::Normal& normal, const lmath::Point3& position );

    bool
    hit( const render::Ray& ray, float tmin, float tmax, render::HitRecord& hit ) const override;

    [[nodiscard]] lmath::Normal getNormal( const lmath::Point3& p ) const override;
};

} // namespace obj
