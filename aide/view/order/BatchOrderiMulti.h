#ifndef BATCHORDERMULTI_H
#define BATCHORDERMULTI_H

#include <QWidget>

namespace Ui {
class BatchOrderMulti;
}

class BatchOrderMulti : public QWidget
{
    Q_OBJECT

public:
    explicit BatchOrderMulti(QWidget *parent = 0);
    ~BatchOrderMulti();

private:
    Ui::BatchOrderMulti *ui;
};

#endif // BATCHORDERMULTI_H
