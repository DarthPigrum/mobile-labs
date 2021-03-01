#include "drawingviewwidget.h"

QWidget *DrawingViewWidget::createFnPlot()
{
    auto res = new QCustomPlot(this);
    QVector<double> x, y;
    for(double param = -5; param < 5; param+=1e-2) {
        x.push_back(param);
        y.push_back(param * param);
    }
    res->addGraph();
    res->graph(0)->setPen(QPen(Qt::GlobalColor::blue, 5.0));
    res->graph(0)->setData(x, y);
    res->xAxis->setRange(-5, 5);
    res->yAxis->setRange(0, 30);
    res->replot();
    return res;
}

QWidget *DrawingViewWidget::createPieChart()
{
    using namespace QtCharts;
    auto chart = new QChart();
    auto series = new QPieSeries(chart);
    series->setHoleSize(0.35);
    series->append("", 0.25)->setColor(Qt::GlobalColor::red);
    series->append("", 0.35)->setColor(Qt::GlobalColor::green);
    series->append("", 0.4)->setColor(Qt::GlobalColor::yellow);
    chart->addSeries(series);
    chart->legend()->hide();
    return new QChartView(chart);
}

DrawingViewWidget::DrawingViewWidget(QWidget *parent) : QTabWidget(parent)
{
    insertTab(0, createFnPlot(), "Графік");
    insertTab(1, createPieChart(), "Діаграма");
}

void DrawingViewWidget::resizeEvent(QResizeEvent*)
{
    tabBar()->setMinimumWidth(width());
}
