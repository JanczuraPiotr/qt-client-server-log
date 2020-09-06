project(gtest)

add_executable(gtest main.cpp

        ../client/input/protocol/GetLogsBetweenEbnf.cpp     ../client/input/protocol/GetLogsBetweenEbnf.h
        ../client/input/protocol/GetLogsBetweenJson.cpp     ../client/input/protocol/GetLogsBetweenJson.h
        ../client/input/protocol/LogEbnf.cpp                ../client/input/protocol/LogEbnf.h
        ../client/input/protocol/GetLogRecordJson.cpp       ../client/input/protocol/GetLogRecordJson.h
        ../client/input/GetLogsBetween.cpp                  ../client/input/GetLogsBetween.h
        ../client/input/Log.cpp                             ../client/input/Log.h

        ../client/data/LogCollection.cpp                    ../client/data/LogCollection.h
        ../client/data/LogRecord.cpp                        ../client/data/LogRecord.h

        ../client/output/protocol/GetLogsBetweenEbnf.cpp    ../client/output/protocol/GetLogsBetweenEbnf.h
        ../client/output/protocol/GetLogsBetweenJson.cpp    ../client/output/protocol/GetLogsBetweenJson.h
        ../client/output/protocol/GetLogRecordJson.cpp      ../client/output/protocol/GetLogRecordJson.hpp
        ../client/output/GetLogsBetween.cpp                 ../client/output/GetLogsBetween.h

        ../common/algorithm/String.cpp                      ../common/algorithm/String.h
        ../common/algorithm/Key.cpp                         ../common/algorithm/Key.h
        ../common/db/Record.cpp                             ../common/db/Record.h
        ../common/data/Data.cpp                             ../common/data/Data.hpp
        ../common/data/entity/Log.cpp                       ../common/data/entity/Log.hpp
        ../common/data/record/Log.cpp                       ../common/data/record/Log.hpp
        ../common/data/entity/Interval.cpp                  ../common/data/entity/Interval.hpp


        ../server/input/Input.cpp                           ../server/input/Input.hpp
        ../server/input/protocol/GetLogsBetweenEbnf.cpp     ../server/input/protocol/GetLogsBetweenEbnf.h
        ../server/input/protocol/GetLogsBetweenJson.cpp     ../server/input/protocol/GetLogsBetweenJson.h
        ../server/input/protocol/GetLogRecordJson.cpp       ../server/input/protocol/GetLogRecordJson.h
        ../server/input/GetLogsBetween.cpp                  ../server/input/GetLogsBetween.h

        ../server/data/LogRecord.cpp                        ../server/data/LogRecord.h

        ../server/output/Output.cpp                         ../server/output/Output.hpp
        ../server/output/protocol/GetLogsBetweenJson.cpp    ../server/output/protocol/GetLogsBetweenJson.h
        ../server/output/protocol/GetLogsBetweenEbnf.cpp    ../server/output/protocol/GetLogsBetweenEbnf.h
        ../server/output/protocol/GetLogRecordJson.cpp      ../server/output/protocol/GetLogRecordJson.h


        common/algorithm/IntervalKey.cpp                    common/algorithm/IntervalKey.h

        client/input/protocol/GetLogRecordEbnf.cpp          client/input/protocol/GetLogRecordEbnf.hpp
        client/input/protocol/GetLogRecordJson.cpp          client/input/protocol/GetLogRecordJson.hpp
        client/input/protocol/GetLogsBetweenEbnf.cpp        client/input/protocol/GetLogsBetweenEbnf.h
        client/input/protocol/GetLogsBetweenJson.cpp        client/input/protocol/GetLogsBetweenJson.h
        client/output/protocol/GetLogRecordEbnf.cpp         client/output/protocol/GetLogRecordEbnf.hpp
        client/output/protocol/GetLogRecordJson.cpp         client/output/protocol/GetLogRecordJson.hpp
        client/output/protocol/GetLogsBetweenEbnf.cpp       client/output/protocol/GetLogsBetweenEbnf.h
        client/output/protocol/GetLogsBetweenJson.cpp       client/output/protocol/GetLogsBetweenJson.h

        server/input/protocol/GetLogRecordEbnf.cpp          server/input/protocol/GetLogRecordEbnf.hpp
        server/input/protocol/GetLogRecordJson.cpp          server/input/protocol/GetLogRecordJson.h
        server/input/protocol/GetLogsBetweenEbnf.cpp        server/input/protocol/GetLogsBetweenEbnf.h
        server/input/protocol/GetLogsBetweenJson.cpp        server/input/protocol/GetLogsBetweenJson.h
        server/output/protocol/GetLogRecordEbnf.cpp         server/output/protocol/GetLogRecordEbnf.hpp
        server/output/protocol/GetLogsBetweenJson.cpp       server/output/protocol/GetLogsBetweenJson.h
        server/output/protocol/GetLogRecordEbnf.cpp         server/output/protocol/GetLogRecordEbnf.hpp
        server/output/protocol/GetLogRecordJson.cpp         server/output/protocol/GetLogRecordJson.hpp
        server/output/protocol/LogEbnf.cpp                  server/output/protocol/LogEbnf.h

        tools-and-fakes/ResponseFromServerToClient.cpp      tools-and-fakes/ResponseFromServerToClient.hpp
        tools-and-fakes/RequestFromClientToServer.cpp       tools-and-fakes/RequestFromClientToServer.hpp

        client/input/protocol/GetLogRecordEbnf.cpp client/input/protocol/GetLogRecordEbnf.hpp ../client/input/protocol/GetLogRecordEbnf.cpp ../client/input/protocol/GetLogRecordEbnf.hpp)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Network REQUIRED)

set(Boost_DEBUG OFF)
find_package(Boost)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif ()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(gtest
        ${GTEST_LIBRARIES}
        pthread
        Qt5::Core
        Qt5::Sql
        Qt5::Widgets
        )