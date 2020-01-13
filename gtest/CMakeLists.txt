project(gtest)
add_subdirectory(gtest-lib/googletest)
include_directories(${gtest-lib/googletest/googlemock/include/gmock/gmock.h}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})



add_executable(gtest_run main.cpp

        ../client/input/Log.cpp                 ../client/input/Log.h
        ../client/input/GetLogsBetween.cpp      ../client/input/GetLogsBetween.h
        ../client/output/GetLogsBetween.cpp     ../client/output/GetLogsBetween.h
        ../client/model/LogCollection.cpp       ../client/model/LogCollection.h
        ../client/model/LogRecord.cpp           ../client/model/LogRecord.h
        ../common/algorithm/String.cpp          ../common/algorithm/String.h
        ../common/algorithm/Key.cpp             ../common/algorithm/Key.h
        ../server/input/GetLogsBetween.cpp      ../server/input/GetLogsBetween.h

        client/input/Log.cpp                    client/input/Log.h
        client/input/GetLogsBetween.cpp         client/input/GetLogsBetween.h
        client/output/GetLogsBetween.cpp        client/output/GetLogsBetween.h

        common/algorithm/IntervalKey.cpp        common/algorithm/IntervalKey.h

        server/input/GetLogsBetween.cpp         server/input/GetLogsBetween.h

        tools-and-fakes/DataFromServerToClient.cpp  tools-and-fakes/DataFromServerToClient.h

        )



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
