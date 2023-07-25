cmake_minimum_required(VERSION 3.9)
project(SDL_ParticleFireSimulation)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_PATH "C:\\Users\\ozgur\\SDL2-2.28.1\\x86_64-w64-mingw32")
find_package(SDL2 REQUIRED)
include_directories( ${SDL2_INCLUDE_DIR} )

message("${SDL2_INCLUDE_DIR}")
add_executable(SDL_ParticleFireSimulation main.cpp)

target_link_libraries(SDL_ParticleFireSimulation ${SDL2_LIBRARY} )
message("${SDL2_LIBRARY}")