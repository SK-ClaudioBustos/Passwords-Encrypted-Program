TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        credential.cpp \
        credentials_manager.cpp \
        main.cpp \
        password.cpp

HEADERS += \
    credential.h \
    credentials_manager.h \
    password.h
