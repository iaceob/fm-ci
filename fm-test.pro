#-------------------------------------------------
#
# Project created by QtCreator 2016-03-02T16:50:03
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fm-test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    navmodel.cpp \
    navdelegate.cpp \
    navview.cpp

HEADERS  += mainwindow.h \
    navmodel.h \
    colordefines.h \
    navdelegate.h \
    navview.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
