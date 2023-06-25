#pragma once

#include <string>
#include <vector>

#include "lmath.h"

namespace files
{
class ObjReader
{
public:
    explicit ObjReader( std::string file_name );
    void read();

public:
    [[nodiscard]] std::vector< lmath::Point3 > getVertexes() const;
    [[nodiscard]] std::vector< lmath::Vec3 > getNormals() const;
    [[nodiscard]] std::vector< std::uint32_t > getLineElements() const;
    [[nodiscard]] std::vector< std::vector< std::vector< std::uint32_t > > > getIndexes() const;

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
    std::vector< std::vector< std::vector< std::uint32_t > > > indexes_;
};
} // namespace files
