project(gtest)
add_subdirectory(gtest-lib/googletest)
include_directories(${gtest-lib/googletest/googlemock/include/gmock/gmock.h}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})



add_executable(gtest_run main.cpp

        ../client/input/component/GetLogsBetweenEbnf.cpp
        ../client/input/component/GetLogsBetweenEbnf.h
        ../client/input/component/GetLogsBetweenJson.cpp
        ../client/input/component/GetLogsBetweenJson.h
        ../client/input/component/LogEbnf.cpp
        ../client/input/component/LogEbnf.h
        ../client/input/component/LogJson.cpp
        ../client/input/component/LogJson.h
        ../client/input/GetLogsBetween.cpp
        ../client/input/GetLogsBetween.h
        ../client/input/Log.cpp
        ../client/input/Log.h
        ../client/model/LogCollection.cpp
        ../client/model/LogCollection.h
        ../client/model/LogRecord.cpp
        ../client/model/LogRecord.h
        ../client/output/component/GetLogsBetweenEbnf.cpp
        ../client/output/component/GetLogsBetweenEbnf.h
        ../client/output/component/GetLogsBetweenJson.cpp
        ../client/output/component/GetLogsBetweenJson.h
        ../client/output/GetLogsBetween.cpp
        ../client/output/GetLogsBetween.h

        ../common/algorithm/String.cpp
        ../common/algorithm/String.h
        ../common/algorithm/Key.cpp
        ../common/algorithm/Key.h
        ../common/db/Record.cpp
        ../common/db/Record.h

        common/algorithm/IntervalKey.cpp
        common/algorithm/IntervalKey.h

        client/input/GetLogsBetweenEbnf.cpp
        client/input/GetLogsBetweenEbnf.h
        client/input/GetLogsBetweenJson.cpp
        client/input/GetLogsBetweenJson.h
        client/input/LogEbnf.cpp
        client/input/LogEbnf.h
        client/input/LogJson.cpp
        client/input/LogJson.h
        client/output/GetLogsBetweenJson.cpp
        client/output/GetLogsBetweenJson.h
        client/output/GetLogsBetweenEbnf.cpp
        client/output/GetLogsBetweenEbnf.h

        server/input/GetLogsBetweenEbnf.cpp
        server/input/GetLogsBetweenEbnf.h
        server/input/GetLogsBetweenJson.cpp
        server/input/GetLogsBetweenJson.h
        server/output/LogEbnf.cpp
        server/output/LogEbnf.h
        server/output/LogJson.cpp
        server/output/LogJson.h

        tools-and-fakes/DataFromServerToClient.cpp
        tools-and-fakes/DataFromServerToClient.h

        ../server/input/components/GetLogsBetweenEbnf.cpp
        ../server/input/components/GetLogsBetweenEbnf.h
        ../server/input/components/GetLogsBetweenJson.cpp
        ../server/input/components/GetLogsBetweenJson.h
        ../server/input/GetLogsBetween.cpp
        ../server/input/GetLogsBetween.h
        ../server/model/LogRecord.cpp
        ../server/model/LogRecord.h
        ../server/output/component/LogJson.cpp
        ../server/output/component/LogJson.h
        ../server/output/component/LogEbnf.cpp
        ../server/output/component/LogEbnf.h
        ../server/output/Log.cpp
        ../server/output/Log.h

        )

set(Boost_DEBUG OFF)
find_package(Boost)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif ()


target_link_libraries(gtest_run
        gtest
        gtest_main
        )

qt5_use_modules(gtest_run
        Core
        Network
        WebSockets
        Widgets
        Sql
        )
