project(ImageConverter)

file(GLOB_RECURSE "${PROJECT_NAME}_SRC" CONFIGURE_DEPENDS "src/*.cpp")

add_executable(${PROJECT_NAME} "${${PROJECT_NAME}_SRC}")

find_package(Boost)
find_package(fmtlog)
find_package(Catch2)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Boost::system
        ${Boost_LIBRARIES}
        fmtlog::fmtlog
        Catch2::Catch2
        ImageConverterLibrary
)