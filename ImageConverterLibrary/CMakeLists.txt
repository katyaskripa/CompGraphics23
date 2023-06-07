project(ImageConverterLibrary)

add_library(${PROJECT_NAME} STATIC)

file(GLOB_RECURSE "${PROJECT_NAME}_SRC" CONFIGURE_DEPENDS "src/*.cpp")

target_sources(${PROJECT_NAME} PRIVATE "${${PROJECT_NAME}_SRC}")

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

find_package(Boost)
find_package(fmtlog)

target_link_libraries(${PROJECT_NAME} PUBLIC
        Boost::system
        ${Boost_LIBRARIES}
        fmtlog::fmtlog
)