#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QDateTime>

class Account {
public:
    Account();

    QString id;
    QString name;
    QString email;
    QString passwd;
    int stat;
    QDateTime ctime;

    // const QString toString();
};

#endif // ACCOUNT_H
