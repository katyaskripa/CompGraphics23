#pragma once

#include "lmath/point3.h"
#include "lmath/vec3.h"
#include "render/ray.h"

namespace render
{
class Camera
{
public:
    Camera() = default;
    Camera( float fov, float aspectRatio );

    [[nodiscard]] Ray castRay( float u, float v ) const;

private:
    lmath::Point3 position_{};
    float fov_{ 90.0f };
    float aspectRatio_{ 1.0f };
};

} // namespace render
