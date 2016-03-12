#include "ShopDao.h"

//ShopDao::ShopDao() {

//}


const char * const SQL_NAMESPACE= "Shop";

QList<QVariantMap> ShopDao::getShopSelectList() {
    QString sql = Singleton<Sqls>::getInstance().getSql(SQL_NAMESPACE, "getShopSelectList");
    return DBUtil::selectMaps(sql);
}
