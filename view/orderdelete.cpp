#include "orderdelete.h"
#include "ui_orderdelete.h"

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

