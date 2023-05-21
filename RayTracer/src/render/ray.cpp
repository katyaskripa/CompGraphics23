#include "render/ray.h"

namespace render
{

Ray::Ray( const lmath::Point3& origin, const lmath::Vec3& direction )
    : origin( origin )
    , direction( direction )
{
}

lmath::Point3 Ray::positionAt( const float t ) const
{
    return origin + ( direction * t );
}

} // namespace render
