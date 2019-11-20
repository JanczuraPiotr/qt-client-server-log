set(CLIENT client)
project(${CLIENT})


add_executable(${CLIENT}
        main.cpp
        ../common/exception/general.cpp     ../common/exception/general.h
        ../server/app/ConfigFile.cpp        ../server/app/ConfigFile.h
        controller/Net.cpp                  controller/Net.h
        )

qt5_use_modules(${CLIENT}
        Core
        Network
        WebSockets
        Sql
        )
