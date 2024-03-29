#pragma once

#include <string>

#include "image.h"

namespace icl
{

class ImageWriter
{
public:
    virtual ~ImageWriter()                                             = default;
    virtual void WriteImageToFile( const std::shared_ptr< Image > image,
                                   const std::string& filepath ) const = 0;
};

} // namespace icl