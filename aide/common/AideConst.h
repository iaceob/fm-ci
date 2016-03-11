#ifndef AIDECONST
#define AIDECONST

#include <QString>
#include <QStandardPaths>

/**
 * @brief AIDE_DEBUG 是否調試狀態
 */
const bool AIDE_DEBUG = true;

/**
 * @brief AIDE_ENCRY_KEY 加密 KEY (當前僅儲存賬戶信息使用)
 */
const int AIDE_ENCRY_KEY = 11;

/**
 * @brief AIDE_NAME  項目名
 */
const QString AIDE_NAME = "Forevermark Aide";

/**
 * @brief AIDE_VERSION 工程版本
 */
const QString AIDE_VERSION = "v0.1";

/**
 * @brief AIDE_DATA_PATH 數據存儲目錄
 */
const QString AIDE_DATA_PATH = QString("%1/.fm-aide").arg(QStandardPaths::writableLocation(QStandardPaths::HomeLocation));

/**
 * @brief AIDE_AUTHOR 作者
 */
const QString AIDE_AUTHOR = "iaceob";

/**
 * @brief AIDE_SAVE_LAN 語言記錄文件名
 */
const QString AIDE_SAVE_LAN = "lan";

/**
 * @brief AIDE_SAVE_USER 賬戶登錄記錄文件名
 */
const QString AIDE_SAVE_USER = "aidesess.pem";

/**
 * @brief AIDE_SAVE_LOCK 啟動鎖, 只允許有一個實例
 */
const QString AIDE_SAVE_LOCK = "lock";


#endif // AIDECONST

