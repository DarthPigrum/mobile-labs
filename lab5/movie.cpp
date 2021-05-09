#include "movie.h"

QString jsonObjectPrinter(QJsonObject obj, QStringList exceptions = {}) {
  QString res;
  for (const auto &key : obj.keys()) {
    if (exceptions.contains(key))
      continue;
    res += key + ": " + obj[key].toString() + "\n";
  }
  return res;
}

Movie::Movie(QJsonObject movie)
    : _text(movie["Title"].toString() +
            (movie["Year"].toString().isEmpty()
                 ? ""
                 : "\n\n" + movie["Year"].toString()) +
            (movie["Type"].toString().isEmpty()
                 ? ""
                 : "\n\n" + movie["Type"].toString())),
      _icon(movie["Poster"].toString()),
      _fulltext(movie["Title"].toString() + "\n\n" +
                jsonObjectPrinter(movie, {"Title", "Poster"})) {}

QString Movie::text() const { return _text; }

QString Movie::fulltext() const { return _fulltext; }

bool Movie::hasIcon() const { return !_icon.isEmpty(); }

QString Movie::icon() const { return _icon; }
