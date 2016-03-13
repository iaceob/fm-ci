#ifndef BATCHORDERMULTI_H
#define BATCHORDERMULTI_H

#include <QWidget>
#include <QDebug>
#include <QList>
#include <QVariantMap>
#include <QMessageBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QInputDialog>

#include "aide/kit/ToolKit.h"
#include "aide/common/DataCenter.h"
#include "aide/view/dialog/QTextDialog.h"

namespace Ui {
class BatchOrderMulti;
}

class BatchOrderMulti : public QWidget {
    Q_OBJECT

public:
    explicit BatchOrderMulti(QWidget *parent = 0);
    ~BatchOrderMulti();

private:
    /**
     * @brief shopList 店鋪列表
     */
    QList<QVariantMap> shopList;

private:
    Ui::BatchOrderMulti *ui;
    /**
     * @brief loadDepotSelect  初始化倉庫數據
     */
    void loadDepotSelect();
    /**
     * @brief loadShopTable 裝載店鋪列表
     */
    void loadShopTable();

private slots:
    /**
     * @brief importDataSlot 數據導入事件
     */
    void importDataSlot();
};

#endif // BATCHORDERMULTI_H
