cmake_minimum_required(VERSION 3.20)

project(AppliMeteoPrevisions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(AppliMeteoPrevisions
    AfficheurPrevisions.cpp
    AppliMeteo.cpp
    ../Question1/Question1/CapteurMeteo.cpp
)

target_include_directories(AppliMeteoPrevisions PRIVATE
    ../Question1/Question1
)

target_compile_definitions(AppliMeteoPrevisions PRIVATE
    CAPTEUR_METEO_TEST
)
