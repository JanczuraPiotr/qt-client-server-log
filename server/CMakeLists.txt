set(SERVER server)
project(${SERVER})

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++ -MMD -MP -MF")

add_executable(${SERVER} main.cpp

        ../common/algorithm/Key.cpp
        ../common/algorithm/Key.h
        ../common/algorithm/String.cpp
        ../common/algorithm/String.h

        ../common/db/Collection.cpp
        ../common/db/Collection.h
        ../common/db/Connection.cpp
        ../common/db/Connection.h
        ../common/db/Db.cpp
        ../common/db/Db.h
        ../common/db/exception.cpp
        ../common/db/exception.h
        ../common/db/Record.cpp
        ../common/db/Record.h
        ../common/db/SQLiteConnection.cpp
        ../common/db/SQLiteConnection.h
        ../common/db/SQLiteStructure.cpp
        ../common/db/SQLiteStructure.h
        ../common/db/Structure.cpp
        ../common/db/Structure.h

        ../common/exception/general.cpp                     ../common/exception/general.h

        ../common/data/entity/Interval.cpp                  ../common/data/entity/Interval.hpp
        ../common/output/ErrorMessage.cpp                   ../common/output/ErrorMessage.h

        action/InsertLog.cpp                                action/InsertLog.h

        app/ConfigFile.cpp                                  app/ConfigFile.h
        app/SignalBus.cpp                                   app/SignalBus.h

        input/Input.cpp                                     input/Input.hpp
        input/protocol/GetLogsBetweenEbnf.cpp               input/protocol/GetLogsBetweenEbnf.h
        input/protocol/GetLogsBetweenJson.cpp               input/protocol/GetLogsBetweenJson.h
        input/protocol/GetLogRecordJson.cpp                 input/protocol/GetLogRecordJson.h
        input/GetLogsBetween.cpp                            input/GetLogsBetween.h

        data/LogCollection.cpp                              data/LogCollection.h
        data/LogRecord.cpp                                  data/LogRecord.h


        output/Output.cpp                                   output/Output.hpp
        output/GetLogsBetween.cpp                           output/GetLogsBetween.h
        output/protocol/GetLogsBetweenJson.cpp              output/protocol/GetLogsBetweenJson.h
        output/protocol/GetLogsBetweenEbnf.cpp              output/protocol/GetLogsBetweenEbnf.h
        output/protocol/GetLogRecordJson.cpp                output/protocol/GetLogRecordJson.h

        service/FakeEvent.cpp                               service/FakeEvent.h
        service/NetConnection.cpp                           service/NetConnection.h
        service/Main.cpp                                    service/Main.h
        )

find_package(Qt5Core REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Network REQUIRED)

target_link_libraries(${SERVER}
        ${GTEST_LIBRARIES}
        pthread
        Qt5::Core
        Qt5::Sql
        Qt5::Network
        )
