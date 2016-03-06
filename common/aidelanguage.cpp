#include "aidelanguage.h"

AideLanguage::AideLanguage()  {

}

QString AideLanguage::saveLanFile = QDir::currentPath() + "/lan/lan.save";

/**
 * 保存選擇的語言到文件中, 供下次登錄後設定默認語言
 * @brief AideLanguage::saveLanguage
 * @param lan
 */
void AideLanguage::saveLanguage(QString lan) {
    QFile *file = new QFile;
    file->setFileName(AideLanguage::saveLanFile );
    bool opend = file->open(QIODevice::WriteOnly);
    if (!opend) {
        QMessageBox::warning(NULL, QObject::tr("錯誤"), QObject::tr("保存語言信息失敗"));
        return;
    }
    QTextStream out(file);
    out<<lan;
    file->close();
    qDebug() << lan;
}

/**
 *  從文件中讀取保存的語言信息
 * @brief AideLanguage::getLanguage
 * @return
 */
QString AideLanguage::getLanguage() {
    QFile *file = new QFile();
    file->setFileName(AideLanguage::saveLanFile );
    bool opend = file->open(QIODevice::ReadOnly);
    if (!opend) return QLocale::system().name();
    QTextStream in(file);
    QString lan = in.readLine(0);
    file->close();
    return lan.trimmed();
}

