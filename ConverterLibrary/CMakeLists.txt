cmake_minimum_required(VERSION 3.22)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake" ${CMAKE_CURRENT_BINARY_DIR})
include(Conan NO_POLICY_SCOPE)

set(CMAKE_CXX_STANDARD 20)

project(ConverterLibrary)

file(GLOB_RECURSE "${PROJECT_NAME}_SRC" CONFIGURE_DEPENDS
        "src/*.cpp")

add_library(${PROJECT_NAME} "${${PROJECT_NAME}_SRC}")

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter -Wno-unused-variable)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# installing libraries with conan and linking libraries to the project
set(DEPENDENCY_LIBS boost/1.80.0 catch2/3.1.0 fmtlog/2.2.1)
conan_config_and_install("${DEPENDENCY_LIBS}")

find_package(Boost)
find_package(fmtlog)
find_package(Catch2)

target_include_directories(${PROJECT_NAME} PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:include>
)

add_link_options(-fuse-ld=lld)

# -- Install common library --
set(COMMON_LIB_PREFIX_PATH "$ENV{HOME}/.CompGraphics23/common" CACHE STRING "Common library install path")

install(TARGETS ${PROJECT_NAME}
        EXPORT "${PROJECT_NAME}Targets"
        DESTINATION "${COMMON_LIB_PREFIX_PATH}/lib/${CMAKE_BUILD_TYPE}"
        CONFIGURATIONS ${CMAKE_BUILD_TYPE}
        )

install(DIRECTORY include DESTINATION "${COMMON_LIB_PREFIX_PATH}")

set(CMAKE_INSTALL_PREFIX ${COMMON_LIB_PREFIX_PATH})
install(EXPORT "${PROJECT_NAME}Targets"
        FILE "${PROJECT_NAME}Targets.cmake"
        NAMESPACE CompGraphics23::
        DESTINATION "${COMMON_LIB_PREFIX_PATH}/cmake"
        )

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../cmake/ConverterLibraryConfig.cmake DESTINATION ${COMMON_LIB_PREFIX_PATH})

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        Boost::system
        fmtlog::fmtlog
        Catch2::Catch2)