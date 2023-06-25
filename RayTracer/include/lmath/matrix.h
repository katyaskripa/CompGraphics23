#pragma once

#include <array>
#include <cstdint>
#include <utility>

#include "lmath/vec3.h"

namespace lmath
{

class Matrix4
{
public:
    Matrix4() = default;
    Matrix4( const float diagonal_element = 1.0f );
    Matrix4& translate( const Vec3& translation );
    Matrix4& scale( const Vec3& v );
    Matrix4& rotate( float angle, const Vec3& axis );
    Matrix4& multiply( const Matrix4& other );

private:
    std::array< float, 16 > data_;
};
} // namespace lmath