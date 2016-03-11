#ifndef NAVTYPE
#define NAVTYPE

enum class NavType {

    //   訂單
    ORDER,
    // 多店鋪批量發貨
    ORDER_BATCH_MILTI,
    // 同店鋪批量發貨
    ORDER_BATCH_SAME,
    // 訂單刪除
    ORDER_DELETE,

    //  倉庫
    DEPOT,
    // 線上發貨
    DEPOT_OUT_ONLINE,
    // 線下發貨
    DEPOT_OUT_OFFLINE,
    //  批量發貨
    DEPOT_OUT_BATCH,
    // 撤銷發貨
    DEPOT_UNDO,

    // 庫存
    STOCK,
    // 入庫
    STOCK_IN,
    // 庫存盤點
    STOCK_INVENTORY,
    // 庫存調撥
    STOCK_ALLOCATION,

    // 報表
    REPORT,
    // 店鋪信息報表
    REPORT_SHOP,

    // 設定
    CONF,
    // 節點設定
    CONF_NODE,
    // 權限設定
    CONF_ACCESS

};

#endif // NAVTYPE

