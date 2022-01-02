QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_credential_window.cpp \
    change_password_window.cpp \
    credential.cpp \
    erase_credential_window.cpp \
    input_password_window.cpp \
    main.cpp \
    mainwindow.cpp \
    new_password_window.cpp \
    password.cpp  \
    credentials_manager.cpp

HEADERS += \
    add_credential_window.h \
    change_password_window.h \
    erase_credential_window.h \
    input_password_window.h \
    mainwindow.h \
    new_password_window.h \
    password.h \
    credential.h \
    credentials_manager.h

FORMS += \
    add_credential_window.ui \
    change_password_window.ui \
    erase_credential_window.ui \
    input_password_window.ui \
    mainwindow.ui \
    new_password_window.ui

TRANSLATIONS += \
    Passwords_Encrypted_Program_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

