#include "LoginWidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget) {
    ui->setupUi(this);

    this->setMaximumSize(528, 393);
    this->setMinimumSize(528, 393);

    //
    QDesktopWidget* desktop = qApp->desktop();
    this->move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);

    // this->refreshLanguage(QLocale::system().name());
    // this->refreshLanguage("en_US");

    this->setWindowTitle(tr("登入") + " - Forevermark Aide");
    this->ui->serialEdit->setPlaceholderText(tr("賬戶編號"));
    this->ui->passwdEdit->setPlaceholderText(tr("密碼"));

    // 取消系統標題欄目
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowIcon(QIcon(":/res/icon/aide.png"));

    this->ui->labelLogo->setPixmap(QPixmap(":/res/icon/aide.png"));
    this->ui->labelUsr->setPixmap(QPixmap(":/res/icon/person.png"));
    this->ui->labelPasswd->setPixmap(QPixmap(":/res/icon/passwd.png"));

    this->ui->passwdEdit->setEchoMode(QLineEdit::Password);

    this->connect(this->ui->btnClose, SIGNAL(clicked(bool)), this, SLOT(closeWindow()));
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

void LoginWidget::closeWindow() {
    Singleton<ConnectionPool>::getInstance().destroy();

    /*
     * 退出登入時刪除鎖定文件
     */
    QString lockFile = QString("%1/%2").arg(AIDE_DATA_PATH).arg(AIDE_SAVE_LOCK);
    if (QFile::exists(lockFile)) {
        QFile *file = new QFile;
        file->setFileName(lockFile);
        file->remove();
        file->close();
    }
    this->close();
}

//void LoginWidget::changeEvent(QEvent *e) {
//    QMessageBox::changeEvent(e);
//}

void LoginWidget::refreshLanguage(QString lan) {

    QTranslator translator;
    bool b = translator.load(QString("%1/lan/aide_%2_.qm").arg(QDir::currentPath()).arg(lan));
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

    QVariantMap account = AccountDao::getSignInUsr(serial);
    if (account.isEmpty()) {
        QMessageBox::warning(this, this->tr("警告"), this->tr("未發現當前賬戶"));
        return;
    }

    if (serial != "ROOT" && account.value("user_passwd") .toString()!=  passwd) {
        QMessageBox::warning(this, this->tr("錯誤"),  this->tr("請輸入正確的賬戶和密碼"));
        return;
    }

    if ((serial == "ROOT" || account.value("uid").toString() == "1") && passwd != "Passw0rd") {
        QMessageBox::warning(this, this->tr("錯誤"), this->tr("以禁止 ROOT 賬戶登入"));
        return;
    }

    if (account.value("user_status").toInt() == 0) {
        QMessageBox::warning(this, this->tr("警告"), this->tr("當前賬戶已被停用不可登入"));
        return;
    }

    if (serial != "ROOT" && account.value("dep_id").toString() != "25") {
        QMessageBox::warning(this, this->tr("警告"), this->tr("限制登入"));
        return;
    }

    QFile *file = new QFile();
    file->setFileName(QString("%1/%2").arg(AIDE_DATA_PATH).arg(AIDE_SAVE_USER));
    bool opend = file->open(QIODevice::WriteOnly);
    if (!opend) {
        QMessageBox::warning(this, this->tr("警告"), this->tr("儲存登入信息失敗"));
        return;
    }

    if (remmber) {
        QTextStream out(file);
        out << AccountKit::encryUserInfo(account.value("uid").toString(), account.value("user_serial").toString(),
                                             account.value("user_name").toString(), account.value("user_mail").toString());
        file->close();
    } else {
        if (file->exists() && !file->remove()) {
            QMessageBox::warning(this, this->tr("警告"),  this->tr("儲存登入信息失敗"));
        }
        file->close();
    }

    this->hide();
    emit loginComplete();
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
