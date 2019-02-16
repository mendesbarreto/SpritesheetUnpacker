cmake_minimum_required(VERSION 3.13)
project(SpritesheetUnpacker)
set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_DIRS})

add_executable(SpritesheetUnpacker main.cpp SDLProgram.cpp SDLProgram.h)
target_link_libraries(SpritesheetUnpacker ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})