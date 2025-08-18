cmake_minimum_required(VERSION 3.10)

set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(PongGame)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_DIR "C:/vcpkg/installed/x64-windows/share/sdl2")
set(SDL2_IMAGE_DIR "C:/vcpkg/installed/x64-windows/share/sdl2-image")
set(SDL2_TTF_DIR "C:/vcpkg/installed/x64-windows/share/sdl2-ttf")

list(APPEND CMAKE_PREFIX_PATH "C:/vcpkg/installed/x64-windows")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(SDL2_LIB_PATH "${SDL2_LIBRARIES}")
set(SDL2_IMAGE_LIB_PATH "C:/vcpkg/installed/x64-windows/lib/SDL2_image.lib")
set(SDL2_TTF_LIB_PATH "C:/vcpkg/installed/x64-windows/lib/SDL2_ttf.lib")

if(NOT EXISTS ${SDL2_IMAGE_LIB_PATH})
    message(FATAL_ERROR "SDL2_image.lib not found at: ${SDL2_IMAGE_LIB_PATH}")
endif()

message(STATUS "SDL2_INCLUDE_DIRS: ${SDL2_INCLUDE_DIRS}")
message(STATUS "SDL2_LIBRARIES: ${SDL2_LIBRARIES}")
 
add_executable(PongGame
    src/ball.cpp
    src/color.cpp 
    src/courtscene.cpp
    src/dimension.cpp
    src/event.cpp
    src/eventbus.cpp
    src/gameapp.cpp
    src/inputhandler.cpp
    src/main.cpp 
    src/paddle.cpp
    src/point.cpp 
    src/scene.cpp
    src/sceneitem.cpp
)

target_include_directories(PongGame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include  
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
)

target_link_libraries(PongGame PRIVATE
    SDL2::SDL2
    SDL2::SDL2main
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
)
