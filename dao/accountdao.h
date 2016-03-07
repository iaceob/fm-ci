#ifndef ACCOUNTDAO_H
#define ACCOUNTDAO_H

#include <QList>
#include <QString>
#include <QVariant>
#include <QVariantMap>

class Account;

class AccountDao {
public:
    static QList<Account> getUsrList();
    static Account getUsrById(QString id);
private:
    static Account mapToUser(const QVariantMap &rowMap);
};

#endif // ACCOUNTDAO_H
