#include "mainwindow.h"
#include "addmoviedialog.h"
#include "movie.h"
#include "ui_mainwindow.h"
#include <QTabBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->searchLine, &QLineEdit::textChanged, [this](QString query) {
    auto result = ui->listWidget->findItems(query, Qt::MatchContains);
    if (result.size()) {
      for (const auto item : ui->listWidget->items())
        item->setHidden(true);
      for (const auto item : result)
        item->setHidden(false);
    } else {
      auto err = new QMessageBox(this);
      err->setText("Nothing found");
      err->show();
    }
  });
  connect(ui->addMovieButton, &QPushButton::clicked, [this]() {
    auto dialog = new AddMovieDialog(this);
    connect(dialog, &AddMovieDialog::yield,
            [this](QString name, int year, QString type) {
              Movie movie(QJsonObject{{"Title", name},
                                      {"Year", QString::number(year)},
                                      {"Type", type}});
              ui->listWidget->addListItem(movie);
            });
    dialog->show();
  });
}

void MainWindow::resizeEvent(QResizeEvent *) {
  ui->tabWidget->tabBar()->setMinimumWidth(ui->tabWidget->width());
}

MainWindow::~MainWindow() { delete ui; }
