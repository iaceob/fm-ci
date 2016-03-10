
#include <QApplication>
#include <QTranslator>
#include <QtDebug>
#include <QDir>

#include "aide/view/mainwindow.h"
#include "aide/view/usr/loginwidget.h"
#include "aide/common/aidelanguage.h"

//  test =======
#include "db/ConnectionPool.h"
#include "util/ConfigUtil.h"
#include "db/DBUtil.h"
#include "dao/AccountDao.h"

void dbTest();

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QString translatorFileName = QString("%1/lan/aide%2.qm").arg(QDir::currentPath()).arg(AideLanguage::getLanguage());
    QTranslator *translator = new QTranslator(&a);
    if (translator->load(translatorFileName)) {
        a.installTranslator(translator);
    }

    MainWindow w;
    LoginWidget lw;
    QObject::connect(&lw, SIGNAL(loginComplete()), &w, SLOT(showWindow()));

    lw.show();

    // dbTest();

    // Singleton<ConnectionPool>::getInstance().destroy();
    return a.exec();
}

void dbTest() {
    qDebug() << "\n1. 查找 Alice 的 ID";
    qDebug() << DBUtil::selectString("select uid from nwfm_user where user_serial='fm001'");

    QVariantMap account =  AccountDao::getSignInUsr("FM001");
    qDebug() << account.value("uid").toString();
}
