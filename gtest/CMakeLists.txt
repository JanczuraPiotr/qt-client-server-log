project(gtest)
add_subdirectory(gtest-lib/googletest)
include_directories(${gtest-lib/googletest/googlemock/include/gmock/gmock.h}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})



add_executable(gtest_run main.cpp

        ../client/input/Log.cpp                 ../client/input/Log.h

        ../server/input/GetLogsAfter.cpp        ../server/input/GetLogsAfter.h
        ../server/input/GetLogsBefore.cpp       ../server/input/GetLogsBefore.h
        ../server/input/GetLogsBetween.cpp      ../server/input/GetLogsBetween.h
        ../common/algorithm/Key.cpp ../common/algorithm/Key.h

        client/input/LogTest.cpp                client/input/LogTest.h

        server/input/GetLogsBeforeTest.cpp      server/input/GetLogsBeforeTest.h
        server/input/GetLogsBetweenTest.cpp     server/input/GetLogsBetweenTest.h
        server/input/GetLogsAfterTest.cpp       server/input/GetLogsAfterTest.h
        common/algorithm/IntervalKeyTest.cpp common/algorithm/IntervalKeyTest.h)



target_link_libraries(gtest_run
        gtest
        gtest_main
        Qt5::Core
        Qt5::Network
        )