#include <catch2/catch_test_macros.hpp>

#include "objects/plane.h"
#include "render/ray.h"

TEST_CASE( "Intersection does not exist", "[single-file]" )
{
    render::Ray ray{ { 0, 0, 0 }, lmath::Vec3{ 0, -1, 0 }.normalize() };
    render::HitRecord hit;
    obj::Plane plane{ lmath::Vec3{ 0.0f, 0.0f, -2.0f }.normalize(),
                      lmath::Point3{ 0.0f, 1.0f, 1.0f } };

    REQUIRE( plane.hit( ray, 0.001f, 100.0f, hit ) == false );
}

TEST_CASE( "Intersection exists", "[single-file]" )
{
    render::Ray ray{ { 0, 0, 0 }, lmath::Vec3{ 0, -1, 0 }.normalize() };
    render::HitRecord hit;
    obj::Plane plane{ lmath::Vec3{ 0.0f, 1.0f, 1.0f }.normalize(),
                      lmath::Point3{ 0.0f, 1.0f, -2.0f } };

    REQUIRE( plane.hit( ray, 0.001f, 100.0f, hit ) == true );
}
