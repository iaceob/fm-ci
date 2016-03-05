#ifndef NODESELECT_H
#define NODESELECT_H

#include <map>
#include <QString>
#include <QtDebug>
#include "navtype.h"

using namespace std;

class NavSelect {


public:
    NavSelect();
    static NavType getType(QString type);

private:
    static map<QString, NavType> navMap;

};

#endif // NODESELECT_H
