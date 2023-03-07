#include "math/point2.h"

#include "math/vec2.h"

namespace math
{

Point2 Point2::operator+( const Vec2& v ) const
{
    return { x + v.x, y + v.y };
}

} // namespace math
