cmake_policy(SET CMP0054 NEW)
cmake_policy(SET CMP0011 NEW)

if(NOT EXISTS "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_CURRENT_BINARY_DIR}/conan.cmake)

function(conan_config_and_install deps)
    conan_cmake_configure(
            REQUIRES "${deps}"
            GENERATORS cmake_find_package
    )
    conan_cmake_autodetect(settings)
    conan_cmake_install(
            PATH_OR_REFERENCE .
            BUILD missing
            REMOTE conancenter
            SETTINGS ${settings}
    )
    conan_cmake_lock_create(PATH conanfile.txt SETTINGS ${settings})
endfunction()
