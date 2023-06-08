cmake_minimum_required(VERSION 3.22)

project(Tests)

enable_testing()
set(SEPARATE_TESTS_FILES math_tests.cpp sphere_tests.cpp plane_tests.cpp)

string( REPLACE ".cpp" "" BASENAMES_IDIOMATIC_TESTS_FILES "${SEPARATE_TESTS_FILES}" )

foreach( name ${BASENAMES_IDIOMATIC_TESTS_FILES} )
    add_executable( ${name}
            ${CMAKE_CURRENT_SOURCE_DIR}/${name}.cpp)

    add_test(NAME ${name} COMMAND ${name})
endforeach()

file(GLOB_RECURSE "PROJECT_AS_LIBRARY_SRC" CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/../src/*.cpp")
list(REMOVE_ITEM PROJECT_AS_LIBRARY_SRC "${CMAKE_CURRENT_SOURCE_DIR}/../src/main.cpp")

add_library(PROJECT_AS_LIBRARY ${PROJECT_AS_LIBRARY_SRC})
target_include_directories( PROJECT_AS_LIBRARY PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include ${CMAKE_SOURCE_DIR}/ImageConverterLibrary/include)

foreach( name ${BASENAMES_IDIOMATIC_TESTS_FILES} )
    target_link_libraries( ${name} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain ImageConverterLibrary PROJECT_AS_LIBRARY )
endforeach()

foreach( name ${BASENAMES_IDIOMATIC_TESTS_FILES} )
    target_include_directories( ${name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include ${CMAKE_SOURCE_DIR}/ImageConverterLibrary/include)
endforeach()
