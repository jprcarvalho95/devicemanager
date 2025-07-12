add_executable(DeviceManagerTests)

#Easier than listing all files
file(GLOB_RECURSE ALL_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)
target_include_directories(DeviceManagerTests 
	PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../DeviceManagerLib/src
    ${CMAKE_CURRENT_SOURCE_DIR}/../DeviceManagerLib/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../DeviceManager/src
    ${CMAKE_CURRENT_SOURCE_DIR}/../DeviceManager/include
)

target_sources(DeviceManagerTests
    PRIVATE
        ${ALL_SOURCES}
)

source_group("Header Files" REGULAR_EXPRESSION .+\\.h)
source_group("Source Files" REGULAR_EXPRESSION .+\\.cpp)

target_compile_definitions(DeviceManagerTests PRIVATE UNICODE _UNICODE)

target_link_libraries(DeviceManagerTests
    PRIVATE
        DeviceManagerLib
        GTest::gmock_main
)

gtest_discover_tests(DeviceManagerTests)
