#ifndef MOVIE_H
#define MOVIE_H

#include "listdata.h"
#include <QJsonObject>

class Movie : public AbstractListItem {
  QString _text;
  QString _icon;
  QString _fulltext;

public:
  Movie(QJsonObject movie);
  virtual QString text() const override;
  virtual bool hasIcon() const override;
  virtual QString icon() const override;
  virtual QString fulltext() const override;
};

#endif // MOVIE_H
