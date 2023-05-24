cmake_minimum_required(VERSION 3.20)

project(zappy_gui)

# Project options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -fdiagnostics-color=always")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Project files
file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(zappy_gui ${SOURCES})
target_include_directories(zappy_gui PRIVATE src)

# Dependencies
include(FetchContent)

FetchCOntent_Declare(
        SFML
        URL "https://github.com/SFML/SFML/archive/2.5.1.zip"
)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG 0ea3b87bd63ecbf359585b7c235839146e84dedb
)

FetchContent_Declare(
    imgui-sfml
    GIT_REPOSITORY https://github.com/SFML/imgui-sfml.git
    GIT_TAG        master
)

FetchContent_MakeAvailable(imgui)

set(IMGUI_DIR ${imgui_SOURCE_DIR})
option(IMGUI_SFML_FIND_SFML "Use find_package to find SFML" OFF)
option(IMGUI_SFML_IMGUI_DEMO "Build imgui_demo.cpp" OFF)

FetchContent_MakeAvailable(imgui-sfml)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.11.0
)
FetchContent_MakeAvailable(spdlog)

find_package(fmt REQUIRED)

# Linking
target_link_libraries(zappy_gui PRIVATE ${SFML_LIBRARIES} spdlog::spdlog fmt::fmt)
target_link_libraries(zappy_gui PRIVATE ImGui-SFML::ImGui-SFML)

# Copy assets
add_custom_command(TARGET zappy_gui POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/assets)