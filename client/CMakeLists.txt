set(CLIENT client)
project(${CLIENT})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++ -MMD -MP -MF")

add_executable(${CLIENT}
        main.cpp

                                                    ../common/def.h
        ../server/app/ConfigFile.cpp                ../server/app/ConfigFile.h
        ../common/exception/general.cpp             ../common/exception/general.h
        ../common/output/ErrorMessage.cpp           ../common/output/ErrorMessage.h

        controller/Main.cpp                         controller/Main.h
        controller/Net.cpp                          controller/Net.h
        input/Log.cpp                               input/Log.h
        model/LogRecord.cpp                         model/LogRecord.h
        model/LogCollection.cpp                     model/LogCollection.h
        view/MainWindow.cpp                         view/MainWindow.h
        view/LogsTable.cpp                          view/LogsTable.h
        view/dialogs/LogsAfter.cpp                  view/dialogs/LogsAfter.h
        view/dialogs/LogsBefore.cpp                 view/dialogs/LogsBefore.h
        view/dialogs/LogsBetween.cpp                view/dialogs/LogsBetween.h
        )

#find_package(Qt5Widgets REQUIRED)

qt5_use_modules(${CLIENT}
        Core
        Network
        WebSockets
        Widgets
        Sql
        )
