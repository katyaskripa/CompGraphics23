#pragma once

#include "object.h"

namespace obj
{
struct Triangle : public Object
{
    lmath::Point3 v0, v1, v2;
    bool clockwise;

    Triangle( const lmath::Point3& v0,
              const lmath::Point3& v1,
              const lmath::Point3& v2,
              bool clockwise = false );

    bool
    hit( const render::Ray& ray, float tmin, float tmax, render::HitRecord& hit ) const override;

    bool firstHit( const render::Ray& ray,
                   float tmin,
                   float tmax,
                   render::HitRecord& hit ) const override;

    [[nodiscard]] lmath::Normal getNormal( const lmath::Point3& p ) const override;

    void translate( const lmath::Vec3& translation ) override;
};
} // namespace obj