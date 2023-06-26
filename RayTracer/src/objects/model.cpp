#include "objects/model.h"

namespace obj
{

Model::Model( const std::vector< lmath::Point3 >& vertices,
              const std::vector< std::vector< std::vector< std::uint32_t > > >& indexes )
{
    for ( uint32_t i{ 0 }; i < indexes.size(); i += 3 )
    {
        triangles.emplace_back( vertices[ indexes[ i ][ 0 ][ 0 ] - 1 ],
                                vertices[ indexes[ i ][ 1 ][ 0 ] - 1 ],
                                vertices[ indexes[ i ][ 2 ][ 0 ] - 1 ] );
    }
}

bool Model::hit( const render::Ray& ray,
                 const float tmin,
                 const float tmax,
                 render::HitRecord& hit ) const
{
    bool hasHit{};
    hit.distance = std::numeric_limits< float >::max();
    for ( const auto& triangle : triangles )
    {
        render::HitRecord temp;
        if ( triangle.hit( ray, tmin, tmax, temp ) )
        {
            hasHit = true;

            if ( temp.distance < hit.distance )
            {
                hit = temp;
            }
        }
    }
    return hasHit;
}

lmath::Normal Model::getNormal( const lmath::Point3& p ) const
{
    return lmath::Normal();
}

Model::Model( const std::vector< Triangle >& triangles ) : triangles( triangles ) { }

void Model::translate( const lmath::Vec3& translation )
{
    for ( auto& triangle : triangles )
    {
        triangle.translate( translation );
    }
}

Model::Model( const files::ObjReader& objReader )
    : Model( objReader.getVertexes(), objReader.getIndexes() )
{
}

bool Model::firstHit( const render::Ray& ray, float tmin, float tmax, render::HitRecord& hit ) const
{
    return std::any_of( triangles.begin(),
                        triangles.end(),
                        [ & ]( const Triangle& triangle )
                        {
                            return triangle.hit( ray, tmin, tmax, hit );
                        } );
}

} // namespace obj