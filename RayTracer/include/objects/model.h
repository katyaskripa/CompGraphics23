#pragma once

#include <vector>

#include "files/ObjReader.h"
#include "object.h"
#include "triangle.h"

namespace obj
{
struct Model : public Object
{
    std::vector< Triangle > triangles;

    explicit Model( const std::vector< Triangle >& triangles );

    Model( const std::vector< lmath::Point3 >& vertices,
           const std::vector< std::vector< std::vector< std::uint32_t > > >& indexes );

    explicit Model( const files::ObjReader& objReader );

    bool
    hit( const render::Ray& ray, float tmin, float tmax, render::HitRecord& hit ) const override;

    bool firstHit( const render::Ray& ray,
                   float tmin,
                   float tmax,
                   render::HitRecord& hit ) const override;

    [[nodiscard]] lmath::Normal getNormal( const lmath::Point3& p ) const override;

    void translate( const lmath::Vec3& translation ) override;

    void scale( const lmath::Vec3& scaling );

    void rotate( float angle, const lmath::Vec3& axis );
};
} // namespace obj