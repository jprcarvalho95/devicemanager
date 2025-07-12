add_executable(DeviceManager)

#Easier than listing all files
file(GLOB_RECURSE ALL_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

target_include_directories(DeviceManager 
	PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../DeviceManagerLib/src
    ${CMAKE_CURRENT_SOURCE_DIR}/../DeviceManagerLib/include

)
target_sources(DeviceManager
    PRIVATE
        ${ALL_SOURCES}
)

source_group("Header Files" REGULAR_EXPRESSION .+\\.h)
source_group("Source Files" REGULAR_EXPRESSION .+\\.cpp)

target_compile_definitions(DeviceManager PRIVATE UNICODE _UNICODE)

target_link_libraries(DeviceManager PRIVATE DeviceManagerLib)
