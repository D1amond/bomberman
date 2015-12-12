cmake_minimum_required(VERSION 2.6)
project(bomberman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(bomberman main.cpp src/window/WindowManager.cpp src/event/EventManager.cpp)

find_package(SFML 2 REQUIRED system window graphics network audio)
target_link_libraries(bomberman ${SFML_LIBRARIES})

include_directories("include/")

install(TARGETS bomberman RUNTIME DESTINATION bin)