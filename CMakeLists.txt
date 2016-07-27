cmake_minimum_required(VERSION 3.5)
project(hyphus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

include_directories(C:/libraries/sdl2/include/)
link_directories(C:/libraries/sdl2/lib/)

set(SOURCE_FILES main.cpp core/Engine.cpp core/Engine.h core/Graphics.cpp core/Graphics.h core/Color.cpp core/Color.h stdpp.h)
add_executable(hyphus ${SOURCE_FILES})

target_link_libraries(hyphus SDL2main SDL2 opengl32)