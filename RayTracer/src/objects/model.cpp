#include "objects/model.h"

namespace obj
{

Model::Model( const std::vector< lmath::Point3 >& vertices,
              const std::vector< std::uint32_t >& indexes )
{
    for ( uint32_t i{ 0 }; i < indexes.size(); i += 3 )
    {
        triangles_.emplace_back( vertices[ indexes[ i ] - 1 ],
                                 vertices[ indexes[ i + 1 ] - 1 ],
                                 vertices[ indexes[ i + 2 ] - 1 ] );
    }
}

bool Model::hit( const render::Ray& ray,
                 const float tmin,
                 const float tmax,
                 render::HitRecord& hit ) const
{
    return std::any_of( triangles_.begin(),
                        triangles_.end(),
                        [ & ]( const Triangle& triangle )
                        {
                            return triangle.hit( ray, tmin, tmax, hit );
                        } );
}

lmath::Normal Model::getNormal( const lmath::Point3& p ) const
{
    return lmath::Normal();
}

Model::Model( const std::vector< Triangle >& triangles ) : triangles_( triangles ) { }
} // namespace obj