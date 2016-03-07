
QT       += core gui xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += $$PWD/view/mainwindow.cpp \
    $$PWD/nav/navdelegate.cpp \
    $$PWD/nav/navmodel.cpp \
    $$PWD/model/ordermodel.cpp \
    $$PWD/common/navselect.cpp \
    $$PWD/view/order/batchordermulti.cpp\
    $$PWD/view/order/orderdelete.cpp\
    $$PWD/view/usr/loginwidget.cpp \
    $$PWD/common/qmenubutton.cpp \
    $$PWD/common/aidelanguage.cpp

HEADERS  += $$PWD/view/mainwindow.h \
    $$PWD/nav/colordefines.h \
    $$PWD/nav/navdelegate.h \
    $$PWD/nav/navmodel.h \
    $$PWD/view/order/orderdelete.h \
    $$PWD/model/ordermodel.h \
    $$PWD/common/navtype.h \
    $$PWD/common/navselect.h \
    $$PWD/view/order/batchordermulti.h \
    $$PWD/view/usr/loginwidget.h \
    $$PWD/common/qmenubutton.h \
    $$PWD/common/aidelanguage.h \
    $$PWD/common/aideproject.h

FORMS    += $$PWD/view/mainwindow.ui \
    $$PWD/view/order/orderdelete.ui \
    $$PWD/view/order/batchordermulti.ui \
    $$PWD/view/usr/loginwidget.ui



RESOURCES += \
    $$PWD/res.qrc \


RC_FILE = $$PWD/fm-cli.rc


TRANSLATIONS = \
    $$PWD/aide_en_US.ts \
    $$PWD/aide_zh_CN.ts \
    $$PWD/aide_zh_TW.ts
