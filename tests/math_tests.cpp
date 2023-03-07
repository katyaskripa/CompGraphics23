#include <catch2/catch_test_macros.hpp>

#include "lmath.h"

TEST_CASE( "Adding two vectors", "[single-file]" )
{
    lmath::Vec2 v1{ 1, 3 }, v2{ 5, -9 };

    lmath::Vec2 result{};
    result = v1 + v2;

    REQUIRE( result.x == v1.x + v2.x );
    REQUIRE( result.y == v1.y + v2.y );
}

TEST_CASE( "Subtracting two vectors", "[single-file]" )
{
    lmath::Vec2 v1{ 1, 3 }, v2{ 5, -9 };

    lmath::Vec2 result{};
    result = v1 - v2;

    REQUIRE( result.x == v1.x - v2.x );
    REQUIRE( result.y == v1.y - v2.y );
}
