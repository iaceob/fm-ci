
#include <QApplication>
#include <QTranslator>
#include <QtDebug>
#include <QFile>
#include <QDir>

#include "aide/view/MainWindow.h"
#include "aide/view/usr/LoginWidget.h"
#include "aide/common/AideLanguage.h"
#include "aide/common/AideConst.h"

//  test =======
#include "db/ConnectionPool.h"
#include "util/ConfigUtil.h"
#include "db/DBUtil.h"
#include "dao/AccountDao.h"

void dbTest();

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    /*
     * 程序啟動後檢測程序存儲路徑是否存在, 不存在則創建
     */
    if (!QFile::exists(AIDE_DATA_PATH)) {
        QDir *saveLanDir = new QDir;
        saveLanDir->mkpath(AIDE_DATA_PATH);
    }

    /*
     * 檢測程序是否已經開啟
     */
    QString lockFile = QString("%1/%2").arg(AIDE_DATA_PATH).arg(AIDE_SAVE_LOCK);
    if (!AIDE_DEBUG) {
        if (QFile::exists(lockFile)) {
            QMessageBox::information(NULL, QObject::tr("提示"), QObject::tr("%1 以開啟").arg(AIDE_NAME));
            return 0;
        }
    }

    /*
     * 啟動後裝載相應的語言包
     */
    QString translatorFileName = QString("%1/lan/aide_%2.qm").arg(QDir::currentPath()).arg(AideLanguage::getLanguage());
    qDebug() << translatorFileName;
    QTranslator *translator = new QTranslator(&a);
    if (translator->load(translatorFileName)) {
        a.installTranslator(translator);
    }

    /*
     * 主窗體啟動
     */
    MainWindow w;
    LoginWidget lw;
    QObject::connect(&lw, SIGNAL(loginComplete()), &w, SLOT(showWindow()));
    // TODO  檢測是否保持登入, 若是則直接啟動 MainWIndow 窗口, 而非登入窗口
    lw.show();

    /*
     * 啟動後寫入啟動鎖文件
     */
    QFile *file = new QFile();
    file->setFileName(lockFile);
    bool opend = file->open(QIODevice::WriteOnly);
    QTextStream out(file);
    out << "";
    file->close();
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
