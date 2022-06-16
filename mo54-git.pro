TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        data_list.cpp \
        data_table.cpp \
        main.cpp \
        moving_average.cpp \
        sort_table.cpp \
        table_count.cpp \
        table_sum.cpp

HEADERS += \
    average2.h \
    calculation.h \
    data_list.h \
    data_table.h \
    moving_average.h \
    sort_table.h \
    table_count.h \
    table_sum.h
