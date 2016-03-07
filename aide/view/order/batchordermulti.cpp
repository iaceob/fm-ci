#include "batchordermulti.h"
#include "ui_batchordermulti.h"

BatchOrderMulti::BatchOrderMulti(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BatchOrderMulti)
{
    ui->setupUi(this);
}

BatchOrderMulti::~BatchOrderMulti()
{
    delete ui;
}
