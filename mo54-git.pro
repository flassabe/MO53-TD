TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        average.cpp \
        calculation.cpp \
        data_list.cpp \
        data_table.cpp \
        main.cpp \
        moving_average.cpp \
        rolling_average.cpp \
        table_count.cpp \
        table_sum.cpp

HEADERS += \
    average.h \
    calculation.h \
    data_list.h \
    data_table.h \
    moving_average.h \
    rolling_average.h \
    table_count.h \
    table_sum.h
