#include <catch2/catch_test_macros.hpp>
  
#include <cmath>

#include "lmath.h"

// 2d vectors - - - - - - - - - - - - - - - - - - 

TEST_CASE( "Adding two 2d vectors", "[single-file]" )
{
    lmath::Vec2 v1{ 1, 3 }, v2{ 5, -9 };

    lmath::Vec2 result{};
    result = v1 + v2;

    REQUIRE( result.x == v1.x + v2.x );
    REQUIRE( result.y == v1.y + v2.y );
}

TEST_CASE( "Subtracting two 2d vectors", "[single-file]" )
{
    lmath::Vec2 v1{ 1, 3 }, v2{ 5, -9 };

    lmath::Vec2 result{};
    result = v1 - v2;

    REQUIRE( result.x == v1.x - v2.x );
    REQUIRE( result.y == v1.y - v2.y );
}

TEST_CASE( "Multiplication of 2d vector", "[single-file]" )
{
    lmath::Vec2 v1{ 1, 3 };
    float s = 1.45;

    lmath::Vec2 result{};
    result = v1 * s;

    REQUIRE( result.x == v1.x * s );
    REQUIRE( result.y == v1.y * s );
}

TEST_CASE( "Scale of 2d vector", "[single-file]" )
{
    lmath::Vec2 v1{ 1, 3 };
    float s = 1.45;

    lmath::Vec2 result{v1};
    result.scale(s);

    REQUIRE( result.x == v1.x * s );
    REQUIRE( result.y == v1.y * s );
}

TEST_CASE( "Dot product of 2d vectors", "[single-file]" )
{
    lmath::Vec2 v1{ 1, 3 }, v2{ 5, -9 };

    float result{};
    result = v1.dotProduct(v2);

    REQUIRE( result == v1.x * v2.x + v1.y * v2.y );
}

TEST_CASE( "Cross product of 2d vectors", "[single-file]" )
{
    lmath::Vec2 v1{ 1, 3 }, v2{ 5, -9 };

    float result{};
    result = v1.crossProduct(v2);

    REQUIRE( result == v1.x * v2.y - v1.y * v2.x );
}

TEST_CASE( "Get length of 2d vector", "[single-file]" )
{
    lmath::Vec2 v1{ 1, 3 };

    float result{};
    result = v1.getLength();

    REQUIRE( result == std::sqrt (v1.x * v1.x + v1.y * v1.y ) );
}

TEST_CASE( "Normalize the 2d vector", "[single-file]" )
{
    lmath::Vec2 v1{ 1, 3 };

    float result{};
    result = v1.getLength();

    REQUIRE( result == std::sqrt (v1.x * v1.x + v1.y * v1.y ) );
}

// 3d vectors - - - - - - - - - - - - - - - - - - 

TEST_CASE( "Adding two 3d vectors", "[single-file]" )
{
    lmath::Vec3 v1{ 1, 3, -4 }, v2{ 5, -9, 10 };

    lmath::Vec3 result{};
    result = v1 + v2;

    REQUIRE( result.x == v1.x + v2.x );
    REQUIRE( result.y == v1.y + v2.y );
    REQUIRE( result.z == v1.z + v2.z );
}

TEST_CASE( "Subtracting two 3d vectors", "[single-file]" )
{
    lmath::Vec3 v1{ 1, 3, -4 }, v2{ 5, -9, 10 };

    lmath::Vec3 result{};
    result = v1 - v2;

    REQUIRE( result.x == v1.x - v2.x );
    REQUIRE( result.y == v1.y - v2.y );
    REQUIRE( result.z == v1.z - v2.z );
}

TEST_CASE( "Multiplication of 3d vector", "[single-file]" )
{
    lmath::Vec3 v1{ 1, 3, -4 };
    float s = 1.45;

    lmath::Vec3 result{};
    result = v1 * s;

    REQUIRE( result.x == v1.x * s );
    REQUIRE( result.y == v1.y * s );
    REQUIRE( result.z == v1.z * s );
}

TEST_CASE( "Scale of 3d vector", "[single-file]" )
{
    lmath::Vec3 v1{ 1, 3, -4 };
    float s = 1.45;

    lmath::Vec3 result{v1};
    result.scale(s);

    REQUIRE( result.x == v1.x * s );
    REQUIRE( result.y == v1.y * s );
    REQUIRE( result.z == v1.z * s );
}

TEST_CASE( "Dot product of two 3d vectors", "[single-file]" )
{
    lmath::Vec3 v1{ 1, 3, -4 }, v2{ 5, -9, 10 };

    float result{};
    result = v1.dotProduct(v2);

    REQUIRE( result == v1.x * v2.x + v1.y * v2.y + v1.z * v2.z );
}

TEST_CASE( "Get length of 3d vector", "[single-file]" )
{
    lmath::Vec3 v1{ 1, 3 , -4 };

    float result{};
    result = v1.getLength();

    REQUIRE( result == std::sqrt (v1.x * v1.x + v1.y * v1.y + v1.z * v1.z ) );
}

TEST_CASE( "Normalize 3d vector", "[single-file]" )
{
    lmath::Vec3 v{ 1, 3 , -4 };
    
    const auto length{v.getLength()};
    lmath::Vec3 normalizedVec3Check{v.x / length, v.y / length, v.z / length};
    
    const auto normalizedVec3{v.normalize()};

    REQUIRE( normalizedVec3.x == normalizedVec3Check.x );
    REQUIRE( normalizedVec3.y == normalizedVec3Check.y );
    REQUIRE( normalizedVec3.z == normalizedVec3Check.z );
}

TEST_CASE( "Adding 2d point to 2d vec", "[single-file]" )
{
    lmath::Point2 p{ 1, 3 };
    lmath::Vec2 v{ 5, -9 };

    const auto result{ p + v };

    REQUIRE( result.x == p.x + v.x );
    REQUIRE( result.y == p.y + v.y );
}

// cross product for 3d vec :(

    // need to add tests for Point2, Point3