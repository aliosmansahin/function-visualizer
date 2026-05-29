cmake_minimum_required(VERSION 3.25)
project(FunctionVisualizer VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/window.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/graphics.cpp"
)
set(GLAD_SOURCE_FILE
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glad/src/glad.c"
)

include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.4
    GIT_SHALLOW    TRUE
)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(glfw)

if(WIN32)
    add_compile_definitions(WINDOWS_PLATFORM)
elseif(APPLE)
    add_compile_definitions(MAC_PLATFORM)
endif()

add_executable(${PROJECT_NAME} ${GLAD_SOURCE_FILE} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glad/include")

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        glfw
        opengl32
    )
elseif(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        glfw
        "-framework Cocoa"
        "-framework OpenGL"
        "-framework IOKit"
        "-framework CoreVideo"
    )
endif()