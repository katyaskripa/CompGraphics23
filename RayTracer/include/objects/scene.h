#pragma once

#include <memory>
#include <vector>

#include "lmath/vec3.h"
#include "object.h"

namespace obj
{

struct Scene
{
    std::vector< std::shared_ptr< Object > > objects;
    lmath::Vec3 directionalLight{};
};

} // namespace obj
