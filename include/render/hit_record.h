#pragma once

#include "lmath/point3.h"
#include "lmath/vec3.h"

namespace render
{

struct HitRecord
{
    float distance;
    lmath::Point3 intersection;
    lmath::Normal normal;
};

} // namespace render
