#include <QCoreApplication>
#include <QTime>
#include <QDateTime>
#include <QDebug>

class TimeMZ {
  unsigned int _hours;
  unsigned int _minutes;
  unsigned int _seconds;
  unsigned int toSeconds() const {
    return _hours * 3600 + _minutes * 60 + _seconds;
  }
  explicit TimeMZ(unsigned int seconds) {
    _hours = seconds / 3600;
    _minutes = (seconds - 3600 * _hours) / 60;
    _seconds = seconds - 3600 * _hours - 60 * _minutes;
  }
  static QString formatNumber(unsigned int num) {
    return (num > 9 ? "" : "0") + QString::number(num);
  }

public:
  TimeMZ() : TimeMZ(0, 0, 0) {}
  explicit TimeMZ(unsigned int hours, unsigned int minutes,
                  unsigned int seconds)
      : _hours(hours <= 23 ? hours : 0),
        _minutes(minutes <= 59 ? minutes : 0),
        _seconds(seconds <= 59 ? seconds : 0) {}
  explicit TimeMZ(QTime time)
      : TimeMZ(time.hour(), time.minute(), time.second()) {}
  explicit TimeMZ(QDateTime date) : TimeMZ(date.time()) {}
  QString toString() {
    return formatNumber(_hours > 12 ? _hours - 12 : _hours) + ":" +
           formatNumber(_minutes) + ":" + formatNumber(_seconds) + " " +
           (_hours > 12 ? "PM" : "AM");
  }
  TimeMZ operator+(const TimeMZ &time) {
    return TimeMZ((toSeconds() + time.toSeconds()) % 86400);
  }
  TimeMZ operator-(const TimeMZ &time) {
    return TimeMZ(toSeconds() >= time.toSeconds()
                      ? toSeconds() - time.toSeconds()
                      : 86400 + toSeconds() - time.toSeconds());
  }
};

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  TimeMZ endDay(23, 59, 59);
  TimeMZ afterMidday(12, 0, 1);
  TimeMZ midnight;
  TimeMZ afterMidnight(QDateTime(QDate(2001, 3, 19), QTime(0, 0, 1)));
  qDebug() << endDay.toString() + " + " + afterMidday.toString() + " = " +
                  (endDay + afterMidday).toString();
  qDebug() << midnight.toString() + " - " + afterMidnight.toString() + " = " +
                  (midnight - afterMidnight).toString();
  return a.exec();
}
