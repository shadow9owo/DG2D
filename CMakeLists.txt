cmake_minimum_required(VERSION 3.10)
project(dg2d)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Enable this while release build
#set(CMAKE_BUILD_TYPE Release)

add_definitions(-Wall -g)

find_package(PkgConfig REQUIRED)
find_package(ZLIB REQUIRED)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
pkg_check_modules(ALSA REQUIRED alsa)

include_directories(
    ${SDL2_INCLUDE_DIRS}
)

set(SRC_FILES
    enums.hpp
    globals.cpp
    globals.hpp
    addons/beep/beep.h
    Audio/Audio.cpp
    Audio/Audio.hpp
    Collision/AABB.cpp
    Collision/AABB.hpp
    demo/main.cpp
    Draw/Draw.cpp
    Draw/Draw.hpp
    events/Handle_SDL_events.cpp
    events/Handle_SDL_events.hpp
    ini/ini.cpp
    ini/ini.hpp
    Math/FPSutils.cpp
    Math/FPSutils.hpp
    Math/MathVars.hpp
    Platform/Platform.cpp
    Platform/Platform.hpp
    std/STD.cpp
    std/STD.hpp
    Textures/Textures.cpp
    Textures/Textures.hpp
    ttf/ttf.cpp
    ttf/ttf.hpp
    utils/utils.cpp
    utils/utils.hpp
)

add_executable(dg2d ${SRC_FILES})

target_include_directories(dg2d PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_MIXER_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
    ${ALSA_INCLUDE_DIRS}
)

target_link_libraries(dg2d PRIVATE 
    ZLIB::ZLIB
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${ALSA_LIBRARIES}
)

