cmake_minimum_required(VERSION 3.16)

project(game LANGUAGES CXX)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)

add_executable(game src/main.cpp)
target_compile_features(game PRIVATE cxx_std_17)
set_target_properties(game PROPERTIES CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.30.0
)

FetchContent_MakeAvailable(SDL2)

target_link_libraries(game
    PRIVATE
        SDL2::SDL2-static
        SDL2::SDL2main
)
