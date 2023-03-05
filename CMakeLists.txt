cmake_minimum_required(VERSION 3.22)

project(RayTracer)

file(GLOB_RECURSE "${PROJECT_NAME}_SRC" CONFIGURE_DEPENDS
        "src/*.cpp")

add_executable(${PROJECT_NAME} "${${PROJECT_NAME}_SRC}")

target_include_directories(${PROJECT_NAME} PRIVATE include)
