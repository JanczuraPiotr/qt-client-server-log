set(SERVER server)
project(${SERVER})


add_executable(${SERVER}
        main.cpp
        ConfigFile.cpp                  ConfigFile.h
        ../common/exception/general.cpp     ../common/exception/general.h

        ../common/db/Db.cpp                 ../common/db/Db.h
        ../common/db/Connection.cpp         ../common/db/Connection.h
        ../common/db/Collection.cpp         ../common/db/Collection.h
        ../common/db/Record.cpp             ../common/db/Record.h
        ../common/db/Structure.cpp          ../common/db/Structure.h
        ../common/db/SQLiteConnection.cpp   ../common/db/SQLiteConnection.h
        ../common/db/SQLiteStructure.cpp    ../common/db/SQLiteStructure.h

        model/LogCollection.cpp             model/LogCollection.h
        model/LogRecord.cpp                 model/LogRecord.h
        )

target_link_libraries(${SERVER}
        Qt5::Core
        Qt5::Sql
        )
