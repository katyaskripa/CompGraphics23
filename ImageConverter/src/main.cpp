#include <iostream>
#include <memory>
#include <string>

#include <boost/program_options.hpp>
#include <fmtlog/fmtlog.h>

#include <icl/bmp_reader.h>
#include <icl/ppm_reader.h>

namespace
{
constexpr auto kSource{ "source" };
constexpr auto kGoalFormat{ "goal-format" };
constexpr auto kOutput{ "output" };
} // namespace

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
        boost::program_options::value< std::string >(),
        "(required) output format, examples: bmp/ppm" )
      ( kOutput,
        boost::program_options::value< std::string >(),
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

    icl::ImageFormat image_source_format{ source_file.substr( source_file.rfind( '.' ),
                                                              source_file.size()
                                                                  - source_file.rfind( '.' ) ) };
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
            reader = std::make_unique< icl::PpmImageReader >();
            break;
        case icl::ImageFormat::kBmp:
            reader = std::make_unique< icl::BmpImageReader >();
            break;
        default:
            loge( "Unknown input format" );
            return EXIT_FAILURE;
    }

    reader->ReadFromFile( source_file );

    // writer here
    switch ( image_goal_format )
    {
        case icl::ImageFormat::kPpm:

            break;
        case icl::ImageFormat::kBmp:
            break;
        default:
            loge( "Unknown output format" );
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}