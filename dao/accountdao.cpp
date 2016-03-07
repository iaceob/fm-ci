#include "accountdao.h"
#include "bean/account.h"
#include "db/DBUtil.h"
#include "db/Sqls.h"
#include <QtDebug>

const char * const SQL_NAMESPACE_USER = "Account";

QList<Account> AccountDao::getUsrList() {
    QString sql = Singleton<Sqls>::getInstance().getSql(SQL_NAMESPACE_USER, "findAll");
    qDebug() << sql;
    return DBUtil::selectBeans(mapToUser, sql);
}

Account AccountDao::getUsrById(QString id) {
    QString sql = Singleton<Sqls>::getInstance().getSql(SQL_NAMESPACE_USER, "findByUserId");
    QVariantMap params;
    params["id"] = id;
    return DBUtil::selectBean(mapToUser, sql, params);
}

Account AccountDao::mapToUser(const QVariantMap &rowMap) {
    Account account;

    account.id = rowMap.value("id", -1).toString();
    account.name = rowMap.value("name").toString();
    account.passwd = rowMap.value("passwd").toString();
    account.email = rowMap.value("email").toString();
    // account.ctime = rowMap.value("ctime").toString();
    return account;
}
