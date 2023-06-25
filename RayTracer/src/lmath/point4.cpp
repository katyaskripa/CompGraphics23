#include "lmath/point4.h"

namespace lmath
{

Point4::Point4( const float x ) : x{ x }, y{ x }, z{ x } { }

Point4::Point4( const float x, const float y ) : x{ x }, y{ y }, z{ 0 } { }

Point4::Point4( const float x, const float y, const float z ) : x{ x }, y{ y }, z{ z } { }

} // namespace lmath
