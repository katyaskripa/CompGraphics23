project(RayTracer)

file(GLOB_RECURSE "${PROJECT_NAME}_SRC" CONFIGURE_DEPENDS
        "src/*.cpp")

add_executable(${PROJECT_NAME} "${${PROJECT_NAME}_SRC}")

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter -Wno-unused-variable)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# installing libraries with conan and linking libraries to the project

find_package(Boost)
find_package(fmtlog)
find_package(Catch2)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Boost::system
        fmtlog::fmtlog
        Catch2::Catch2
        ImageConverterLibrary)

# tests
add_subdirectory(tests)
