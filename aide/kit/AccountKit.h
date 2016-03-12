#ifndef ACCOUNTKIT_H
#define ACCOUNTKIT_H

#include <QString>
#include <QDebug>
#include <QTextCodec>
#include <QVariantMap>

#include "aide/common/AideConst.h"

class AccountKit {

public:
    /**
     * @brief encryAccountInfo 加密登錄賬戶信息
     * @param uid 賬戶 id
     * @param serial 賬戶編號
     * @param name 賬戶名
     * @param email 郵箱
     * @return
     */
    static QString encryAccountInfo(const QString &uid, const QString &serial, const QString &name, const QString &email);
    /**
     * @brief getXorEncryptDecrypt 一個不靠譜的加密以及解密方案, 此處放開作為解密用
     * @param str 加密字符串
     * @param key 加密 KEY
     * @return QString
     */
    static QString getXorEncryptDecrypt(const QString &str, const char &key);
    static void setAccount(const QString &uid, const QString &serial, const QString &name, const QString &email);
    static QVariantMap getAccount();

private:
    static QVariantMap account;
    static QString byteToQString(const QByteArray &byte);
    static QByteArray qstringToByte(const QString &strInfo);

};

#endif // ACCOUNTKIT_H
