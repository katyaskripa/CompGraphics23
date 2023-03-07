#include "math/point3.h"

#include "math/vec3.h"

namespace math
{

Point3 Point3::operator+( const Vec3& v ) const
{
    return { x + v.x, y + v.y, z + v.z };
}

} // namespace math
