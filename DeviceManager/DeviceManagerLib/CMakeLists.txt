add_library(DeviceManagerLib STATIC)

#Easier than listing all files
file(GLOB_RECURSE ALL_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.cpp"
)


target_sources(DeviceManagerLib
    PRIVATE
        ${ALL_SOURCES}
)

source_group("Header Files" REGULAR_EXPRESSION .+\\.h)
source_group("Source Files" REGULAR_EXPRESSION .+\\.cpp)

target_compile_definitions(DeviceManagerLib PRIVATE UNICODE _UNICODE)

target_include_directories(DeviceManagerLib
	PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../DeviceManager/include
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
