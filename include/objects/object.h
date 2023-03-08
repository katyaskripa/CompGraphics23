#pragma once

#include "lmath/point3.h"
#include "render/hit_record.h"
#include "render/ray.h"

namespace objects
{

struct Object
{
    virtual ~Object() = default;

    virtual bool
    hit( const render::Ray& ray, float tmin, float tmax, render::HitRecord& hit ) const = 0;

    [[nodiscard]] virtual lmath::Normal getNormal( const lmath::Point3& p ) const = 0;
};

} // namespace objects
