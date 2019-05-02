#-------------------------------------------------
#
# Project created by QtCreator 2019-02-07T14:24:58
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport
QT       += serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CharlyRobot
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        CharlyRobot.cpp \
    reglage.cpp \
    reglagefraise.cpp \
    visuel.cpp \
    CharlyRobot.cpp \
    dl_dxf.cpp \
    dl_writer_ascii.cpp \
    filtreDxf.cpp \
    LSerie.cpp \
    main.cpp \
    PilotageCharlyRobot.cpp \
    test_creationclass.cpp

HEADERS += \
        CharlyRobot.h \
    reglage.h \
    reglagefraise.h \
    visuel.h \
    CharlyRobot.h \
    dl_attributes.h \
    dl_codes.h \
    dl_creationadapter.h \
    dl_creationinterface.h \
    dl_dxf.h \
    dl_entities.h \
    dl_exception.h \
    dl_extrusion.h \
    dl_global.h \
    dl_writer.h \
    dl_writer_ascii.h \
    filtreDxf.h \
    LSerie.h \
    PilotageCharlyRobot.h \
    test_creationclass.h

FORMS += \
        CharlyRobot.ui \
    reglage.ui \
    reglagefraise.ui \
    visuel.ui
