#ifndef MOVIE_H
#define MOVIE_H

#include <QJsonObject>
#include "listdata.h"

class Movie : public AbstractListItem {
    QString _text;
    QString _icon;
public:
    Movie(QJsonObject movie);
    virtual QString text() const override;
    virtual bool hasIcon() const override;
    virtual QString icon() const override;
};

#endif // MOVIE_H
