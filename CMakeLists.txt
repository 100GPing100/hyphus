cmake_minimum_required(VERSION 3.5)
project(hyphus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

add_definitions(-DGLEW_STATIC)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib/")

set(SOURCE_FILES main.cpp stdpp.h core/Engine.cpp core/Engine.h core/Graphics.cpp core/Graphics.h core/Color.cpp core/Color.h core/Entity.cpp core/Entity.h core/Component.cpp core/Component.h include/quidor/Object.h include/quidor/Type.h)
add_executable(hyphus ${SOURCE_FILES})

target_link_libraries(hyphus SDL2main SDL2 opengl32 glew32 DevIL ILU ILUT)