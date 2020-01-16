set(CLIENT client)
project(${CLIENT})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++ -MMD -MP -MF")

add_executable(${CLIENT}
        main.cpp

                                                    ../common/def.h
        ../server/app/ConfigFile.cpp                ../server/app/ConfigFile.h
        ../common/exception/general.cpp             ../common/exception/general.h
        ../common/output/ErrorMessage.cpp           ../common/output/ErrorMessage.h
        ../common/algorithm/Key.cpp                 ../common/algorithm/Key.h
        ../common/algorithm/String.cpp              ../common/algorithm/String.h

        controller/Main.cpp                         controller/Main.h
        controller/Net.cpp                          controller/Net.h
        input/GetLogsBetween.cpp                    input/GetLogsBetween.h
        input/Log.cpp                               input/Log.h
        model/LogRecord.cpp                         model/LogRecord.h
        model/LogCollection.cpp                     model/LogCollection.h
        output/component/GetLogsBetweenJson.cpp output/component/GetLogsBetweenJson.h
        view/MainWindow.cpp                         view/MainWindow.h
        view/table/Logs.cpp                         view/table/Logs.h
        view/dialogs/LogsBetween.cpp                view/dialogs/LogsBetween.h
        view/windows/Logs.cpp                       view/windows/Logs.h
        input/component/GetLogsBetweenJson.cpp input/component/GetLogsBetweenJson.h input/component/GetLogsBetweenEbnf.cpp input/component/GetLogsBetweenEbnf.h output/component/GetLogsBetweenEbnf.cpp output/component/GetLogsBetweenEbnf.h output/GetLogsBetween.cpp output/GetLogsBetween.h)

qt5_use_modules(${CLIENT}
        Core
        Network
        WebSockets
        Widgets
        Sql
        )
