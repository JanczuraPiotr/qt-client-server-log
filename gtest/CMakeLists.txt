project(gtest)
add_subdirectory(gtest-lib/googletest)
include_directories(${gtest-lib/googletest/googlemock/include/gmock/gmock.h}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})



add_executable(gtest_run main.cpp

        ../client/input/Log.cpp                 ../client/input/Log.h
        ../client/input/GetLogsBetween.cpp      ../client/input/GetLogsBetween.h
        ../client/output/GetLogsBetween.cpp     ../client/output/GetLogsBetween.h
        ../common/algorithm/Key.cpp             ../common/algorithm/Key.h
        ../server/input/GetLogsBetween.cpp      ../server/input/GetLogsBetween.h

        client/input/Log.cpp                    client/input/Log.h
        client/input/GetLogsBetween.cpp         client/input/GetLogsBetween.h
        client/output/GetLogsBetween.cpp        client/output/GetLogsBetween.h

        common/algorithm/IntervalKey.cpp        common/algorithm/IntervalKey.h

        server/input/GetLogsBetween.cpp         server/input/GetLogsBetween.h
        )



target_link_libraries(gtest_run
        gtest
        gtest_main
        Qt5::Core
        Qt5::Network
        )