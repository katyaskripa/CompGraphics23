#include "render/hit_record.h"

namespace render
{

void HitRecord::setNormal( const Ray& ray, const lmath::Normal& n )
{
    bool frontFace{ ray.direction.dotProduct( n ) < 0.0f };
    normal = frontFace ? n : n.neg();
}

} // namespace render
