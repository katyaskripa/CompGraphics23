#pragma once

#include <memory>

#include "image_reader.h"
#include "image_writer.h"

namespace icl
{

class ImageIOFactory
{
public:
    virtual std::unique_ptr< ImageReader > CreateImageReader() const = 0;
    virtual std::unique_ptr< ImageWriter > CreateImageWriter() const = 0;
};

} // namespace icl