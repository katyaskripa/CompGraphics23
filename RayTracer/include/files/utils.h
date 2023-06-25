#pragma once

#include <filesystem>

namespace files::utils
{
inline bool checkIfFileExists( const std::string& file_name )
{
    return std::filesystem::exists( std::filesystem::path{ file_name.c_str() } );
}

inline std::string getExtension( const std::string& file_path )
{
    return file_path.substr( file_path.rfind( '.' ) + 1,
                             file_path.size() - file_path.rfind( '.' ) - 1 );
}

} // namespace files::utils