#ifndef DRAWINGVIEWWIDGET_H
#define DRAWINGVIEWWIDGET_H

#include <QChart>
#include <QChartView>
#include <QPieSeries>
#include <QTabWidget>
#include <qcustomplot/qcustomplot.h>

class DrawingViewWidget : public QTabWidget {
  Q_OBJECT
  QWidget *createFnPlot();
  QWidget *createPieChart();

public:
  explicit DrawingViewWidget(QWidget *parent = nullptr);
  virtual void resizeEvent(QResizeEvent *event) override;
};

#endif // DRAWINGVIEWWIDGET_H
