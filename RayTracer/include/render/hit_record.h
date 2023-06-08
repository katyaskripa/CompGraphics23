#pragma once

#include "lmath/point3.h"
#include "lmath/vec3.h"
#include "ray.h"

namespace render
{

struct HitRecord
{
    float distance{};
    lmath::Point3 intersection{};
    lmath::Normal normal{};

    void setNormal( const Ray& ray, const lmath::Normal& n );
};

} // namespace render
