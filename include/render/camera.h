#pragma once

#include "lmath/point3.h"
#include "lmath/vec3.h"
#include "render/ray.h"

namespace render
{
class Camera
{
public:
    Camera( float fov, float aspectRatio );

    [[nodiscard]] Ray castRay( float u, float v ) const;

private:
    lmath::Point3 position{};
    float fov{ 90.0f };
    float aspectRatio;
};

} // namespace render
