#include <iostream>

#include "objects/disk.h"
#include "objects/sphere.h"
#include "render/renderer.h"

int main()
{
    render::Renderer renderer{ 90.0f, 150, 150 };
    renderer.getScene().directionalLight = lmath::Vec3( 0.6f, -0.8f, 0.0f ).normalize();
    renderer.getScene().objects.push_back(
        std::make_shared< obj::Sphere >( 0.5f, lmath::Point3( 1.0f, 0.0f, -2.0f ) ) );
    renderer.getScene().objects.push_back(
        std::make_shared< obj::Sphere >( 0.5f, lmath::Point3( -1.0f, 0.0f, -3.0f ) ) );
    renderer.getScene().objects.push_back(
        std::make_shared< obj::Disk >( 0.5f,
                                       lmath::Normal( 0.0f, 1.0f, 0.5f ).normalize(),
                                       lmath::Point3( 0.0f, 0.0f, -2.0f ) ) );

    renderer.render();
}
