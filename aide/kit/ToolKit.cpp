#include "ToolKit.h"

//ToolKit::ToolKit() {

//}

bool ToolKit::isNum(const QString &str) {
    QRegExp rx("\\d");
    return rx.exactMatch(str);
}
