#-------------------------------------------------
#
# Project created by QtCreator 2012-11-29T11:20:47
#
#-------------------------------------------------

QT       += core gui

TARGET = move-object
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    customgraphicsview.cpp

HEADERS  += window.hpp \
    customgraphicsview.hpp

FORMS    += window.ui

RESOURCES += \
    images.qrc

win32:RC_FILE += moving-object.rc
