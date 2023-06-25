cmake_minimum_required(VERSION 3.22)
project(CompGraphics23)
set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_BINARY_DIR})

include(Conan NO_POLICY_SCOPE)
set(DEPENDENCY_LIBS boost/1.82.0 catch2/3.1.0 fmtlog/2.2.1)
conan_config_and_install("${DEPENDENCY_LIBS}")

add_subdirectory(RayTracer)
add_subdirectory(ImageConverterLibrary)
add_subdirectory(ImageConverter)
