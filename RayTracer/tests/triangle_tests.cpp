#include <catch2/catch_test_macros.hpp>

#include "objects/triangle.h"
#include "render/ray.h"

TEST_CASE( "Intersection exists", "[single-file]" )
{
    render::Ray ray{ { 0, 0, 100 }, lmath::Vec3{ 0, 0, -1 }.normalize() };
    render::HitRecord hit;
    obj::Triangle sphere{ lmath::Point3{ -1.0f, -1.0f, 0.0f },
                          lmath::Point3{ 1.0f, -1.0f, 0.0f },
                          lmath::Point3{ 0.0f, 1.0f, 0.0f } };

    REQUIRE( sphere.hit( ray, 0.001f, 1000.0f, hit ) == true );
    REQUIRE( hit.distance == 100.0f );
}

TEST_CASE( "Intersection doesn't exist", "[single-file]" )
{
    render::Ray ray{ { 10, 0, 100 }, lmath::Vec3{ 0, 0, -1 }.normalize() };
    render::HitRecord hit;
    obj::Triangle sphere{ lmath::Point3{ -1.0f, -1.0f, 0.0f },
                          lmath::Point3{ 1.0f, -1.0f, 0.0f },
                          lmath::Point3{ 0.0f, 1.0f, 0.0f } };

    REQUIRE( sphere.hit( ray, 0.001f, 1000.0f, hit ) == false );
}