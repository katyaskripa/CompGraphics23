#include <iostream>

#include <boost/algorithm/string.hpp>
#include <boost/program_options.hpp>
#include <fmtlog/fmtlog.h>

#include <icl/bmp/bmp_image.h>
#include <icl/bmp/bmp_writer.h>
#include <icl/image.h>
#include <icl/ppm/ppm_image.h>
#include <icl/ppm/ppm_writer.h>

#include "files/ObjReader.h"
#include "files/utils.h"
#include "objects/model.h"
#include "objects/sphere.h"
#include "render/renderer.h"

namespace
{
constexpr auto kSource{ "source" };
constexpr auto kOutput{ "output" };
constexpr auto kObjFileExtension{ "obj" };

std::shared_ptr< boost::program_options::options_description >
program_options( const int argc,
                 const char**& argv,
                 std::string& source_file,
                 std::string& output_file,
                 bool& is_help )
{
    // clang-format off
    auto desc { std::make_shared<boost::program_options::options_description>( "RayTracer usage") };
    desc->add_options()
      ( kSource,
        boost::program_options::value< std::string >( &source_file ),
        "(required) input Wavefront OBJ file" )
      ( kOutput,
        boost::program_options::value< std::string >(&output_file),
        "(required) location to output file" )
      ( "help, h",
        boost::program_options::bool_switch( &is_help ),
        "display a help dialog" );
    // clang-format on
    boost::program_options::variables_map map_of_args;
    boost::program_options::store( boost::program_options::parse_command_line( argc, argv, *desc ),
                                   map_of_args );
    boost::program_options::notify( map_of_args );

    return desc;
}

} // namespace

int main( int argc, char** argv )
{
    std::string source_file, output_file;
    bool is_help{};

    const auto desc{ program_options( argc,
                                      const_cast< const char**& >( argv ),
                                      source_file,
                                      output_file,
                                      is_help ) };

    if ( is_help || source_file.empty() || output_file.empty() )
    {
        std::cout << *desc << std::endl;
        return EXIT_SUCCESS;
    }

    const auto source_file_extension{ files::utils::getExtension( source_file ) };
    if ( !boost::iequals( source_file_extension, kObjFileExtension ) )
    {
        loge( "Unsupported input format! Only Wavefront OBJ are supported." );
        return EXIT_FAILURE;
    }

    if ( !files::utils::checkIfFileExists( source_file ) )
    {
        loge( "Input file not found: {}", source_file );
        return EXIT_FAILURE;
    }

    files::ObjReader objReader( source_file );
    objReader.read();

    icl::ImageFormat image_output_format{ files::utils::getExtension( output_file ) };
    if ( image_output_format == icl::ImageFormat::kUndefined )
    {
        loge( "Unsupported image output format! RayTracer support only PPM and BMP images." );
        return EXIT_FAILURE;
    }

    std::unique_ptr< icl::ImageWriter > image_writer;
    std::shared_ptr< icl::Image > output_image;
    switch ( image_output_format )
    {
        case icl::ImageFormat::kPpm:
            image_writer = std::make_unique< icl::ppm::PpmImageWriter >();
            output_image = std::make_shared< icl::ppm::PpmImage >();
            break;
        case icl::ImageFormat::kBmp:
            image_writer = std::make_unique< icl::bmp::BmpImageWriter >();
            output_image = std::make_shared< icl::bmp::BmpImage >();
            break;
        default:
            loge( "Unknown output format" );
            return EXIT_FAILURE;
    }

    output_image->setWidth( 640 );
    output_image->setHeight( 360 );

    render::Renderer renderer{ 60.0f, output_image };
    auto& rendererScene{ renderer.getScene() };

    rendererScene.directionalLight = lmath::Vec3( 0.7f, 0.0f, 0.8f ).normalize();
    rendererScene.objects.emplace_back(
        std::make_shared< obj::Sphere >( 0.5f, lmath::Point3( 1.5f, 0.0f, -2.5f ) ) );

    auto model = std::make_shared< obj::Model >( objReader );
    model->rotate( 0.8f, { 0, 1, 0 } );
    model->translate( { -0.1f, -0.3f, -3.5f } );
    rendererScene.objects.emplace_back( model );

    renderer.render();
    image_writer->WriteImageToFile( output_image, output_file );

    return EXIT_SUCCESS;
}
