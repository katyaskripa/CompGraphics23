#include <icl/bmp_reader.h>
#include <iostream>
#include <memory>

int main( int argc, char** argv )
{
    std::cout << "Image converter!\n";
    std::unique_ptr< icl::ImageReader > reader{ new icl::BmpImageReader{} };
    return 0;
}