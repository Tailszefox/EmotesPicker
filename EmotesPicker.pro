#-------------------------------------------------
#
# Project created by QtCreator 2015-03-08T21:56:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#QT += KEmoticons

TARGET = EmotesPicker
TEMPLATE = app

INCLUDEPATH += /usr/include/KDE
INCLUDEPATH += /usr/include

LIBS += -lkdeui

SOURCES += main.cpp\
    actualpicker.cpp

HEADERS  += \
    actualpicker.h

FORMS    += \
    actualpicker.ui
