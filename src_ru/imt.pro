TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        counter.cpp \
        data.cpp \
        helper.cpp \
        imtmaker.cpp \
        main.cpp

HEADERS += \
    counter.h \
    data.h \
    enums.h \
    helper.h \
    imtmaker.h
