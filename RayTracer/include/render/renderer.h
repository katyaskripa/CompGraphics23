#pragma once

#include <memory>
#include <string>

#include <icl/image.h>

#include "camera.h"
#include "objects/scene.h"

namespace render
{

class Renderer
{
public:
    Renderer( float fov,
              const std::shared_ptr< icl::Image >& image,
              float nearClip = 0.001f,
              float farClip  = 100.0f );

    [[nodiscard]] obj::Scene& getScene();
    [[nodiscard]] Camera& getCamera();
    [[nodiscard]] const obj::Scene& getScene() const;

    void setScene( const obj::Scene& newScene );
    void setCamera( const Camera& newCamera );
    void enableLighting( bool toggle );

    void render() const;

private:
    Camera camera_;
    obj::Scene scene_{};

    std::shared_ptr< icl::Image > image_;

    float nearClip_;
    float farClip_;

    bool lightingTurnedOff_{};

    [[nodiscard]] static float rasterToWorldSpace( std::size_t coord, std::size_t imageSize );

    [[nodiscard]] icl::Pixel trace( float u, float v ) const;
    [[nodiscard]] float getLightingCoefficient( const lmath::Normal& normal ) const;
    [[nodiscard]] icl::Pixel calculateColor( const HitRecord& hit ) const;
};

} // namespace render
