#ifndef NAVMODEL_H
#define NAVMODEL_H

#include <QAbstractListModel>
#include <vector>
#include <QtDebug>
#include "aide/common/navtype.h"
#include "aide/common/navselect.h"

class TreeNode :public QObject {
    Q_OBJECT
public:
    QString label;
    QString id;
    int level;
    bool collapse;
    bool theLast;
    int count;
    std::list<TreeNode*> children;
};



class NavModel : public QAbstractListModel {
    Q_OBJECT


public:

    struct ListNode {
        QString label;
        TreeNode* treeNode;
    };

    NavModel(QObject *parent);
    ~NavModel();

    /*!
    \brief
        Read data from xml.
    */
    void ReadDataFromConfig(QString path);

    void refresh(bool isCcollapse, int first, int last);

public:
    std::vector<ListNode> m_list;
    int rowCount(const QModelIndex &parent /* = QModelIndex */) const;
    QVariant data(const QModelIndex &index, int role /* = Qt::DisplayRole */) const;

//    void beginInsertRows(const QModelIndex &parent, int first, int last);
//    void endInsertRows();
//    void beginRemoveRows(const QModelIndex &parent, int first, int last);
//    void endRemoveRows();

//public slots:
//    void collapseSlot(const QModelIndex &index);


private:
    std::vector<TreeNode*> m_nodeList;
    void refreshList();
};


#endif // NAVMODEL_H
