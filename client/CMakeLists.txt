set(CLIENT client)
project(${CLIENT})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++ -MMD -MP -MF")

add_executable(${CLIENT}
        main.cpp

        controller/Main.cpp
        controller/Main.h
        controller/Net.cpp
        controller/Net.h

        input/protocol/GetLogsBetweenEbnf.cpp
        input/protocol/GetLogsBetweenEbnf.h
        input/protocol/GetLogsBetweenJson.cpp
        input/protocol/GetLogsBetweenJson.h
        input/GetLogsBetween.cpp
        input/GetLogsBetween.h
        input/Log.cpp
        input/Log.h

        model/LogCollection.cpp
        model/LogCollection.h
        model/LogRecord.cpp
        model/LogRecord.h

        output/protocol/GetLogsBetweenEbnf.cpp
        output/protocol/GetLogsBetweenEbnf.h
        output/protocol/GetLogsBetweenJson.cpp
        output/protocol/GetLogsBetweenJson.h
        output/GetLogsBetween.cpp
        output/GetLogsBetween.h

        view/dialogs/LogsBetween.cpp
        view/dialogs/LogsBetween.h
        view/table/Logs.cpp
        view/table/Logs.h
        view/windows/Logs.cpp
        view/windows/Logs.h
        view/MainWindow.cpp
        view/MainWindow.h

        ../common/algorithm/Key.cpp
        ../common/algorithm/Key.h
        ../common/algorithm/String.cpp
        ../common/algorithm/String.h
        ../common/exception/general.cpp
        ../common/exception/general.h

        ../common/output/ErrorMessage.cpp
        ../common/output/ErrorMessage.h
        ../common/def.h

        ../server/app/ConfigFile.cpp
        ../server/app/ConfigFile.h
        )

qt5_use_modules(${CLIENT}
        Core
        Network
        WebSockets
        Widgets
        Sql
        )
