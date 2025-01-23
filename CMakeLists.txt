cmake_minimum_required(VERSION 3.28)

project(webgui)

set(VERSION 0.0.1)

set(LANGUAGE CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (MSVC)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32)
elseif(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
    add_executable(${PROJECT_NAME} WIN32)
else()
    add_executable(${PROJECT_NAME})
endif()

message(${CMAKE_BUILD_TYPE})

target_sources(${PROJECT_NAME}
    PRIVATE
    "src/main.cpp"
)

include_directories("${PROJECT_SOURCE_DIR}/third_party/webui/include")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(WEBUI_LIB ${PROJECT_SOURCE_DIR}/third_party/webui/debug/webui-2-static.lib)
else()
    set(WEBUI_LIB ${PROJECT_SOURCE_DIR}/third_party/webui/webui-2-static.lib)
endif()

target_link_libraries(
    ${PROJECT_NAME}
    ${WEBUI_LIB}
)
