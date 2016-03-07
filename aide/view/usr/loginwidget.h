#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>
#include <QTranslator>
#include <QMenu>
#include <QDir>
#include <QDesktopWidget>
#include "aide/common/aidelanguage.h"

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget {
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();

protected:
    // void changeEvent(QEvent *);

private:
    Ui::LoginWidget *ui;
    void refreshLanguage(QString lan);

private slots:
    void loginSlot();
    void serialEditSlot();
    void confProxySlot();
    void toLanEnUS();
    void toLanZhCN();
    void toLanZhTW();
};

#endif // LOGINWIDGET_H
