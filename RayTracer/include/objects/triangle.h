#pragma once

#include "object.h"

namespace obj
{
struct Triangle : public Object
{
    lmath::Point3 v0, v1, v2;

    Triangle( const lmath::Point3& v0, const lmath::Point3& v1, const lmath::Point3& v2 );

    bool
    hit( const render::Ray& ray, float tmin, float tmax, render::HitRecord& hit ) const override;

    [[nodiscard]] lmath::Normal getNormal( const lmath::Point3& p ) const override;
};
} // namespace obj