cmake_minimum_required(VERSION 3.1)

# Compiling Flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -Wall -Werror")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2 -Wall")

project(SpaceShooter)

set(SRC
    src/Background.cpp
    src/Bullet.cpp
    src/Ennemy.cpp
    src/gameInputs.cpp
    src/main.cpp
    src/Player.cpp
    src/Score.cpp
    src/WindowGestion.cpp
    src/Menus.cpp
    src/Animation.cpp)

include_directories(.)

set(EXECUTABLE_NAME Spaceshooter)
add_executable(${EXECUTABLE_NAME} ${SRC})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4 REQUIRED system window graphics)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})