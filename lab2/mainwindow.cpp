#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTabBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    ui->tabWidget->tabBar()->setMinimumWidth(ui->tabWidget->width());
}

MainWindow::~MainWindow()
{
    delete ui;
}

