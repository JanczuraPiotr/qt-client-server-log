project(gtest)

add_executable(gtest main.cpp

        ../client/input/protocol/GetLogsBetweenEbnf.cpp     ../client/input/protocol/GetLogsBetweenEbnf.h
        ../client/input/protocol/GetLogsBetweenJson.cpp     ../client/input/protocol/GetLogsBetweenJson.h
        ../client/input/protocol/LogEbnf.cpp                ../client/input/protocol/LogEbnf.h
        ../client/input/protocol/LogJson.cpp                ../client/input/protocol/LogJson.h
        ../client/input/GetLogsBetween.cpp                  ../client/input/GetLogsBetween.h
        ../client/input/Log.cpp                             ../client/input/Log.h
        ../client/data/LogCollection.cpp ../client/data/LogCollection.h
        ../client/data/LogRecord.cpp ../client/data/LogRecord.h
        ../client/output/protocol/GetLogsBetweenEbnf.cpp    ../client/output/protocol/GetLogsBetweenEbnf.h
        ../client/output/protocol/GetLogsBetweenJson.cpp    ../client/output/protocol/GetLogsBetweenJson.h
        ../client/output/GetLogsBetween.cpp                 ../client/output/GetLogsBetween.h

        ../common/algorithm/String.cpp                      ../common/algorithm/String.h
        ../common/algorithm/Key.cpp                         ../common/algorithm/Key.h
        ../common/db/Record.cpp                             ../common/db/Record.h

        ../server/input/Input.cpp                           ../server/input/Input.hpp
        ../server/input/protocol/GetLogsBetweenEbnf.cpp     ../server/input/protocol/GetLogsBetweenEbnf.h
        ../server/input/protocol/GetLogsBetweenJson.cpp     ../server/input/protocol/GetLogsBetweenJson.h
        ../server/input/GetLogsBetween.cpp                  ../server/input/GetLogsBetween.h

        ../server/data/LogRecord.cpp ../server/data/LogRecord.h

        ../server/output/Output.cpp                         ../server/output/Output.hpp
        ../server/output/protocol/LogJson.cpp               ../server/output/protocol/LogJson.h
        ../server/output/protocol/LogEbnf.cpp               ../server/output/protocol/LogEbnf.h


        common/algorithm/IntervalKey.cpp                    common/algorithm/IntervalKey.h

        client/input/GetLogsBetweenEbnf.cpp                 client/input/GetLogsBetweenEbnf.h
        client/input/GetLogsBetweenJson.cpp                 client/input/GetLogsBetweenJson.h
        client/input/LogEbnf.cpp                            client/input/LogEbnf.h
        client/input/LogJson.cpp                            client/input/LogJson.h
        client/output/GetLogsBetweenJson.cpp                client/output/GetLogsBetweenJson.h
        client/output/GetLogsBetweenEbnf.cpp                client/output/GetLogsBetweenEbnf.h

        server/input/GetLogsBetweenEbnf.cpp                 server/input/GetLogsBetweenEbnf.h
        server/input/GetLogsBetweenJson.cpp                 server/input/GetLogsBetweenJson.h
        server/output/protocol/LogEbnf.cpp                  server/output/protocol/LogEbnf.h
        server/output/protocol/LogJson.cpp                  server/output/protocol/LogJson.h

        tools-and-fakes/ResponseFromServerToClient.cpp      tools-and-fakes/ResponseFromServerToClient.hpp
        tools-and-fakes/RequestFromClientToServer.cpp       tools-and-fakes/RequestFromClientToServer.hpp

        )

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