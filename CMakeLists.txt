cmake_minimum_required(VERSION 3.25)
project(FunctionVisualizer VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/window.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/graphics.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/interface.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/function_executor.cpp"
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

FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG        docking
    GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(imgui)

FetchContent_GetProperties(imgui SOURCE_DIR IMGUI_SOURCE_DIR)

set(IMGUI_SOURCES
    "${IMGUI_SOURCE_DIR}/imgui.cpp"
    "${IMGUI_SOURCE_DIR}/imgui_draw.cpp"
    "${IMGUI_SOURCE_DIR}/imgui_widgets.cpp"
    "${IMGUI_SOURCE_DIR}/imgui_tables.cpp"
    "${IMGUI_SOURCE_DIR}/imgui_demo.cpp"
    "${IMGUI_SOURCE_DIR}/backends/imgui_impl_glfw.cpp"
    "${IMGUI_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp"
)

if(WIN32)
    add_compile_definitions(WINDOWS_PLATFORM)
elseif(APPLE)
    add_compile_definitions(MAC_PLATFORM)
endif()

add_executable(${PROJECT_NAME} ${GLAD_SOURCE_FILE} ${SOURCE_FILES} ${IMGUI_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/glad/include"
    "${IMGUI_SOURCE_DIR}"
    "${IMGUI_SOURCE_DIR}/backends"
)

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