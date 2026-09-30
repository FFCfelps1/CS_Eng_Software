cmake_minimum_required(VERSION 3.20)

project(AppliScores LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SFML 3 CONFIG REQUIRED COMPONENTS Graphics Window System)

add_executable(AppliScores
    AfficheurCourbe.cpp
    AppliScores.cpp
)

target_link_libraries(AppliScores PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)
