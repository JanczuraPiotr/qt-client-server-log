cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++ -MMD -MP -MF")
set(CMAKE_CXX_COMPILER_LOADED "${CMAKE_CXX_COMPILER_LOADED} -lz -lm -lrt -ldl")

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)

# client

include_directories(.)

add_executable(qt-client-server-log-client
        client/main.cpp
        common/transport/Push.cpp           common/transport/Push.h
        common/transport/Pull.cpp           common/transport/Pull.h
        server/model/Log.cpp                server/model/Log.h
                                            common/def.h
        server/model/def.h)

target_link_libraries(qt-client-server-log-client Qt5::Widgets)


# server

include_directories(.)
add_executable(qt-client-server-log-server
        server/main.cpp
                                            server/config.h
        common/transport/Push.cpp           common/transport/Push.h
        common/transport/Pull.cpp           common/transport/Pull.h
        server/model/db/Driver.cpp          server/model/db/Driver.h
        server/model/LogTable.cpp           server/model/LogTable.h
        server/model/db/Record.cpp server/model/db/Record.h server/model/db/Table.cpp server/model/db/Table.h)

target_link_libraries(qt-client-server-log-server
        Qt5::Sql
        Qt5::Widgets
        )


include_directories(.)
include_directories(./client)
include_directories(./common)
include_directories(./server)

add_executable(qt-client-server-log-test
        test/main.cpp
        test/client/MainTest.cpp            test/client/MainTest.h
        )

target_link_libraries(qt-client-server-log-test
        gtest
        gtest_main
        )


target_link_libraries(qt-client-server-log-test
        Qt5::Widgets
        )