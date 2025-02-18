add_executable(DeviceManager)

target_sources(DeviceManager
    PRIVATE
        src/DeviceManager.cpp
)

source_group("Header Files" REGULAR_EXPRESSION .+\\.h)
source_group("Source Files" REGULAR_EXPRESSION .+\\.cpp)

target_compile_definitions(DeviceManager PRIVATE UNICODE _UNICODE)

target_link_libraries(DeviceManager PRIVATE DeviceManagerLib)
