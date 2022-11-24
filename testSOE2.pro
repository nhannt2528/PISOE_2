QT       += core gui serialbus network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DI.cpp \
    localstore.cpp \
    main.cpp \
    mainwindow.cpp \
    modbustcp.cpp \
    task_spi.cpp \
    timetypes.cpp

HEADERS += \
    DI.h \
    diCard.h \
    localstore.h \
    mainwindow.h \
    modbustcp.h \
    task_spi.h \
    timetypes.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target





#unix|win32: LIBS += -lwiringPi
#unix|win32: LIBS += -lwiringPiDev
LIBS += -lwiringPi
target.path = /home/pi/testSOE2/bin
INSTALLS += target
HEADERS +=
