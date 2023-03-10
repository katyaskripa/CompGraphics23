#include "render/renderer.h"

#include <iostream>
#include <limits>

namespace render
{

Renderer::Renderer( const float fov,
                    const int imageWidth,
                    const int imageHeight,
                    const float nearClip,
                    const float farClip )
    : camera( fov, (float) imageWidth / (float) imageHeight )
    , imageWidth( imageWidth )
    , imageHeight( imageHeight )
    , nearClip( nearClip )
    , farClip( farClip )
{
}

obj::Scene& Renderer::getScene()
{
    return scene;
}

Camera& Renderer::getCamera()
{
    return camera;
}

const obj::Scene& Renderer::getScene() const
{
    return scene;
}

void Renderer::setScene( const obj::Scene& newScene )
{
    scene = newScene;
}

void Renderer::setCamera( const Camera& newCamera )
{
    camera = newCamera;
}

void Renderer::render() const
{
    std::cout << std::endl;

    for ( int y = 0; y < imageHeight; y++ )
    {
        for ( int x = 0; x < imageWidth; x++ )
        {
            const auto u{ rasterToWorldSpace( x, imageWidth ) };
            const auto v{ rasterToWorldSpace( y, imageWidth ) };

            std::cout << trace( u, v );
        }

        std::cout << std::endl;
    }
}

float Renderer::rasterToWorldSpace( int coord, int imageSize )
{
    const auto worldCoord{ (float) coord / (float) imageSize };
    return worldCoord * 2.0f - 1.0f;
}

std::string Renderer::trace( const float u, const float v ) const
{
    const auto ray{ camera.castRay( u, v ) };

    bool hasHit{ false };
    HitRecord closestHit;
    closestHit.distance = std::numeric_limits< float >::max();
    for ( const auto& object : scene.objects )
    {
        HitRecord hit;
        if ( object->hit( ray, nearClip, farClip, hit ) )
        {
            if ( !hasHit )
            {
                hasHit = true;
            }

            if ( hit.distance < closestHit.distance )
            {
                closestHit = hit;
            }
        }
    }

    if ( hasHit )
    {
        return calculateColor( closestHit );
    }

    return " ";
}

float Renderer::getLightingCoefficient( const lmath::Normal& normal ) const
{
    return normal.dotProduct( scene.directionalLight.normalize() );
}

std::string Renderer::calculateColor( const HitRecord& hit ) const
{
    const auto lightingCoefficient{ getLightingCoefficient( hit.normal ) };

    if ( lightingCoefficient > 0.8f )
    {
        return "\u2588"; // █
    }
    else if ( lightingCoefficient > 0.5f )
    {
        return "\u2593"; // ▓
    }
    else if ( lightingCoefficient > 0.2f )
    {
        return "\u2592"; // ▒
    }
    else if ( lightingCoefficient > 0.0f )
    {
        return "\u2591"; // ░
    }

    return " ";
}

} // namespace render
