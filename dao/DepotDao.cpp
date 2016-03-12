#include "DepotDao.h"

//DepotDao::DepotDao() {

//}


const char * const SQL_NAMESPACE= "Depot";


QList<QVariantMap> DepotDao::getDepotList() {
    QString sql = Singleton<Sqls>::getInstance().getSql(SQL_NAMESPACE, "getDepotList");
    return DBUtil::selectMaps(sql);
}



