#ifndef LISTVIEWWIDGET_H
#define LISTVIEWWIDGET_H

#include "listdata.h"
#include <QListWidget>
#include <QTimer>

class ListViewWidget : public QListWidget {
  Q_OBJECT
  QHash<void *, QString> _fulltext;
  QVector<QListWidgetItem *> _items;

public:
  explicit ListViewWidget(QWidget *parent = nullptr);
  virtual void resizeEvent(QResizeEvent *) override;
  void addListItem(const AbstractListItem &listitem);
  QVector<QListWidgetItem *> items();
};

#endif // LISTVIEWWIDGET_H
