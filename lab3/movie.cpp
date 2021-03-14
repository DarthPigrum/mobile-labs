#include "movie.h"

Movie::Movie(QJsonObject movie) :
    _text(movie["Title"].toString()
  +(movie["Year"].toString().isEmpty() ? "" : "\n\n" + movie["Year"].toString())
  +(movie["Type"].toString().isEmpty() ? "" : "\n\n" + movie["Type"].toString())),
    _icon(movie["Poster"].toString()) {}

QString Movie::text() const {
    return _text;
}

bool Movie::hasIcon() const {
    return !_icon.isEmpty();
}

QString Movie::icon() const {
    return _icon;
}
