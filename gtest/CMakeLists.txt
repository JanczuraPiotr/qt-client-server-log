project(gtest)
add_subdirectory(gtest-lib/googletest)
include_directories(${gtest-lib/googletest/googlemock/include/gmock/gmock.h}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(gtest_run main.cpp
        )


target_link_libraries(gtest_run
        gtest
        gtest_main
        Qt5::Core
        Qt5::Network
        Qt5::Sql
        )