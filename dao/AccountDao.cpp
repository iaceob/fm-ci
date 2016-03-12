#include "AccountDao.h"

const char * const SQL_NAMESPACE = "Account";

QVariantMap AccountDao::getSignInUsr(QString serial) {
    QString sql = Singleton<Sqls>::getInstance().getSql(SQL_NAMESPACE, "getSignInUsr");
    // QString sql = QString("select uid, user_serial, user_name, user_passwd, user_email, user_status from nwfm_user where user_serial=%1").arg(serial);
    QVariantMap params;
    params["serial"] = serial;
    return DBUtil::selectMap(sql, params);
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
