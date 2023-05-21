#include <iostream>

#include "objects/disk.h"
#include "objects/sphere.h"
#include "render/renderer.h"

int main()
{
    render::Renderer renderer{ 90.0f, 150, 150 };
    auto& rendererScene{ renderer.getScene() };

    rendererScene.directionalLight = lmath::Vec3( 0.6f, -0.8f, 0.0f ).normalize();
    rendererScene.objects.emplace_back(
        std::make_shared< obj::Sphere >( 0.5f, lmath::Point3( 1.0f, 0.0f, -2.0f ) ) );
    rendererScene.objects.emplace_back(
        std::make_shared< obj::Sphere >( 0.5f, lmath::Point3( -1.0f, 0.0f, -3.0f ) ) );
    rendererScene.objects.emplace_back(
        std::make_shared< obj::Disk >( 0.5f,
                                       lmath::Normal{ 0.0f, 1.0f, 0.5f }.normalize(),
                                       lmath::Point3{ 0.0f, 0.0f, -2.0f } ) );

    renderer.render();
}
