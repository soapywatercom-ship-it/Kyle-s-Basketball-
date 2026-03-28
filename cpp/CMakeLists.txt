cmake_minimum_required(VERSION 3.20)
project(KylesBasketballFoundation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(kb_foundation
    src/main.cpp
    src/GameApp.cpp
    src/MatchManager.cpp
    src/PossessionManager.cpp
    src/SaveManager.cpp
    src/InputRouter.cpp
    src/CourtSpawner.cpp
)

target_include_directories(kb_foundation PRIVATE include)

if(MSVC)
    target_compile_options(kb_foundation PRIVATE /W4 /permissive-)
else()
    target_compile_options(kb_foundation PRIVATE -Wall -Wextra -Wpedantic)
endif()
