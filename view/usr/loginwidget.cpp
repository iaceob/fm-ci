#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget) {
    ui->setupUi(this);

    this->setMaximumSize(528, 393);
    this->setMinimumSize(528, 393);

    this->refreshLanguage();

    // 取消系統標題欄目
    this->setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    this->setWindowIcon(QIcon(":/res/icon/aide.png"));

    this->ui->labelLogo->setPixmap(QPixmap(":/res/icon/aide.png"));
    this->ui->labelUsr->setPixmap(QPixmap(":/res/icon/person.png"));
    this->ui->labelPasswd->setPixmap(QPixmap(":/res/icon/passwd.png"));

    this->ui->passwdEdit->setEchoMode(QLineEdit::Password);

    this->connect(this->ui->btnClose, SIGNAL(clicked(bool)), this, SLOT(close()));
    this->connect(this->ui->btnMin, SIGNAL(clicked(bool)), this, SLOT(showMinimized()));

    this->connect(this->ui->btnLogin, SIGNAL(clicked(bool)), this, SLOT(loginSlot()));
    this->connect(this->ui->serialEdit, SIGNAL(returnPressed()), this, SLOT(loginSlot()));
    this->connect(this->ui->passwdEdit, SIGNAL(returnPressed()), this, SLOT(loginSlot()));
    this->connect(this->ui->btnConf, SIGNAL(clicked(bool)), this, SLOT(confSlot()));

}

LoginWidget::~LoginWidget() {
    delete ui;
}


//void LoginWidget::changeEvent(QEvent *e) {
//    QMessageBox::changeEvent(e);
//}

void LoginWidget::refreshLanguage() {
    this->setWindowTitle(tr("登入") + " - Forevermark Aide");
    this->ui->serialEdit->setPlaceholderText(tr("賬戶編號"));
    this->ui->passwdEdit->setPlaceholderText(tr("密碼"));
}

/**
 * User login slot
 * @brief LoginWidget::loginSlot
 */
void LoginWidget::loginSlot() {
    QString serial = this->ui->serialEdit->text();
    QString passwd = this->ui->passwdEdit->text();
    bool remmber = this->ui->cbkAuto->isChecked();

    if (serial.isEmpty() || passwd.isEmpty()) {
        QMessageBox::warning(this, tr("警告"), tr("請輸入賬戶和密碼"));
        return;
    }

    qDebug() << serial << passwd << remmber;
}

void LoginWidget::confSlot() {
    QTranslator translator;
    bool b = translator.load("aide_en_US.qm");
    if (!b) return;
    qApp->installTranslator(&translator);
    this->ui->retranslateUi(this);
    this->refreshLanguage();
}
