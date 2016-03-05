#include "navselect.h"

NavSelect::NavSelect(){
   // this->navMap["order"] = NavType::ORDER;
}

map<QString, NavType> init() {
    map<QString, NavType> m;

    m["order"] = ORDER;
    m["order.batch_order_multi"] = ORDER_BATCH_MILTI;
    m["order.batch_order_same"] = ORDER_BATCH_SAME;
    m["order.delete"] = ORDER_DELETE;

    m["depot"] = DEPOT;
    m["depot.out_online"] = DEPOT_OUT_ONLINE;
    m["depot.out_offline"] = DEPOT_OUT_OFFLINE;
    m["depot.out_batch"] = DEPOT_OUT_BATCH;
    m["depot.undo"] = DEPOT_UNDO;

    m["stock"] = STOCK;
    m["stock.in"] = STOCK_IN;
    m["stock.inventory"] = STOCK_INVENTORY;
    m["stock.allocation"] = STOCK_ALLOCATION;

    m["report"] = REPORT;
    m["report.shop"] = REPORT_SHOP;

    m["conf"] = CONF;
    m["conf.node"] = CONF_NODE;
    m["conf.access"] = CONF_ACCESS;

    return m;
}

map<QString, NavType> NavSelect::navMap = init();


NavType NavSelect::getType(QString type) {
    return NavSelect::navMap[type];
}


