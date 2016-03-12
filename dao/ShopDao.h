#ifndef SHOPDAO_H
#define SHOPDAO_H

#include <QList>
#include <QString>
#include <QVariantMap>
#include <QtDebug>

#include "db/DBUtil.h"
#include "db/Sqls.h"

class ShopDao {
public:
    // ShopDao();
    /**
     * @brief getShopSelectList 獲取供選擇的店鋪列表
     * @return
     */
    static QList<QVariantMap> getShopSelectList();
};

#endif // SHOPDAO_H
