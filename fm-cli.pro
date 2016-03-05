#-------------------------------------------------
#
# Project created by QtCreator 2016-03-02T16:50:03
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fm-cli
TEMPLATE = app


SOURCES += main.cpp\
        view/mainwindow.cpp \
    nav/navdelegate.cpp \
    nav/navmodel.cpp \
    view/orderdelete.cpp \
    model/ordermodel.cpp \
    common/navselect.cpp \
    view/batchordermulti.cpp

HEADERS  += view/mainwindow.h \
    nav/colordefines.h \
    nav/navdelegate.h \
    navview.h \
    nav/navmodel.h \
    view/orderdelete.h \
    model/ordermodel.h \
    common/navtype.h \
    common/navselect.h \
    view/batchordermulti.h

FORMS    += view/mainwindow.ui \
    view/orderdelete.ui \
    view/batchordermulti.ui

RESOURCES += \
    res.qrc

RC_FILE = fm-cli.rc
