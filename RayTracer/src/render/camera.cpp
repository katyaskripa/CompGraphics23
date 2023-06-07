#include "render/camera.h"

#include <cmath>

#include "lmath.h"

namespace render
{

Camera::Camera( const float fov, const float aspectRatio )
    : fov_{ fov }
    , aspectRatio_{ aspectRatio }
{
}

Ray Camera::castRay( const float u, const float v ) const
{
    const auto theta{ lmath::toRad( fov_ ) };
    const auto h{ std::tan( theta / 2 ) };
    const auto w{ h * aspectRatio_ };

    return { position_, lmath::Vec3{ u * w, v * h, -1.0f }.normalize() };
}

} // namespace render
