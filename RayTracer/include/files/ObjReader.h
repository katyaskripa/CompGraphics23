#pragma once

#include <string>
#include <vector>

#include "lmath.h"

namespace files
{
class ObjReader
{
public:
    ObjReader( std::string file_name );
    void read();

public:
    std::vector< lmath::Point3 > getVertexes() const;
    std::vector< lmath::Vec3 > getNormals() const;
    std::vector< std::uint32_t > getLineElements() const;
    std::vector< std::pair< std::uint32_t, std::uint32_t > > getDoubledIndexes() const;
    std::vector< std::tuple< std::uint32_t, std::uint32_t, std::uint32_t > >
    getTripledIndexes() const;
    std::vector< std::vector< std::uint32_t > > getIndexes() const;

private:
    void readVertexes();
    void readNormals();
    void readIndexes();
    void readLineElements();

private:
    std::string file_name_;
    std::vector< lmath::Point3 > vertexes_;
    std::vector< lmath::Vec3 > normals_;
    std::vector< std::uint32_t > line_elements_;
    std::vector< std::pair< std::uint32_t, std::uint32_t > > doubled_indexes_;
    std::vector< std::tuple< std::uint32_t, std::uint32_t, std::uint32_t > > tripled_indexes_;
    std::vector< std::vector< std::uint32_t > > indexes_;
};
} // namespace files
