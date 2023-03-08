#pragma once

#include "lmath/point3.h"
#include "lmath/vec3.h"

namespace render
{

struct HitRecord
{
    float distance;
    lmath::Point3 intersection;
    lmath::Vec3 normal;
};

} // namespace render
