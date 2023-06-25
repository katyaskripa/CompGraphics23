#include "lmath/matrix.h"

#include <cmath>

namespace lmath
{
Matrix4::Matrix4( const float diagonal_element )
{
    for ( int k = 0; k < 4; ++k )
    {
        data_[ k + k ] = diagonal_element;
    }
}

Matrix4& Matrix4::multiply( const Matrix4& other )
{
    std::array< float, 16 > C;

    for ( int k = 0; k < 4; ++k )
    {
        for ( int j = 0; j < 4; ++j )
        {
            C[ k * 4 + j ] = data_[ 0 * 4 + j ] * other.data_[ k * 4 + 0 ]
                + data_[ 1 * 4 + j ] * other.data_[ k * 4 + 1 ]
                + data_[ 2 * 4 + j ] * other.data_[ k * 4 + 2 ]
                + data_[ 3 * 4 + j ] * other.data_[ k * 4 + 3 ];
        }
    }
    data_ = C;

    return *this;
}

Matrix4& Matrix4::translate( const Vec3& v )
{
    float x = v.x;
    float y = v.y;
    float z = v.z;

    Matrix4 trans_matrix;
    trans_matrix.data_ = { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
                           0.0f, 0.0f, 1.0f, 0.0f, x,    y,    z,    1.0f };

    return multiply( trans_matrix );
}

Matrix4& Matrix4::rotate( float angle, const Vec3& v )
{
    float c = std::cos( angle );
    float s = std::sin( angle );

    Matrix4 rotation_matrix;
    rotation_matrix.data_ = { v.x * v.x * ( 1.0f - c ) + c,
                              v.x * v.y * ( 1.0f - c ) - v.z * s,
                              v.x * v.z * ( 1.0f - c ) + v.y * s,
                              0.0f,
                              v.y * v.x * ( 1.0f - c ) + v.z * s,
                              v.y * v.y * ( 1.0f - c ) + c,
                              v.y * v.z * ( 1.0f - c ) - v.x * s,
                              0.0f,
                              v.z * v.x * ( 1.0f - c ) - v.y * s,
                              v.z * v.y * ( 1.0f - c ) + v.x * s,
                              v.z * v.z * ( 1.0f - c ) + c,
                              0.0f,
                              0.0f,
                              0.0f,
                              0.0f,
                              1.0f };

    return multiply( rotation_matrix );
}

Matrix4& Matrix4::scale( const Vec3& v )
{
    Matrix4 scaleMat;
    scaleMat.data_ = { v.x,  0.0f, 0.0f, 0.0f, 0.0f, v.y,  0.0f, 0.0f,
                       0.0f, 0.0f, v.z,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f };

    return multiply( scaleMat );
}
std::array< float, 16 > Matrix4::getData() const
{
    return data_;
}
} // namespace lmath