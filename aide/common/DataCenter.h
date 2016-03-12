#ifndef DATACENTER_H
#define DATACENTER_H

#include <QList>
#include <QVariantMap>

#include "dao/ShopDao.h"
#include "dao/DepotDao.h"

/**
 * @brief The DataCenter class 數據中心, 存儲數據庫數據緩存, 減少從數據庫中查詢
 */
class DataCenter {
public:
    // DataCenter();

    /**
     * @brief init 初始化
     */
    static void init();

    /**
     * @brief clear 清空所有保存的數據
     */
    static void clear();

    /**
     * @brief getShopSelectList 店鋪選擇列表
     * @return
     */
    static QList<QVariantMap>  getShopSelectList();
    static void setShopSelectList(const QList<QVariantMap> shopSelectList);
    /**
     * @brief getShopSelectList 倉庫選擇列表
     * @return
     */
    static QList<QVariantMap>  getDepotSelectList();
    static void setDepotSelectList(const QList<QVariantMap> depotSelectList);

private:
    /**
     * @brief shopSelectList 店鋪選擇列表, 僅 ID SERIAL NAME 字段
     */
    static QList<QVariantMap> shopSelectList;
    /**
     * @brief depotList 倉庫選擇列表, 僅 ID NAME 字段
     */
    static QList<QVariantMap> depotSelectList;
};

#endif // DATACENTER_H
