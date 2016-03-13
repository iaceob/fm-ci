#include "BatchOrderMulti.h"
#include "ui_BatchOrderMulti.h"

BatchOrderMulti::BatchOrderMulti(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BatchOrderMulti) {
    ui->setupUi(this);

    this->loadDepotSelect();
    this->loadShopTable();

    this->connect(this->ui->btnImport, SIGNAL(clicked(bool)), this, SLOT(importDataSlot()));
    // this->connect(this->ui->shopTable, SIGNAL())

}


BatchOrderMulti::~BatchOrderMulti() {
    delete ui;
}



// ====== slots
void BatchOrderMulti::importDataSlot() {
    bool ok;
    QString text = QInputDialog::getText(this, tr("請輸入導入數據"),
                                         tr("輸入需要導入的數據 "),
                                         QLineEdit::Normal,
                                         "", &ok);
    if (!ok || text.isEmpty()) return;
    // QMessageBox::information(this, "title", text);
    // qDebug() << text;
    QStringList datas = text.split("\n");
    QStringList dataParams;
    QTableWidget *shopTable = this->ui->shopTable;
    for (QString data : datas) {
        dataParams = data.split("&");
        if (dataParams.size() != 2) continue;
        qDebug() << ToolKit::isNum(dataParams.at(1));
        if (!ToolKit::isNum(dataParams.at(1))) continue;
        for (int i=shopTable->rowCount(); i-->0;) {
            if (shopTable->item(i, 0)->text() != dataParams.at(0)) continue;
            shopTable->item(i, 2)->setText(dataParams.at(1));
        }
    }

}


// ====== private
void BatchOrderMulti::loadDepotSelect() {
    QList<QVariantMap> depotList =  DataCenter::getDepotSelectList();
    for (int i=0; i<depotList.size(); ++i) {
        this->ui->depotSelect->addItem(depotList.at(i).value("depot_name").toString(), depotList.at(i).value("depot_id").toString());
        // 默認門店維護倉庫
        if ("191285184920948736" != depotList.at(i).value("depot_id")) continue;
        this->ui->depotSelect->setCurrentIndex(i);
    }
}

void BatchOrderMulti::loadShopTable() {
    this->shopList = DataCenter::getShopSelectList();

    QTableWidget *shopTable = this->ui->shopTable;
    shopTable->setRowCount(shopList.size());
    shopTable->setColumnCount(3);

    QHeaderView *header = shopTable->horizontalHeader();
    header->setStretchLastSection(true);
    header->setSectionResizeMode(1, QHeaderView::Stretch);
    // header->setSectionResizeMode(QHeaderView::Stretch);

    // shopTable->setHorizontalHeaderLabels();
    shopTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    shopTable->setHorizontalHeaderItem(0, new QTableWidgetItem(this->tr("編號")));
    shopTable->setHorizontalHeaderItem(1, new QTableWidgetItem(this->tr("店鋪名")));
    shopTable->setHorizontalHeaderItem(2, new QTableWidgetItem(this->tr("數量")));


    int colIndex = 0;
    for (int i=0; i<this->shopList.size(); ++i) {
        QStringList shopKeys = this->shopList.at(i).keys();
        for (int j=0; j<shopKeys.size(); ++j) {
            if ("shop_id" == shopKeys.at(j)) continue;
            if ("shop_serial" == shopKeys.at(j)) colIndex = 0;
            if ("shop_name" == shopKeys.at(j)) colIndex = 1;
            shopTable->setItem(i, colIndex, new QTableWidgetItem(this->shopList.at(i).value(shopKeys.at(j)).toString()));
        }
        shopTable->setItem(i, 2, new QTableWidgetItem);
    }
}
