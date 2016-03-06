#include "view/mainwindow.h"
#include "view/usr/loginwidget.h"
#include <QApplication>
#include <QTranslator>
#include <QtDebug>
#include "common/aidelanguage.h"
#include <QDir>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QString translatorFileName = QDir::currentPath() + "/lan/aide_"+AideLanguage::getLanguage()+".qm";
    QTranslator *translator = new QTranslator(&a);
    if (translator->load(translatorFileName)) {
        a.installTranslator(translator);
    }

    // MainWindow w;
    // w.show();

    LoginWidget lw;
    lw.show();

    return a.exec();
}
