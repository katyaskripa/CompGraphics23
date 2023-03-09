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
    lmath::Vec2 v{ 1, 3 };
    float s = 1.45;

    lmath::Vec2 result{};
    result = v * s;

    REQUIRE( result.x == v.x * s );
    REQUIRE( result.y == v.y * s );
}

TEST_CASE( "Scale of 2d vector", "[single-file]" )
{
    lmath::Vec2 v{ 1, 3 };
    float s = 1.45;

    lmath::Vec2 result{ v };
    result.scale( s );

    REQUIRE( result.x == v.x * s );
    REQUIRE( result.y == v.y * s );
}

TEST_CASE( "Dot product of 2d vectors", "[single-file]" )
{
    lmath::Vec2 v1{ 1, 3 }, v2{ 5, -9 };

    float result{};
    result = v1.dotProduct( v2 );

    REQUIRE( result == v1.x * v2.x + v1.y * v2.y );
}

TEST_CASE( "Cross product of 2d vectors", "[single-file]" )
{
    lmath::Vec2 v1{ 1, 3 }, v2{ 5, -9 };

    float result{};
    result = v1.crossProduct( v2 );

    REQUIRE( result == v1.x * v2.y - v1.y * v2.x );
}

TEST_CASE( "Get length of 2d vector", "[single-file]" )
{
    lmath::Vec2 v{ 1, 3 };

    float result{};
    result = v.getLength();

    REQUIRE( result == std::sqrt( v.x * v.x + v.y * v.y ) );
}

TEST_CASE( "Normalize the 2d vector", "[single-file]" )
{
    lmath::Vec2 v{ 1, 3 };

    const auto result{ v.getLength() };

    REQUIRE( result == std::sqrt( v.x * v.x + v.y * v.y ) );
}

// 3d vectors - - - - - - - - - - - - - - - - - -

TEST_CASE( "Adding two 3d vectors", "[single-file]" )
{
    lmath::Vec3 v1{ 1, 3, -4 }, v2{ 5, -9, 10 };

    lmath::Vec3 result{ v1 + v2 };

    REQUIRE( result.x == v1.x + v2.x );
    REQUIRE( result.y == v1.y + v2.y );
    REQUIRE( result.z == v1.z + v2.z );
}

TEST_CASE( "Subtracting two 3d vectors", "[single-file]" )
{
    lmath::Vec3 v1{ 1, 3, -4 }, v2{ 5, -9, 10 };

    lmath::Vec3 result{ v1 - v2 };

    REQUIRE( result.x == v1.x - v2.x );
    REQUIRE( result.y == v1.y - v2.y );
    REQUIRE( result.z == v1.z - v2.z );
}

TEST_CASE( "Multiplication of 3d vector", "[single-file]" )
{
    lmath::Vec3 v{ 1, 3, -4 };
    float s = 1.45;

    lmath::Vec3 result{ v * s };

    REQUIRE( result.x == v.x * s );
    REQUIRE( result.y == v.y * s );
    REQUIRE( result.z == v.z * s );
}

TEST_CASE( "Scale of 3d vector", "[single-file]" )
{
    lmath::Vec3 v{ 1, 3, -4 };
    float s = 1.45;

    lmath::Vec3 result{ v };
    result.scale( s );

    REQUIRE( result.x == v.x * s );
    REQUIRE( result.y == v.y * s );
    REQUIRE( result.z == v.z * s );
}

TEST_CASE( "Dot product of two 3d vectors", "[single-file]" )
{
    lmath::Vec3 v1{ 1, 3, -4 }, v2{ 5, -9, 10 };

    const auto result{ v1.dotProduct( v2 ) };

    REQUIRE( result == v1.x * v2.x + v1.y * v2.y + v1.z * v2.z );
}

TEST_CASE( "Get length of 3d vector", "[single-file]" )
{
    lmath::Vec3 v{ 1, 3, -4 };

    const auto result{ v.getLength() };

    REQUIRE( result == std::sqrt( v.x * v.x + v.y * v.y + v.z * v.z ) );
}

TEST_CASE( "Normalize 3d vector", "[single-file]" )
{
    lmath::Vec3 v{ 1, 3, -4 };

    const auto length{ v.getLength() };
    lmath::Vec3 normalizedVec3Check{ v.x / length, v.y / length, v.z / length };

    const auto normalizedVec3{ v.normalize() };

    REQUIRE( normalizedVec3.x == normalizedVec3Check.x );
    REQUIRE( normalizedVec3.y == normalizedVec3Check.y );
    REQUIRE( normalizedVec3.z == normalizedVec3Check.z );
}

// 2d points - - - - - - - - - - - - - - - - - -

TEST_CASE( "Adding 2d vec to 2d vec", "[single-file]" )
{
    lmath::Vec2 v1{ 1, 3 };
    lmath::Vec2 v2{ 5, -9 };

    const auto result{ v1 + v2 };

    REQUIRE( result.x == v1.x + v2.x );
    REQUIRE( result.y == v1.y + v2.y );
}

TEST_CASE( "Adding 2d point to 3d point", "[single-file]" )
{
    lmath::Vec2 v1{ 1, 3 };
    lmath::Vec3 v2{ 5, -9, 10 };

    const auto result{ v1 + v2 };

    REQUIRE( result.x == v1.x + v2.x );
    REQUIRE( result.y == v1.y + v2.y );
    REQUIRE( result.z == v2.z );
}

TEST_CASE( "Adding 2d point to 2d point", "[single-file]" )
{
    lmath::Point2 p1{ 5, -3 };
    lmath::Point2 p2{ 7, -1 };

    const auto result{ p1 - p2 };

    REQUIRE( result.x == p1.x - p2.x );
    REQUIRE( result.y == p1.y - p2.y );
}

TEST_CASE( "Subtracting 2d points", "[single-file]" )
{
    lmath::Vec2 v1{ 1, 3 };
    lmath::Vec2 v2{ 5, -9 };

    const auto result{ v1 - v2 };

    REQUIRE( result.x == v1.x - v2.x );
    REQUIRE( result.y == v1.y - v2.y );
}

TEST_CASE( "Subtracting 2d point from a point", "[single-file]" )
{
    lmath::Point2 p1{ 5, -3 };
    lmath::Point2 p2{ 7, -1 };

    const auto result{ p1 - p2 };

    REQUIRE( result.x == p1.x - p2.x );
    REQUIRE( result.y == p1.y - p2.y );
}

// point2.cpp 40-43

// cross product for 3d vec :(

// 3d points - - - - - - - - - - - - - - - - - -

TEST_CASE( "Adding 3point to 3point in vector dimension", "[single-file]" )
{
    lmath::Vec3 v1{ 1, 3, -8 };
    lmath::Vec3 v2{ 5, -9, 10 };

    const auto result{ v1.operator+( v2 ) };

    REQUIRE( result.x == v1.x + v2.x );
    REQUIRE( result.y == v1.y + v2.y );
    REQUIRE( result.z == v1.z + v2.z );
}

TEST_CASE( "Subtracting 3point from 3point in vector dimension", "[single-file]" )
{
    lmath::Vec3 v1{ 1, 3, -8 };
    lmath::Vec3 v2{ 5, -9, 10 };

    const auto result{ v1 - v2 };

    REQUIRE( result.x == v1.x - v2.x );
    REQUIRE( result.y == v1.y - v2.y );
    REQUIRE( result.z == v1.z - v2.z );
}

TEST_CASE( "Adding 3point to 3point in another vector dimension", "[single-file]" )
{
    lmath::Vec3 v1{ 1, 3, -8 };
    lmath::Vec2 v2{ 5, -9 };

    const auto result{ v1 + v2 };

    REQUIRE( result.x == v1.x + v2.x );
    REQUIRE( result.y == v1.y + v2.y );
    REQUIRE( result.z == v1.z );
}

TEST_CASE( "Subtracting 3point from 3point in another vector dimension", "[single-file]" )
{
    lmath::Vec3 v1{ 1, 3, -8 };
    lmath::Vec2 v2{ 5, -9 };

    const auto result{ v1 - v2 };

    REQUIRE( result.x == v1.x - v2.x );
    REQUIRE( result.y == v1.y - v2.y );
    REQUIRE( result.z == v1.z );
}

TEST_CASE( "Adding 3point to 3point", "[single-file]" )
{
    lmath::Point3 p1{ 1, 3, -8 };
    lmath::Point3 p2{ 5, -9, 10 };

    const auto result{ p1 + p2 };

    REQUIRE( result.x == p1.x + p2.x );
    REQUIRE( result.y == p1.y + p2.y );
    REQUIRE( result.z == p1.z + p2.z );
}

TEST_CASE( "Subtracting 3point from 3point", "[single-file]" )
{
    lmath::Point3 p1{ 1, 3, -8 };
    lmath::Point3 p2{ 5, -9, 10 };

    const auto result{ p1 - p2 };

    REQUIRE( result.x == p1.x - p2.x );
    REQUIRE( result.y == p1.y - p2.y );
    REQUIRE( result.z == p1.z - p2.z );
}

TEST_CASE( "Adding 2d and 3d points", "[single-file]" )
{
    lmath::Point2 p1{ 1, 3 };
    lmath::Point3 p2{ 5, -9, 10 };

    const auto result{ p1 + p2 };

    REQUIRE( result.x == p1.x + p2.x );
    REQUIRE( result.y == p1.y + p2.y );
    REQUIRE( result.z == p2.z );
}