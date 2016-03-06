#ifndef AIDELANGUAGE_H
#define AIDELANGUAGE_H

#include <QString>
#include <QtDebug>
#include <QDir>
#include <QMessageBox>

class AideLanguage {
public:
    AideLanguage();
    static void saveLanguage(QString lan);
    static QString getLanguage();

private:
    static QString saveLanFile;

};

#endif // AIDELANGUAGE_H
