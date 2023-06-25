#pragma once

#include <vector>

#include "object.h"
#include "triangle.h"

namespace obj
{
struct Model : public Object
{
    std::vector< Triangle > triangles_;

    explicit Model( const std::vector< Triangle >& triangles );

    Model( const std::vector< lmath::Point3 >& vertices,
           const std::vector< std::vector< std::vector< std::uint32_t > > >& indexes );

    bool
    hit( const render::Ray& ray, float tmin, float tmax, render::HitRecord& hit ) const override;

    [[nodiscard]] lmath::Normal getNormal( const lmath::Point3& p ) const override;
};
} // namespace obj