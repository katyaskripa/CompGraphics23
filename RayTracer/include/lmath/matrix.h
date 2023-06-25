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
    explicit Matrix4( const float diagonal_element = 1.0f );
    [[nodiscard]] Matrix4& translate( const Vec3& translation );
    [[nodiscard]] Matrix4& scale( const Vec3& v );
    [[nodiscard]] Matrix4& rotate( float angle, const Vec3& axis );
    [[nodiscard]] Matrix4& multiply( const Matrix4& other );
    [[nodiscard]] std::array< float, 16 > getData() const;

private:
    std::array< float, 16 > data_;
};
} // namespace lmath