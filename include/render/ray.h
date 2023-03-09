#pragma once

#include "lmath/point3.h"
#include "lmath/vec3.h"

namespace render
{

class Ray
{
public:
    Ray() = default;
    Ray( const lmath::Point3& origin, const lmath::Vec3& direction );

    [[nodiscard]] lmath::Point3 positionAt( float t ) const;

public:
    lmath::Point3 origin{};
    lmath::Vec3 direction{};
};

} // namespace render
