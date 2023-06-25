#include "files/ObjReader.h"

#include <fstream>
#include <string>

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <fmtlog/fmtlog.h>
#include <utility>

#include "files/utils.h"

namespace files
{
ObjReader::ObjReader( std::string file_name ) : file_name_{ std::move( file_name ) }
{
    if ( !utils::checkIfFileExists( file_name_ ) )
    {
        throw std::runtime_error{ fmt::format( "Couldn't find obj file: {}", file_name_ ) };
    }
}

void ObjReader::read()
{
    indexes_.clear();
    vertexes_.clear();
    normals_.clear();
    line_elements_.clear();

    readVertexes();
    readNormals();
    readIndexes();
    readLineElements();
}

void ObjReader::readIndexes()
{
    std::ifstream open_file( file_name_ );
    std::string line;
    while ( getline( open_file, line ) )
    {
        if ( line.find( ' ' ) == std::string::npos )
        {
            continue;
        }

        if ( line.substr( 0, line.find( ' ' ) ) == "f" )
        {
            line = line.substr( line.find( ' ' ), line.size() - line.find( ' ' ) );

            while ( !line.empty()
                    && ( line.back() == '\n' || line.back() == '\r' || line.back() == ' ' ) )
            {
                line.pop_back();
            }
            const auto it{ std::find_if( line.begin(),
                                         line.end(),
                                         []( const char c )
                                         {
                                             return c != ' ';
                                         } ) };
            line = std::string{ it, line.end() };

            if ( line.find( "//" ) != std::string::npos )
            {
                std::vector< std::string > doubled_indexes;
                boost::split( doubled_indexes, line, boost::is_any_of( " " ) );

                std::vector< std::vector< std::uint32_t > > global_indexes;
                for ( const auto& item : doubled_indexes )
                {
                    std::vector< std::string > local_indexes;
                    std::vector< std::uint32_t > casted_local_indexes;
                    boost::split( local_indexes, item, boost::is_any_of( "//" ) );
                    for ( const auto& local_index : local_indexes )
                    {
                        if ( !local_index.empty() )
                        {
                            casted_local_indexes.emplace_back( std::stoi( local_index ) );
                        }
                    }
                    global_indexes.emplace_back( casted_local_indexes );
                }
                indexes_.emplace_back( global_indexes );
            }
            else if ( line.find( "/" ) != std::string::npos )
            {
                std::vector< std::string > tripled_indexes;
                boost::split( tripled_indexes, line, boost::is_any_of( " " ) );

                std::vector< std::vector< std::uint32_t > > global_indexes;
                for ( const auto& item : tripled_indexes )
                {
                    std::vector< std::string > local_indexes;
                    std::vector< std::uint32_t > casted_local_indexes;
                    boost::split( local_indexes, item, boost::is_any_of( "/" ) );
                    for ( const auto& local_index : local_indexes )
                    {
                        casted_local_indexes.emplace_back( std::stoi( local_index ) );
                    }
                    global_indexes.emplace_back( casted_local_indexes );
                }
                indexes_.emplace_back( global_indexes );
            }
            else
            {
                std::vector< std::string > indexes;
                boost::split( indexes, line, boost::is_any_of( " " ) );

                std::vector< std::vector< std::uint32_t > > global_indexes;
                for ( const auto& item : indexes )
                {
                    std::vector< std::uint32_t > casted_items_of_indexes;
                    casted_items_of_indexes.reserve( indexes.size() );
                    for ( const auto& index : indexes )
                    {
                        casted_items_of_indexes.push_back( std::stoi( index ) );
                    }
                    global_indexes.emplace_back( casted_items_of_indexes );
                }
                indexes_.emplace_back( global_indexes );
            }
        }
    }
}

void ObjReader::readNormals()
{
    std::ifstream open_file( file_name_ );
    std::string line;
    while ( getline( open_file, line ) )
    {
        if ( line.find( ' ' ) == std::string::npos )
        {
            continue;
        }

        if ( line.substr( 0, line.find( ' ' ) ) == "vn" )
        {
            line = line.substr( line.find( ' ' ), line.size() - line.find( ' ' ) );

            while ( !line.empty()
                    && ( line.back() == '\n' || line.back() == '\r' || line.back() == ' ' ) )
            {
                line.pop_back();
            }
            const auto it{ std::find_if( line.begin(),
                                         line.end(),
                                         []( const char c )
                                         {
                                             return c != ' ';
                                         } ) };
            line = std::string{ it, line.end() };

            lmath::Vec3 v3;

            std::vector< std::string > normals;
            boost::split( normals, line, boost::is_any_of( " " ) );
            v3.x = boost::lexical_cast< float >( normals[ 0 ] );
            v3.y = boost::lexical_cast< float >( normals[ 1 ] );
            v3.z = boost::lexical_cast< float >( normals[ 2 ] );

            normals_.emplace_back( v3 );
        }
    }
}

void ObjReader::readVertexes()
{
    std::ifstream open_file( file_name_ );
    std::string line;
    while ( getline( open_file, line ) )
    {
        if ( line.find( ' ' ) == std::string::npos )
        {
            continue;
        }

        if ( line.substr( 0, line.find( ' ' ) ) == "v" )
        {
            line = line.substr( line.find( ' ' ), line.size() - line.find( ' ' ) );

            while ( !line.empty()
                    && ( line.back() == '\n' || line.back() == '\r' || line.back() == ' ' ) )
            {
                line.pop_back();
            }
            const auto it{ std::find_if( line.begin(),
                                         line.end(),
                                         []( const char c )
                                         {
                                             return c != ' ';
                                         } ) };
            line = std::string{ it, line.end() };

            lmath::Point3 p3;

            std::vector< std::string > points;
            boost::split( points, line, boost::is_any_of( " " ) );
            p3.x = boost::lexical_cast< float >( points[ 0 ] );
            p3.y = boost::lexical_cast< float >( points[ 1 ] );
            p3.z = boost::lexical_cast< float >( points[ 2 ] );

            vertexes_.emplace_back( p3 );
        }
    }
}

void ObjReader::readLineElements()
{
    std::ifstream open_file( file_name_ );
    std::string line;
    while ( getline( open_file, line ) )
    {
        if ( line.find( ' ' ) == std::string::npos )
        {
            continue;
        }
        if ( line.substr( 0, line.find( ' ' ) ) == "l" )
        {
            line = line.substr( line.find( ' ' ), line.size() - line.find( ' ' ) );

            while ( !line.empty()
                    && ( line.back() == '\n' || line.back() == '\r' || line.back() == ' ' ) )
            {
                line.pop_back();
            }
            const auto it{ std::find_if( line.begin(),
                                         line.end(),
                                         []( const char c )
                                         {
                                             return c != ' ';
                                         } ) };
            line = std::string{ it, line.end() };

            std::vector< std::string > line_elements;
            boost::split( line_elements, line, boost::is_any_of( " " ) );
            for ( const auto& item : line_elements )
            {
                line_elements_.emplace_back( boost::lexical_cast< std::uint32_t >( item ) );
            }
        }
    }
}
std::vector< lmath::Point3 > ObjReader::getVertexes() const
{
    return vertexes_;
}
std::vector< lmath::Vec3 > ObjReader::getNormals() const
{
    return normals_;
}
std::vector< std::uint32_t > ObjReader::getLineElements() const
{
    return line_elements_;
}

std::vector< std::vector< std::vector< std::uint32_t > > > ObjReader::getIndexes() const
{
    return indexes_;
}

} // namespace files