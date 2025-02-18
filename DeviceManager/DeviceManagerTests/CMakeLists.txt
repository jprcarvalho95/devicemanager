add_executable(DeviceManagerTests)

target_sources(DeviceManagerTests
    PRIVATE
        src/Tests.cpp
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
