cmake_minimum_required(VERSION 3.25)
project(FunctionVisualizer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCE_FILES "src/*.cpp")

if(WIN32)
    add_compile_definitions(WINDOWS_PLATFORM)
elseif(APPLE)
    add_compile_definitions(MAC_PLATFORM)
endif()

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE src)