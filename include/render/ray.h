#pragma once

#include "lmath/point3.h"
#include "lmath/vec3.h"

namespace render
{

struct Ray
{
    lmath::Point3 origin;
    lmath::Vec3 direction;
};

} // namespace render
