cmake_minimum_required(VERSION 4.0.0)
set(CMAKE_CXX_COMPILER "clang++")

project(IntroToOpenGL
    VERSION 1.0.0
    LANGUAGES CXX
)

# Export compile commands for clangd(LSP)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include_directories(
	"${CMAKE_SOURCE_DIR}/src"
)

file(GLOB_RECURSE SOURCE_FILES
	${CMAKE_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE HEADER_FILES
	${CMAKE_SOURCE_DIR}/src/*.h
)

file(GLOB_RECURSE SHADER_FILES
	${CMAKE_SOURCE_DIR}/assets/shaders/*.shader
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES} ${SHADER_FILES})

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(imgui CONFIG REQUIRED)

set(LIBS OpenGL::GL glfw glad::glad glm::glm imgui::imgui)

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)


message(STATUS "Source files: ${SOURCE_FILES}")
message(STATUS "Header files: ${HEADER_FILES}")
message(STATUS "Shader files: ${SHADER_FILES}")
