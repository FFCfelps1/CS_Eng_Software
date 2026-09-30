cmake_minimum_required(VERSION 3.20)

project(AppliMeteo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SFML 3 CONFIG REQUIRED COMPONENTS Graphics Window System)

add_executable(AppliMeteo
    AfficheurCourbe.cpp
    AppliMeteo.cpp
    ../Question1/Question1/CapteurMeteo.cpp
)

target_include_directories(AppliMeteo PRIVATE
    ../Question1/Question1
)

target_link_libraries(AppliMeteo PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)
