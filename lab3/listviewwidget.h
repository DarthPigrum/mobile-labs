#ifndef LISTVIEWWIDGET_H
#define LISTVIEWWIDGET_H

#include <QListWidget>
#include "listdata.h"

class ListViewWidget : public QListWidget
{
    Q_OBJECT

public:
    explicit ListViewWidget(QWidget *parent = nullptr);
    virtual void resizeEvent(QResizeEvent*) override;
    void addListItem(const AbstractListItem& listitem);
};

#endif // LISTVIEWWIDGET_H
