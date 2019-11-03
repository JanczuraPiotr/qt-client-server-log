cmake_minimum_required(VERSION 3.10)

set(APP log)

project(${APP})
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++ -MMD -MP -MF")
set(CMAKE_CXX_COMPILER_LOADED "${CMAKE_CXX_COMPILER_LOADED} -lz -lm -lrt -ldl")

set(CMAKE_PREFIX_PATH "/opt/Qt5.12.4/5.12.4/gcc_64")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Network REQUIRED)


include_directories(.)
#include_directories(client)
#include_directories(common)
#include_directories(common/model)
#include_directories(common/model/db)
#include_directories(common/transport)
#include_directories(install)
include_directories(server)
#include_directories(gtest)
#include_directories(gtest/client)

## client
#add_executable(${APP}-client
#        client/main.cpp
#        common/transport/Push.cpp           common/transport/Push.h
#        common/transport/Pull.cpp           common/transport/Pull.h
#        server/model/Log.cpp                server/model/Log.h
#                                            common/def.h
#        server/model/def.h)
#
#target_link_libraries(${APP}-client Qt5::Widgets)
#

# server

add_executable(qt-client-server-log-server
        server/main.cpp
                                            server/config.h
#        common/transport/Push.cpp           common/transport/Push.h
#        common/transport/Pull.cpp           common/transport/Pull.h
#        server/model/db/Driver.cpp          server/model/db/Driver.h
#        server/model/LogTable.cpp           server/model/LogTable.h
#        server/model/db/Record.cpp          server/model/db/Record.h
#        server/model/db/Table.cpp           server/model/db/Table.h
        )

target_link_libraries(qt-client-server-log-server
        Qt5::Core
        Qt5::Sql
        Qt5::Widgets
        )


#include_directories(.)
#include_directories(./client)
#include_directories(./common)
#include_directories(./server)
#
#add_executable(qt-client-server-log-gtest
#        gtest/main.cpp
#        gtest/client/MainTest.cpp            gtest/client/MainTest.h
#        )
#
#target_link_libraries(qt-client-server-log-gtest
#        gtest
#        gtest_main
#        )
#
#
#target_link_libraries(qt-client-server-log-gtest
#        Qt5::Widgets
#        )


add_subdirectory(gtest)
