#include "collectionviewwidget.h"
#include "ui_collectionviewwidget.h"
#include <QFileDialog>

CollectionViewWidget::CollectionViewWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::CollectionViewWidget) {
  ui->setupUi(this);
  views.push_back(ui->graphicsView_1);
  views.push_back(ui->graphicsView_2);
  views.push_back(ui->graphicsView_3);
  views.push_back(ui->graphicsView_4);
  views.push_back(ui->graphicsView_5);
  views.push_back(ui->graphicsView_6);
  views.push_back(ui->graphicsView_7);
  views.push_back(ui->graphicsView_8);
  views.push_back(ui->graphicsView_9);
  views.push_back(ui->graphicsView_10);
  connect(ui->addButton, &QPushButton::clicked, [this]() {
    auto dialog = new QFileDialog(this, "Choose image", "~", ".jpg");
    connect(dialog, &QFileDialog::accepted, [this, dialog]() {
      for (const auto &file : dialog->selectedFiles()) {
        auto view = views.first();
        auto scene = new QGraphicsScene(this);
        scene->addPixmap(QPixmap(file)
                             .scaledToHeight(view->height() * 0.99)
                             .scaledToWidth(view->width() * 0.99));
        view->setScene(scene);
        views.pop_front();
        views.push_back(view);
      }
    });
    dialog->show();
  });
}

void CollectionViewWidget::resizeEvent(QResizeEvent *e) {
  resize(e->size().width(), e->size().width() * 1.25);
  ui->placeholder->resize(ui->placeholder->width(), 0);
}

CollectionViewWidget::~CollectionViewWidget() { delete ui; }
