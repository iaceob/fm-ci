#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);

    // application setting
    this->appTitle = "Forevermark Aide";
    this->setWindowIcon(QIcon(":/res/icon/aide.png"));
    this->setWindowIconText(this->appTitle);
    this->setWindowTitle(this->appTitle);

    // 設定容器佈局類型
    this->containerLayout = new QHBoxLayout;

    // 設定菜單列表
    this->navModel = new NavModel(this);
    qDebug() << QCoreApplication::applicationDirPath();
    this->navModel->ReadDataFromConfig(QCoreApplication::applicationDirPath() + "/config.xml");
    NavDelegate* delegate = new NavDelegate(this);
    this->ui->listView->setModel(this->navModel);
    this->ui->listView->setItemDelegate(delegate);

    // 綁定菜單雙擊事
    this->connect(this->ui->listView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(collapseSlot(const QModelIndex&)));

    // Action 事件綁定
    this->connect(this->ui->exitAction, SIGNAL(triggered(bool)), this, SLOT(closeWindowSlot()));

}

MainWindow::~MainWindow() {
    delete ui;
}

/**
 * 菜單雙擊出發槽
 * @brief MainWindow::collapseSlot
 * @param index
 */
void MainWindow::collapseSlot(const QModelIndex &index) {

    //   判斷當前節點是否有子節點, 如果有則展開子節點
    TreeNode *node = this->navModel->m_list[index.row()].treeNode;
    if (node->children.size()!=0) {
        node->collapse = !node->collapse;
        this->navModel->refresh(!node->collapse, index.row()+1, index.row()+node->children.size());
        return;
    }

    /*
     * 否則構造容器顯示
     */

    QWidget *container = NULL;
    QString modalTitle;
    switch(NavSelect::getType(node->id)) {
    case NavType::ORDER:
        break;
    case NavType::ORDER_BATCH_MILTI:
        modalTitle = "批量下單 (多店鋪)";
        container = new BatchOrderMulti;
        break;
    case NavType::ORDER_BATCH_SAME:
        modalTitle = "批量下單 (同店鋪)";
        break;
    case NavType::ORDER_DELETE:
        modalTitle = "訂單刪除";
        container = new OrderDelete;
        break;
    default:
        break;
    }

    if (container==NULL) return;

    modalTitle.isEmpty() ? (modalTitle=this->appTitle) : (modalTitle += " - " + this->appTitle);
    qDebug() << modalTitle;
    this->setWindowTitle(modalTitle);

    this->clearLayout(this->containerLayout);
    this->containerLayout->addWidget(container);
    this->ui->widget->setLayout(this->containerLayout);


}



void MainWindow::closeWindowSlot() {
    this->close();
}

/**
 *  清空 layout 函數
 * @brief MainWindow::clearLayout
 * @param layout
 */
void MainWindow::clearLayout(QLayout *layout) {
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}
