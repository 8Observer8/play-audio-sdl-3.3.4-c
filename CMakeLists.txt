cmake_minimum_required(VERSION 3.21)
project(play-audio-sdl-3.3.4-c)
add_executable(app)

# Specify where the application source files are stored
target_sources(app
PRIVATE
    src/main.c
)

# Check for WebAssembly
if (CMAKE_SYSTEM_NAME MATCHES "Emscripten")
    target_link_options("app" PRIVATE "SHELL:--embed-file ${CMAKE_CURRENT_SOURCE_DIR}/assets/audio/picked-coin-echo-2.wav@/assets/audio/picked-coin-echo-2.wav")
    set_property(TARGET "app" APPEND PROPERTY LINK_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/assets/audio/picked-coin-echo-2.wav")
endif()

# Check for Windows
if (WIN32)
    target_link_options(app PRIVATE -static)
endif()

find_package(SDL3)
find_package(SDL3_mixer)
target_link_libraries(app PRIVATE SDL3_mixer::SDL3_mixer SDL3::SDL3)

# For comments:
#[===[
# Some content here
#]===]
