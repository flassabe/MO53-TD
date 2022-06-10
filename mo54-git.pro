TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        calculation.cpp \
        data_list.cpp \
        data_table.cpp \
        loader.cpp \
        main.cpp \
        manager.cpp \
        process.cpp \
        storage_type.cpp \
        writer.cpp

HEADERS += \
    calculation.h \
    data_list.h \
    data_table.h \
    loader.h \
    manager.h \
    process.h \
    storage_type.h \
    writer.h
