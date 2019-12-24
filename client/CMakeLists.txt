set(CLIENT client)
project(${CLIENT})


add_executable(${CLIENT}
        main.cpp

                                                    ../common/def.h
        ../server/app/ConfigFile.cpp                ../server/app/ConfigFile.h
        ../common/exception/general.cpp             ../common/exception/general.h
#        ../common/algorithm/StringToDateTime.cpp    ../common/algorithm/StringToDateTime.h
#        ../common/exception/general.cpp             ../common/exception/general.h
        ../common/output/ErrorMessage.cpp           ../common/output/ErrorMessage.h
#
        controller/Main.cpp                         controller/Main.h
        controller/Net.cpp                          controller/Net.h
        input/Log.cpp                               input/Log.h
        model/LogRecord.cpp                         model/LogRecord.h
        model/LogCollection.cpp                     model/LogCollection.h
        view/MainWindow.cpp                         view/MainWindow.h
        view/LogsTable.cpp                          view/LogsTable.h
        )

#find_package(Qt5Widgets REQUIRED)

qt5_use_modules(${CLIENT}
        Core
        Network
        WebSockets
        Widgets
        Sql
        )
