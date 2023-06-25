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
    readVertexes();
    readNormals();
    readIndexes();
}

void ObjReader::readIndexes()
{
    doubled_indexes_.clear();

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

                for ( const auto& item : doubled_indexes )
                {
                    doubled_indexes_.emplace_back(
                        std::stoi( item.substr( 0, item.find( "//" ) ) ),
                        std::stoi( item.substr( item.find( "//" ) + 2,
                                                item.size() - item.find( "//" ) - 2 ) ) );
                }
            }
            else if ( line.find( "/" ) != std::string::npos )
            {
                std::vector< std::string > tripled_indexes;
                boost::split( tripled_indexes, line, boost::is_any_of( " " ) );

                for ( const auto& item : tripled_indexes )
                {
                    std::vector< std::string > splitted_indexes;
                    boost::split( splitted_indexes, item, boost::is_any_of( "/" ) );
                    tripled_indexes_.emplace_back( std::stoi( splitted_indexes[ 0 ] ),
                                                   std::stoi( splitted_indexes[ 1 ] ),
                                                   std::stoi( splitted_indexes[ 2 ] ) );
                }
            }
            else
            {
                std::vector< std::string > indexes;
                boost::split( indexes, line, boost::is_any_of( " " ) );

                for ( const auto& item : indexes )
                {
                    std::vector< std::uint32_t > casted_items_of_indexes;
                    casted_items_of_indexes.reserve( indexes.size() );
                    for ( const auto& index : indexes )
                    {
                        casted_items_of_indexes.push_back( std::stoi( index ) );
                    }
                    indexes_.emplace_back( casted_items_of_indexes );
                }
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
std::vector< std::pair< std::uint32_t, std::uint32_t > > ObjReader::getDoubledIndexes() const
{
    return doubled_indexes_;
}
std::vector< std::tuple< std::uint32_t, std::uint32_t, std::uint32_t > >
ObjReader::getTripledIndexes() const
{
    return tripled_indexes_;
}
std::vector< std::vector< std::uint32_t > > ObjReader::getIndexes() const
{
    return indexes_;
}

} // namespace files