#include "NavSelect.h"

NavSelect::NavSelect(){
   // this->navMap["order"] = NavType::ORDER;
}

map<QString, NavType> init() {
    map<QString, NavType> m;

    m["order"] = NavType::ORDER;
    m["order.batch_order_multi"] = NavType::ORDER_BATCH_MILTI;
    m["order.batch_order_same"] = NavType::ORDER_BATCH_SAME;
    m["order.delete"] = NavType::ORDER_DELETE;

    m["depot"] = NavType::DEPOT;
    m["depot.out_online"] = NavType::DEPOT_OUT_ONLINE;
    m["depot.out_offline"] = NavType::DEPOT_OUT_OFFLINE;
    m["depot.out_batch"] = NavType::DEPOT_OUT_BATCH;
    m["depot.undo"] = NavType::DEPOT_UNDO;

    m["stock"] = NavType::STOCK;
    m["stock.in"] = NavType::STOCK_IN;
    m["stock.inventory"] = NavType::STOCK_INVENTORY;
    m["stock.allocation"] = NavType::STOCK_ALLOCATION;

    m["report"] = NavType::REPORT;
    m["report.shop"] = NavType::REPORT_SHOP;

    m["conf"] = NavType::CONF;
    m["conf.node"] = NavType::CONF_NODE;
    m["conf.access"] = NavType::CONF_ACCESS;

    return m;
}

map<QString, NavType> NavSelect::navMap = init();


NavType NavSelect::getType(QString type) {
    return NavSelect::navMap[type];
}


