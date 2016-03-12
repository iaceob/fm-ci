#include "DataCenter.h"

//DataCenter::DataCenter() {

//}

QList<QVariantMap> DataCenter::shopSelectList;
QList<QVariantMap> DataCenter::depotSelectList;

void DataCenter::init() {
    DataCenter::shopSelectList = ShopDao::getShopSelectList();
    DataCenter::depotSelectList = DepotDao::getDepotList();
}

void DataCenter::clear() {
    DataCenter::shopSelectList.clear();
    DataCenter::depotSelectList.clear();
}

QList<QVariantMap> DataCenter::getShopSelectList() {
    return DataCenter::shopSelectList;
}

void DataCenter::setShopSelectList(const QList<QVariantMap> shopSelectList) {
    DataCenter::shopSelectList = shopSelectList;
}

QList<QVariantMap> DataCenter::getDepotSelectList() {
    return DataCenter::depotSelectList;
}

void DataCenter::setDepotSelectList(const QList<QVariantMap> depotSelectList) {
    DataCenter::depotSelectList = depotSelectList;
}


