#ifndef TOOLKIT_H
#define TOOLKIT_H

#include <QString>
#include <QDebug>
#include <QRegExp>

class ToolKit {
public:
    // ToolKit();
    /**
     * @brief isNum 判斷字符串是否數字
     * @param str 字符串
     * @return
     */
    static bool isNum(const QString &str);

};

#endif // TOOLKIT_H
