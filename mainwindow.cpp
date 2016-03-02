#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "navmodel.h"
#include "navdelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    NavModel* model = new NavModel(this);
    qDebug() << QCoreApplication::applicationDirPath();
    model->ReadDataFromConfig(QCoreApplication::applicationDirPath() + "/config.xml");
    NavDelegate* delegate = new NavDelegate(this);
    this->ui->listView->setModel(model);
    this->ui->listView->setItemDelegate(delegate);
    this->connect(this->ui->listView, SIGNAL(doubleClicked(const QModelIndex &)), model, SLOT(Collapse(const QModelIndex&)));
    // QAction *qa = this->ui->listView->actions()[0];


}

MainWindow::~MainWindow() {
    delete ui;
}
