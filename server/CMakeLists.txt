set(SERVER server)
project(${SERVER})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++ -MMD -MP -MF")

add_executable(${SERVER}
        main.cpp
        ../common/exception/general.cpp     ../common/exception/general.h

        ../common/db/exception.cpp          ../common/db/exception.h
        ../common/db/Db.cpp                 ../common/db/Db.h
        ../common/db/Connection.cpp         ../common/db/Connection.h
        ../common/db/Collection.cpp         ../common/db/Collection.h
        ../common/db/Record.cpp             ../common/db/Record.h
        ../common/db/Structure.cpp          ../common/db/Structure.h
        ../common/db/SQLiteConnection.cpp   ../common/db/SQLiteConnection.h
        ../common/db/SQLiteStructure.cpp    ../common/db/SQLiteStructure.h
        ../common/algorithm/Key.cpp         ../common/algorithm/Key.h


        ../common/output/ErrorMessage.cpp   ../common/output/ErrorMessage.h

        action/InsertLog.cpp                action/InsertLog.h

        app/ConfigFile.cpp                  app/ConfigFile.h
        app/SignalBus.cpp                   app/SignalBus.h

        input/GetLogsBetween.cpp            input/GetLogsBetween.h

        model/LogCollection.cpp             model/LogCollection.h
        model/LogRecord.cpp                 model/LogRecord.h

        output/Log.cpp                      output/Log.h

        service/FakeEvent.cpp               service/FakeEvent.h
        service/NetConnection.cpp           service/NetConnection.h
        service/Main.cpp                    service/Main.h
        )

qt5_use_modules(${SERVER}
        Core
        Network
        WebSockets
        Sql
        )
