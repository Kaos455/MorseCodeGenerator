cmake_minimum_required(VERSION 3.15)

project(MorseCodeGenerator VERSION 0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(imgui CONFIG REQUIRED)
find_package(portaudio CONFIG REQUIRED)
find_package(mp3lame CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${CMAKE_SOURCE_DIR}/vendors")
file(GLOB_RECURSE SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)
file(COPY "${CMAKE_SOURCE_DIR}/vendors/resources/fonts" DESTINATION "${CMAKE_BINARY_DIR}/resources/")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        imgui::imgui
        portaudio
        mp3lame::mp3lame
        glad::glad
        glfw
)