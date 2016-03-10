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

#include "db/ConnectionPool.h"
#include "dao/AccountDao.h"

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget {
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();

signals:
    void loginComplete();

protected:
    // void changeEvent(QEvent *);


private:
    Ui::LoginWidget *ui;
    void refreshLanguage(QString lan);

private slots:
    void closeWindow();
    void loginSlot();
    void serialEditSlot();
    void confProxySlot();
    void toLanEnUS();
    void toLanZhCN();
    void toLanZhTW();
};


#endif // LOGINWIDGET_H
