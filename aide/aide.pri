
QT       += core gui xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    $$PWD/kit/AccountKit.cpp \
    $$PWD/common/AideLanguage.cpp \
    $$PWD/common/NavSelect.cpp \
    $$PWD/common/QMenuButton.cpp \
    $$PWD/view/usr/LoginWidget.cpp \
    $$PWD/view/order/BatchOrderiMulti.cpp \
    $$PWD/view/order/OrderDelete.cpp \
    $$PWD/view/MainWindow.cpp \
    $$PWD/nav/NavModel.cpp \
    $$PWD/nav/NavDelegate.cpp

HEADERS  += \
    $$PWD/kit/AccountKit.h \
    $$PWD/common/AideLanguage.h \
    $$PWD/common/NavSelect.h \
    $$PWD/common/NavType.h \
    $$PWD/common/QMenuButton.h \
    $$PWD/view/usr/LoginWidget.h \
    $$PWD/view/order/BatchOrderiMulti.h \
    $$PWD/view/order/OrderDelete.h \
    $$PWD/view/MainWindow.h \
    $$PWD/nav/NavModel.h \
    $$PWD/nav/NavDelegate.h \
    $$PWD/nav/ColorDefines.h \
    $$PWD/common/AideConst.h

FORMS    += \
    $$PWD/view/usr/LoginWidget.ui \
    $$PWD/view/order/OrderDelete.ui \
    $$PWD/view/order/BatchOrderMulti.ui \
    $$PWD/view/MainWindow.ui



RESOURCES += \
    $$PWD/res.qrc \


RC_FILE = $$PWD/fm-cli.rc


TRANSLATIONS = \
    $$PWD/aide_en_US.ts \
    $$PWD/aide_zh_CN.ts \
    $$PWD/aide_zh_TW.ts
