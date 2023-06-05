#include <filesystem>
#include <iostream>
#include <memory>
#include <string>

#include <boost/program_options.hpp>
#include <fmtlog/fmtlog.h>

#include "icl/bmp/bmp_reader.h"
#include "icl/bmp/bmp_writer.h"
#include "icl/ppm/ppm_reader.h"
#include "icl/ppm/ppm_writer.h"

namespace
{
constexpr auto kSource{ "source" };
constexpr auto kGoalFormat{ "goal-format" };
constexpr auto kOutput{ "output" };
} // namespace

bool checkIfFileExists( const std::string& file_name )
{
    const std::filesystem::path path_to_file_name{ file_name.c_str() };
    return std::filesystem::exists( path_to_file_name );
}

std::string getPathOfFile( const std::string& file_name )
{
    return file_name.substr( 0, file_name.rfind( '.' ) + 1 );
}

std::string getFileName( const std::string& file_name )
{
    const std::filesystem::path path_to_file_name{ file_name.c_str() };
    const auto file{ path_to_file_name.filename().string() };
    return file.substr( 0, file.rfind( '.' ) + 1 );
}

std::string getSeparator()
{
#ifdef _WIN32
    return "\\";
#endif
#if defined(__unix__) || defined(__unix) || \
    (defined(__APPLE__) && defined(__MACH__))
    return "/";
#endif
}

std::shared_ptr< boost::program_options::options_description >
program_options( const int argc,
                 const char**& argv,
                 std::string& source_file,
                 std::string& output_file,
                 std::string& goal_format,
                 bool& is_help )
{
    // clang-format off
    auto desc { std::make_shared<boost::program_options::options_description>( "Allowed options") };
    desc->add_options()
      ( kSource,
        boost::program_options::value< std::string >( &source_file ),
        "(required) input file path to convert" )
      ( kGoalFormat,
        boost::program_options::value< std::string >(&goal_format),
        "(required) output format, examples: bmp/ppm" )
      ( kOutput,
        boost::program_options::value< std::string >(&output_file),
        "(optional) location to output file" )
      ( "help, h",
        boost::program_options::bool_switch( &is_help ),
        "display a help dialog" );;
    // clang-format on
    boost::program_options::variables_map map_of_args;
    boost::program_options::store( boost::program_options::parse_command_line( argc, argv, *desc ),
                                   map_of_args );
    boost::program_options::notify( map_of_args );

    return desc;
}

int main( int argc, char** argv )
{
    std::string source_file, output_file, goal_format;
    bool is_help{};

    const auto desc{ program_options( argc,
                                      const_cast< const char**& >( argv ),
                                      source_file,
                                      output_file,
                                      goal_format,
                                      is_help ) };

    if ( is_help || source_file.empty() || goal_format.empty() )
    {
        std::cout << *desc << std::endl;
        return EXIT_SUCCESS;
    }

    if ( !checkIfFileExists( source_file ) )
    {
        loge( "Input file not found: {}", source_file );
        return EXIT_FAILURE;
    }

    icl::ImageFormat image_source_format{ source_file.substr(
        source_file.rfind( '.' ) + 1,
        source_file.size() - source_file.rfind( '.' ) - 1 ) };
    if ( image_source_format == icl::ImageFormat::kUndefined )
    {
        loge( "Unsupported input format" );
        return EXIT_FAILURE;
    }

    icl::ImageFormat image_goal_format{ goal_format };
    if ( image_goal_format == icl::ImageFormat::kUndefined )
    {
        loge( "Unsupported output format" );
        return EXIT_FAILURE;
    }

    std::unique_ptr< icl::ImageReader > reader;
    switch ( image_source_format )
    {
        case icl::ImageFormat::kPpm:
            reader = std::make_unique< icl::ppm::PpmImageReader >();
            break;
        case icl::ImageFormat::kBmp:
            reader = std::make_unique< icl::bmp::BmpImageReader >();
            break;
        default:
            loge( "Unknown input format" );
            return EXIT_FAILURE;
    }
    const auto image{ reader->ReadFromFile( source_file ) };

    if ( !image )
    {
        loge( "Image is not read properly. Cannot write" );
        return EXIT_FAILURE;
    }

    std::unique_ptr< icl::ImageWriter > writer;
    switch ( image_goal_format )
    {
        case icl::ImageFormat::kPpm:
            writer = std::make_unique< icl::ppm::PpmImageWriter >();
            break;
        case icl::ImageFormat::kBmp:
            writer = std::make_unique< icl::bmp::BmpImageWriter >();
            break;
        default:
            loge( "Unknown output format" );
            return EXIT_FAILURE;
    }
    if ( output_file.empty() )
    {
        output_file = getPathOfFile( source_file ) + image_goal_format.operator std::string();
    }
    else
    {
        output_file += getFileName( source_file ) + image_goal_format.operator std::string();
    }

    writer->WriteImageToFile( image, output_file );
    return EXIT_SUCCESS;
}