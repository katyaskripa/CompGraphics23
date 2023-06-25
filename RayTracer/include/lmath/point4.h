#pragma once

namespace lmath
{

struct Point4
{
    float x;
    float y;
    float z;
    float w;

    explicit Point4( float x = 0 );
    Point4( float x, float y );
    Point4( float x, float y, float z );
    Point4( float x, float y, float z, float w );
};

} // namespace lmath