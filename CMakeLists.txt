cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)

project(RayTracer)

file(GLOB_RECURSE "${PROJECT_NAME}_SRC" CONFIGURE_DEPENDS
        "src/*.cpp")

add_executable(${PROJECT_NAME} "${${PROJECT_NAME}_SRC}")

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -Wunused-parameter)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
