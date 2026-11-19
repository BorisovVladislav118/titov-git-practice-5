cmake_minimum_required(VERSION 3.12)

project(practice5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SKIP_BUILD_TEST ON)

add_subdirectory(lib/postgresql build-pqxx)

add_executable(practice5 main.cpp)

target_link_libraries(practice5 PRIVATE pqxx)
