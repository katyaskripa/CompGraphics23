#pragma once

#include <string>

#include "camera.h"
#include "objects/scene.h"

namespace render
{

class Renderer
{
public:
    Renderer( float fov,
              int imageWidth,
              int imageHeight,
              float nearClip = 0.001f,
              float farClip  = 100.0f );

    [[nodiscard]] obj::Scene& getScene();
    [[nodiscard]] Camera& getCamera();
    [[nodiscard]] const obj::Scene& getScene() const;

    void setScene( const obj::Scene& newScene );
    void setCamera( const Camera& newCamera );

    void render() const;

private:
    Camera camera;
    obj::Scene scene{};

    int imageWidth;
    int imageHeight;

    float nearClip;
    float farClip;

private:
    [[nodiscard]] static float rasterToWorldSpace( int coord, int imageSize );

    [[nodiscard]] std::string trace( float u, float v ) const;
    [[nodiscard]] float getLightingCoefficient( const lmath::Normal& normal ) const;
    [[nodiscard]] std::string calculateColor( const HitRecord& hit ) const;
};

} // namespace render
