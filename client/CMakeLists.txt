set(CLIENT client)
project(${CLIENT})


add_executable(${CLIENT}
        main.cpp
        )

target_link_libraries(${CLIENT}
        Qt5::Core
        )