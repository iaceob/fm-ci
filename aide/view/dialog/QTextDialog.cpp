#include "QTextDialog.h"
#include "ui_QTextDialog.h"

QTextDialog::QTextDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QTextDialog) {
    ui->setupUi(this);
}

QTextDialog::~QTextDialog() {
    delete ui;
}

void QTextDialog::setDialogTitle(const QString &title) {
    this->setWindowTitle(title);
}

void QTextDialog::setMessage(const QString &messge) {
    this->ui->label->setText(messge);
}

void QTextDialog::setText(const QString &text) {
    this->ui->text->insertPlainText(text);
}

