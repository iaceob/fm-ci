#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget) {
    ui->setupUi(this);

    this->setMaximumSize(528, 393);
    this->setMinimumSize(528, 393);

    // this->refreshLanguage(QLocale::system().name());
    // this->refreshLanguage("en_US");

    this->setWindowTitle(tr("登入") + " - Forevermark Aide");
    this->ui->serialEdit->setPlaceholderText(tr("賬戶編號"));
    this->ui->passwdEdit->setPlaceholderText(tr("密碼"));

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
    this->connect(this->ui->serialEdit, SIGNAL(textEdited(QString)), this, SLOT(serialEditSlot()));
    // this->connect(this->ui->btnConf, SIGNAL(clicked(bool)), this, SLOT(confSlot()));


    QMenu * menu = this->ui->btnConf->getMenu(); //获得菜单，并向上面添加菜单
    QAction *proxyAction = menu->addAction(tr("代理"));
    QMenu *lanMenu = menu->addMenu(tr("語言"));
    QAction *lanEnUSAction = lanMenu->addAction("English (US)");
    QAction *lanZhTWAction = lanMenu->addAction("中文 (臺灣)");
    QAction *lanZhCNAction = lanMenu->addAction("中文 (大陸)");

    // this->connect(lanEnUSAction, SIGNAL(triggered(bool)), this, SLOT(refreshLanguage("en_US")));
    this->connect(proxyAction, SIGNAL(triggered(bool)), this, SLOT(confProxySlot()));
    this->connect(lanEnUSAction, SIGNAL(triggered(bool)), this, SLOT(toLanEnUS()));
    this->connect(lanZhCNAction, SIGNAL(triggered(bool)), this, SLOT(toLanZhCN()));
    this->connect(lanZhTWAction, SIGNAL(triggered(bool)), this, SLOT(toLanZhTW()));

}

LoginWidget::~LoginWidget() {
    delete ui;
}


//void LoginWidget::changeEvent(QEvent *e) {
//    QMessageBox::changeEvent(e);
//}

void LoginWidget::refreshLanguage(QString lan) {

    QTranslator translator;
    bool b = translator.load(QDir::currentPath() + "/lan/aide_"+lan+".qm");
    if (!b) return;
    qApp->installTranslator(&translator);
    this->ui->retranslateUi(this);

    AideLanguage::saveLanguage(lan);

    QMessageBox::information(this, this->tr("提醒"), this->tr("部分語言切換需要重啟"));

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

/**
 * 輸入賬戶時將賬戶轉為大寫
 * @brief LoginWidget::serialEditSlot
 */
void LoginWidget::serialEditSlot() {
    this->ui->serialEdit->setText(this->ui->serialEdit->text().trimmed().toUpper());
}

void LoginWidget::confProxySlot() {
    QMessageBox::information(this, this->tr("消息"), this->tr("Coming soon ..."));
}

void LoginWidget::toLanEnUS() {
    this->refreshLanguage("en_US");
}
void LoginWidget::toLanZhCN() {
    this->refreshLanguage("zh_CN");
}
void LoginWidget::toLanZhTW() {
    this->refreshLanguage("zh_TW");
}
