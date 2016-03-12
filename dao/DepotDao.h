#ifndef DEPOTDAO_H
#define DEPOTDAO_H

#include <QList>
#include <QString>
#include <QVariantMap>
#include <QtDebug>

#include "db/DBUtil.h"
#include "db/Sqls.h"

class DepotDao {
public:
    // DepotDao();
    /**
     * @brief getDepotList 獲取倉庫列表
     * @return
     */
    static QList<QVariantMap> getDepotList();
};

#endif // DEPOTDAO_H
