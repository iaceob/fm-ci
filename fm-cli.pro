#-------------------------------------------------
#
# Project created by QtCreator 2016-03-02T16:50:03
#
#-------------------------------------------------

QT       += core gui xml sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fm-cli
TEMPLATE = app
CONFIG     += c++11

DESTDIR     = bin
UI_DIR      = compiled/ui
MOC_DIR     = compiled/moc
OBJECTS_DIR = compiled/obj
RCC_DIR     = compiled/qrc

include(aide/aide.pri)
include(util/util.pri)
include(bean/bean.pri)
include(dao/dao.pri)
include(db/db.pri)

SOURCES += main.cpp

HEADERS  +=

FORMS    +=

DISTFILES += \
    resources/sql/product.sql.xml \
    resources/sql/user.sql.xml \
    resources/config.json
