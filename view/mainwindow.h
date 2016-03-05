#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtDebug>

#include "nav/navmodel.h"
#include "nav/navdelegate.h"

#include "view/batchordermulti.h"
#include "view/orderdelete.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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
    // 菜單點擊出發函數
    void collapseSlot(const QModelIndex &index);
    // 窗口關閉槽
    void closeWindowSlot();

};

#endif // MAINWINDOW_H
