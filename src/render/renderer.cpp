#include "render/renderer.h"

#include <iostream>
#include <limits>

namespace render
{

Renderer::Renderer( const float fov,
                    const std::size_t imageWidth,
                    const std::size_t imageHeight,
                    const float nearClip,
                    const float farClip )
    : camera_{ fov, (float) imageWidth / (float) imageHeight }
    , imageWidth_{ imageWidth }
    , imageHeight_{ imageHeight }
    , nearClip_{ nearClip }
    , farClip_{ farClip }
{
}

obj::Scene& Renderer::getScene()
{
    return scene_;
}

Camera& Renderer::getCamera()
{
    return camera_;
}

const obj::Scene& Renderer::getScene() const
{
    return scene_;
}

void Renderer::setScene( const obj::Scene& newScene )
{
    scene_ = newScene;
}

void Renderer::setCamera( const Camera& newCamera )
{
    camera_ = newCamera;
}

void Renderer::render() const
{
    std::cout << '\n';

    for ( std::size_t y{ 0 }; y < imageHeight_; ++y )
    {
        for ( std::size_t x{ 0 }; x < imageWidth_; ++x )
        {
            const auto u{ rasterToWorldSpace( x, imageWidth_ ) };
            const auto v{ rasterToWorldSpace( y, imageHeight_ ) };

            std::cout << trace( u, v );
        }

        std::cout << std::endl;
    }
}

float Renderer::rasterToWorldSpace( std::size_t coord, std::size_t imageSize )
{
    const auto worldCoord{ (float) coord / (float) imageSize };
    return worldCoord * 2.0f - 1.0f;
}

std::string Renderer::trace( const float u, const float v ) const
{
    const auto ray{ camera_.castRay( u, v ) };

    bool hasHit{};
    HitRecord closestHit;
    closestHit.distance = std::numeric_limits< float >::max();
    for ( const auto& object : scene_.objects )
    {
        HitRecord hit;
        if ( object->hit( ray, nearClip_, farClip_, hit ) )
        {
            hasHit = true;

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
    return normal.dotProduct( scene_.directionalLight.normalize() );
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
