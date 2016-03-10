#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtDebug>
#include <QCloseEvent>

#include "db/ConnectionPool.h"

#include "aide/nav/navmodel.h"
#include "aide/nav/navdelegate.h"

#include "aide/view/order/batchordermulti.h"
#include "aide/view/order/orderdelete.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *);

private:
    //  主界面
    Ui::MainWindow *ui;
    // 菜單列表
    NavModel *navModel;
    // 主窗體 Layout
    QLayout *containerLayout;
    // 清空 QLayout 工具函數
    void clearLayout(QLayout *);
    // window title
    QString appTitle;

private slots:
    //  登錄成功後顯示主界面
    void showWindow();
    // 菜單點擊出發函數
    void collapseSlot(const QModelIndex &index);
    // 窗口關閉槽
    bool closeWindowSlot();

};

#endif // MAINWINDOW_H
