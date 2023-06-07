#pragma once

#include <cmath>

#include "lmath/point2.h"
#include "lmath/point3.h"
#include "lmath/vec2.h"
#include "lmath/vec3.h"

namespace lmath
{

inline float toRad( const float deg )
{
    return deg * M_PI / 180.0f;
}

inline float toDeg( const float rad )
{
    return rad * 180.0f / M_PI;
}

} // namespace lmath
