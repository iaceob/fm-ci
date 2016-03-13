#ifndef QTEXTDIALOG_H
#define QTEXTDIALOG_H

#include <QDialog>

namespace Ui {
class QTextDialog;
}

class QTextDialog : public QDialog {
    Q_OBJECT

public:
    explicit QTextDialog(QWidget *parent = 0);
    ~QTextDialog();

public:
    void setDialogTitle(const QString &title);
    void setMessage(const QString &messge);
    void setText(const QString &text);
    void getText();

private:
    Ui::QTextDialog *ui;
};

#endif // QTEXTDIALOG_H
