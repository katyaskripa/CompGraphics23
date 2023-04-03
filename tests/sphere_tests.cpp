#include <catch2/catch_test_macros.hpp>

#include "objects/sphere.h"
#include "render/ray.h"

TEST_CASE( "Intersection does not exist", "[single-file]" )
{
    render::Ray ray{ { 0, 0, 0 }, lmath::Vec3{ 2, 1, 4 }.normalize() };
    render::HitRecord hit;
    obj::Sphere sphere{ 3.0f, lmath::Point3{ 3.0f, 3.0f, 1.0f } };

    REQUIRE( sphere.hit( ray, 0.001f, 100.0f, hit ) == false );
}

TEST_CASE( "Intersection exists", "[single-file]" )
{
    render::Ray ray{ { 0, 0, 0 }, lmath::Vec3{ 5, 1, 0 }.normalize() };
    render::HitRecord hit;
    obj::Sphere sphere{ 3.0f, lmath::Point3{ 3.0f, 3.0f, 1.0f } };

    REQUIRE( sphere.hit( ray, 0.001f, 100.0f, hit ) == true );
}

TEST_CASE( "Intersection exists. Check also for closest intersection", "[single-file]" )
{
    render::Ray ray{ { 0, 0, 0 }, lmath::Vec3{ 5, 1, 0 }.normalize() };
    render::HitRecord hit;
    obj::Sphere sphere{ 3.0f, lmath::Point3{ 3.0f, 3.0f, 1.0f } };

    REQUIRE( sphere.hit( ray, 0.001f, 100.0f, hit ) == true );

    const lmath::Point3 result_to_check{ 1.92307723, 0.384615421, 0 };
    const float distance_to_check{ 1.96116161 };

    REQUIRE( hit.intersection.x == result_to_check.x );
    REQUIRE( hit.intersection.y == result_to_check.y );
    REQUIRE( hit.intersection.z == result_to_check.z );
    REQUIRE( hit.distance == distance_to_check );
}
