#include "listviewwidget.h"
#include "movie.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QScroller>
#include <QEasingCurve>
ListViewWidget::ListViewWidget(QWidget *parent) : QListWidget(parent) {
    setWordWrap(true);
    QVector<Movie> movies;
    QFile json(":/movies/MoviesList.txt");
    json.open(QFile::ReadOnly);
    for(const auto& obj : QJsonDocument::fromJson(json.readAll())["Search"].toArray())
        movies.push_back(Movie(obj.toObject()));
    for(const auto& movie : movies)
        addListItem(movie);
}

void ListViewWidget::resizeEvent(QResizeEvent *) {
    setIconSize(QSize(width()/2, height()/2));
}

void ListViewWidget::addListItem(const AbstractListItem &listitem) {
    auto item = new QListWidgetItem(
                QIcon(":/movies/Posters/" + (listitem.hasIcon() ? listitem.icon() : "NoPoster.jpg")),
                listitem.text(), this);
    item->setTextAlignment(Qt::AlignTop);
    addItem(item);
}
