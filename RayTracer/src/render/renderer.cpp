#include "render/renderer.h"

#include <iostream>
#include <limits>
#include <utility>

namespace render
{
Renderer::Renderer( const float fov,
                    const std::shared_ptr< icl::Image >& image,
                    const float nearClip,
                    const float farClip )
    : camera_{ fov, (float) image->getWidth() / (float) image->getHeight() }
    , image_{ image }
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

    const auto image_width{ image_->getWidth() };
    const auto image_height{ image_->getHeight() };
    for ( std::int32_t y{ 0 }; y < image_height; ++y )
    {
        for ( std::int32_t x{ 0 }; x < image_width; ++x )
        {
            const auto u{ rasterToWorldSpace( x, image_width ) };
            const auto v{ rasterToWorldSpace( y, image_height ) };

            image_->insertPixel( trace( u, v ) );
        }
    }
}

float Renderer::rasterToWorldSpace( std::size_t coord, std::size_t imageSize )
{
    const auto worldCoord{ (float) coord / (float) imageSize };
    return worldCoord * 2.0f - 1.0f;
}

icl::Pixel Renderer::trace( const float u, const float v ) const
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

    return { 0, 0, 0 };
}

float Renderer::getLightingCoefficient( const lmath::Normal& normal ) const
{
    return normal.dotProduct( scene_.directionalLight.normalize() );
}

icl::Pixel Renderer::calculateColor( const HitRecord& hit ) const
{
    const auto lighting_coefficient{ getLightingCoefficient( hit.normal ) };
    const auto color_value{ static_cast< std::uint8_t >( 255 * lighting_coefficient ) };
    return icl::Pixel{ color_value, color_value, color_value };
}

} // namespace render
