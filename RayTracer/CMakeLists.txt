cmake_minimum_required(VERSION 3.22)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake" ${CMAKE_CURRENT_BINARY_DIR})

include(Conan NO_POLICY_SCOPE)

set(CMAKE_CXX_STANDARD 20)

project(RayTracer)

file(GLOB_RECURSE "${PROJECT_NAME}_SRC" CONFIGURE_DEPENDS
        "src/*.cpp")

add_executable(${PROJECT_NAME} "${${PROJECT_NAME}_SRC}")

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter -Wno-unused-variable)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# installing libraries with conan and linking libraries to the project
set(DEPENDENCY_LIBS boost/1.80.0 catch2/3.1.0 fmtlog/2.2.1)
conan_config_and_install("${DEPENDENCY_LIBS}")


find_package(Boost)
find_package(fmtlog)
find_package(Catch2)
find_package(ConverterLibrary)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    CompGraphics23::ConverterLibrary)

add_link_options(-fuse-ld=lld)

# tests
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)