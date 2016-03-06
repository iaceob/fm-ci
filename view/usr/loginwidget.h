#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>
#include <QTranslator>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();

protected:
    // void changeEvent(QEvent *);

private:
    Ui::LoginWidget *ui;
    void refreshLanguage();

private slots:
    void loginSlot();
    void confSlot();
};

#endif // LOGINWIDGET_H
