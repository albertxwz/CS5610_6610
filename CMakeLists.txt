cmake_minimum_required(VERSION 3.1...3.28 FATAL_ERROR)

project(
    CS5610_6610
    VERSION 0.1.0
    LANGUAGES CXX C
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

# Find Vulkan package
find_package(Vulkan REQUIRED)

# Include vulkan
include_directories(${Vulkan_INCLUDE_DIRS})

# Include glfw
add_subdirectory(glfw)
include_directories(glfw/include)

add_subdirectory(project1)
