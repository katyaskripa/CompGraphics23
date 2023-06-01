#pragma once

#include "icl/image_writer.h"

namespace icl::ppm
{
class PpmImageWriter : public ImageWriter
{
public:
    void WriteImageToFile( const std::shared_ptr< Image > image,
                           const std::string& filepath ) const override;
};
} // namespace icl::ppm