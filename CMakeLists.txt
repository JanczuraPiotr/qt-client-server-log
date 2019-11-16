cmake_minimum_required(VERSION 3.10)

set(PROJECT  qt-client-server-log)
project(${PROJECT})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++ -MMD -MP -MF")
set(CMAKE_CXX_COMPILER_LOADED "${CMAKE_CXX_COMPILER_LOADED} -lz -lm -lrt -ldl")

set(CMAKE_PREFIX_PATH "/opt/Qt5.12.4/5.12.4/gcc_64")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Network REQUIRED)
#find_package(Qt5Widgets REQUIRED)


include_directories(.)
include_directories(client)
include_directories(common)
include_directories(common/exception)
include_directories(common/db)
include_directories(common/transport)
include_directories(server)


add_subdirectory(client)
add_subdirectory(server)
#add_subdirectory(gtest)
