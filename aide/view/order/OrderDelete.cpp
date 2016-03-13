#include "OrderDelete.h"
#include "ui_OrderDelete.h"

OrderDelete::OrderDelete(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderDelete)
{
    ui->setupUi(this);
}

OrderDelete::~OrderDelete()
{
    delete ui;
}

