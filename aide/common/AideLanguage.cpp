#include "AideLanguage.h"

AideLanguage::AideLanguage()  {

}

// QString AideLanguage::saveLanPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/" + AIDE_DATA_PATH + "";
QString AideLanguage::saveLanFile = QString("%1/%2").arg(AIDE_DATA_PATH).arg(AIDE_SAVE_LAN);

/**
 * 保存選擇的語言到文件中, 供下次登錄後設定默認語言
 * @brief AideLanguage::saveLanguage
 * @param lan
 */
void AideLanguage::saveLanguage(QString lan) {
    // QString lanFile = QString("%1/%2").arg(AIDE_DATA_PATH).arg(AideLanguage::saveLanFile);
    qDebug() << AideLanguage::saveLanFile;
    if (!QFile::exists(AIDE_DATA_PATH)) {
        QDir *saveLanDir = new QDir;
        saveLanDir->mkpath(AIDE_DATA_PATH);
    }
    QFile *file = new QFile;
    file->setFileName(AideLanguage::saveLanFile);
    bool opend = file->open(QIODevice::WriteOnly);
    if (!opend) {
        QMessageBox::warning(NULL, QObject::tr("錯誤"), QObject::tr("保存語言信息失敗"));
        return;
    }
    QTextStream out(file);
    out<<lan;
    file->close();
}

/**
 *  從文件中讀取保存的語言信息
 * @brief AideLanguage::getLanguage
 * @return
 */
QString AideLanguage::getLanguage() {
    QFile *file = new QFile();
    file->setFileName(AideLanguage::saveLanFile);
    bool opend = file->open(QIODevice::ReadOnly);
    if (!opend) return QLocale::system().name();
    QTextStream in(file);
    QString lan = in.readLine(0);
    file->close();
    return lan.trimmed();
}

