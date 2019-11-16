set(SERVER server)
project(${SERVER})


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

        app/ConfigFile.cpp                  app/ConfigFile.h
        app/SignalBus.cpp                   app/SignalBus.h
        model/LogCollection.cpp             model/LogCollection.h
        model/LogRecord.cpp                 model/LogRecord.h
        action/InsertLog.cpp                action/InsertLog.h
        FakeEvent.cpp                       FakeEvent.h

        service/NetConnection.cpp           service/NetConnection.h
        )

#target_link_libraries(${SERVER}

#        )

qt5_use_modules(${SERVER}
        Core
        Network
        WebSockets
        Sql
        )
