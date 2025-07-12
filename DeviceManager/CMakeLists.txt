cmake_minimum_required(VERSION 3.30)

project(DeviceManagerTask VERSION 1.0.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20 CACHE STRING "The supported C++ standard is C++20." FORCE)
set(CMAKE_CXX_STANDARD_REQUIRED ON CACHE BOOL "It is required to use C++20." FORCE)
set(CMAKE_CXX_EXTENSIONS OFF CACHE BOOL "Compiler specific extensions are disabled." FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Always build static libraries." FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "Do not install GoogleTest." FORCE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/b514bdc898e2951020cbdca1304b75f5950d1f59.zip # v1.15.2
    URL_HASH SHA256=8C0CEAFA3EA24BF78E3519B7846D99E76C45899AA4DAC4D64E7DD62E495DE9FD
)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)
set(googletest_targets gtest gtest_main gmock gmock_main)
foreach(googletest_target IN LISTS googletest_targets)
    set_property(TARGET ${googletest_target} PROPERTY FOLDER GoogleTest)
    target_compile_definitions(${googletest_target}
        PRIVATE
            GTEST_CREATE_SHARED_LIBRARY=0
    )
endforeach()


add_subdirectory(DeviceManager)
add_subdirectory(DeviceManagerLib)
add_subdirectory(DeviceManagerTests)


install(TARGETS DeviceManager RUNTIME DESTINATION bin)


set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_directory_properties(PROPERTIES VS_STARTUP_PROJECT DeviceManager)
