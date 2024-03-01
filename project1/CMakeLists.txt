include_directories(include)
add_executable(project1 main.cpp src/Application.cpp src/VulkanDebug.cpp)
target_link_libraries(project1 glfw Vulkan::Vulkan)

file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/shaders)
add_custom_command(
    OUTPUT ${PROJECT_SOURCE_DIR}/bin/shaders/vert.spv
    COMMAND $ENV{VULKAN_SDK}/bin/glslc -g ${CMAKE_CURRENT_SOURCE_DIR}/shaders/shader.vert -o ${PROJECT_SOURCE_DIR}/bin/shaders/vert.spv
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/shaders/shader.vert
    COMMENT "--------------Compiling vertex shader------------------"
)
add_custom_command(
    OUTPUT ${PROJECT_SOURCE_DIR}/bin/shaders/frag.spv
    COMMAND $ENV{VULKAN_SDK}/bin/glslc -g ${CMAKE_CURRENT_SOURCE_DIR}/shaders/shader.frag -o ${PROJECT_SOURCE_DIR}/bin/shaders/frag.spv
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/shaders/shader.frag
    COMMENT "--------------Compiling fragment shader-------------------"
)

add_custom_target(shaders DEPENDS
                        ${PROJECT_SOURCE_DIR}/bin/shaders/vert.spv
                        ${PROJECT_SOURCE_DIR}/bin/shaders/frag.spv)

add_dependencies(project1 shaders)