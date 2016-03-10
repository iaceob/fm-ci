#ifndef ACCOUNTDAO_H
#define ACCOUNTDAO_H

#include <QList>
#include <QString>
#include <QVariant>
#include <QVariantMap>
#include <QtDebug>
#include "bean/account.h"
#include "db/DBUtil.h"
#include "db/Sqls.h"

class Account;

class AccountDao {
public:
    static QVariantMap getSignInUsr(QString serial);
private:
    static Account mapToUser(const QVariantMap &rowMap);
};

#endif // ACCOUNTDAO_H
