#include "listviewwidget.h"
#include "movie.h"
#include <QAbstractButton>
#include <QDir>
#include <QEasingCurve>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QMessageBox>
#include <QPushButton>
#include <QScroller>
ListViewWidget::ListViewWidget(QWidget *parent) : QListWidget(parent) {
  setWordWrap(true);
  QVector<Movie> movies;
  for (const auto &file : QDir(":/movies/Movies").entryList()) {
    QFile json(":/movies/Movies/" + file);
    json.open(QFile::ReadOnly);
    movies.push_back(Movie(QJsonDocument::fromJson(json.readAll()).object()));
  }
  for (const auto &movie : movies)
    addListItem(movie);
  connect(this, &QListWidget::itemClicked, [this](QListWidgetItem *item) {
    auto popup = new QMessageBox(this);
    popup->setText(_fulltext[item]);
    popup->addButton("Close", QMessageBox::RejectRole);
    auto remove = new QPushButton("Remove", this);
    connect(remove, &QPushButton::clicked, [this]() {
      auto item = takeItem(currentRow());
      _items.removeAll(item);
      _fulltext.remove(item);
    });
    popup->addButton(remove, QMessageBox::AcceptRole);
    popup->open();
  });
}

void ListViewWidget::resizeEvent(QResizeEvent *) {
  setIconSize(QSize(width() / 2, height() / 2));
}

void ListViewWidget::addListItem(const AbstractListItem &listitem) {
  auto item = new QListWidgetItem(
      QIcon(":/movies/Posters/" +
            (listitem.hasIcon() ? listitem.icon() : "NoPoster.jpg")),
      listitem.text(), this);
  item->setTextAlignment(Qt::AlignTop);
  _fulltext[item] = listitem.fulltext();
  _items.push_back(item);
  addItem(item);
}

QVector<QListWidgetItem *> ListViewWidget::items() { return _items; }
