#ifndef ORDERDELETE_H
#define ORDERDELETE_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class OrderDelete;
}

class OrderDelete : public QWidget
{
    Q_OBJECT

public:
    explicit OrderDelete(QWidget *parent = 0);
    ~OrderDelete();

private slots:

private:
    Ui::OrderDelete *ui;
};

#endif // ORDERDELETE_H
