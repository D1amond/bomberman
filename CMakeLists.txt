cmake_minimum_required(VERSION 2.6)
project(bomberman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

file(GLOB_RECURSE SRC_FILES "src/*.cpp")

add_executable(bomberman ${SRC_FILES} main.cpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

find_package(SFML 2 REQUIRED system window graphics network audio)
target_link_libraries(bomberman ${SFML_LIBRARIES})

include_directories("include/" "./")

install(TARGETS bomberman RUNTIME DESTINATION bin)