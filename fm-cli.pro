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
    model/ordermodel.cpp \
    common/navselect.cpp \
    view/order/batchordermulti.cpp\
    view/order/orderdelete.cpp\
    view/usr/loginwidget.cpp \
    common/qmenubutton.cpp \
    common/aidelanguage.cpp

HEADERS  += view/mainwindow.h \
    nav/colordefines.h \
    nav/navdelegate.h \
    navview.h \
    nav/navmodel.h \
    view/order/orderdelete.h \
    model/ordermodel.h \
    common/navtype.h \
    common/navselect.h \
    view/order/batchordermulti.h \
    view/usr/loginwidget.h \
    common/qmenubutton.h \
    common/aidelanguage.h

FORMS    += view/mainwindow.ui \
    view/order/orderdelete.ui \
    view/order/batchordermulti.ui \
    view/usr/loginwidget.ui

RESOURCES += \
    res.qrc \

RC_FILE = fm-cli.rc

TRANSLATIONS = aide_zh_CN.ts \
    aide_zh_TW.ts \
    aide_en_US.ts
