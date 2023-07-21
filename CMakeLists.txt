cmake_minimum_required(VERSION 3.5)
project(backuper VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(third_party/drogon)

add_executable(backuper main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE drogon)
