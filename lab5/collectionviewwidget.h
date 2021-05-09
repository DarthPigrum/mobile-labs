#ifndef COLLECTIONVIEWWIDGET_H
#define COLLECTIONVIEWWIDGET_H

#include <QGraphicsView>
#include <QResizeEvent>
#include <QWidget>

namespace Ui {
class CollectionViewWidget;
}

class CollectionViewWidget : public QWidget {
  Q_OBJECT
  QList<QGraphicsView *> views;

public:
  explicit CollectionViewWidget(QWidget *parent = nullptr);
  virtual void resizeEvent(QResizeEvent *e) override;
  ;
  ~CollectionViewWidget();

private:
  Ui::CollectionViewWidget *ui;
};

#endif // COLLECTIONVIEWWIDGET_H
