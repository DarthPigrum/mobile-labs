#include <QDebug>
#include <QMap>
#include <QVector>
#include <QtMath>
#include <QRandomGenerator>
#include <QTextCodec>
template <typename T> void print(T value) { qDebug() << value; }
int randomValue(int maxValue) {
  switch (QRandomGenerator::global()->bounded(0, 6)) {
  case 0:
    return 0;
  case 1:
    return std::ceil(maxValue * 0.7);
  case 2:
    return std::ceil(maxValue * 0.9);
  default:
    return maxValue;
  }
}

int main() {
  QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
  QString studentsStr =
      "Дмитренко Олександр - ІП-84; Матвійчук Андрій - ІВ-83; Лесик Сергій - "
      "ІО-82; Ткаченко Ярослав - ІВ-83; Аверкова Анастасія - ІО-83; Соловйов "
      "Даніїл - ІО-83; Рахуба Вероніка - ІО-81; Кочерук Давид - ІВ-83; "
      "Лихацька Юлія - ІВ-82; Головенець Руслан - ІВ-83; Ющенко Андрій - "
      "ІО-82; "
      "Мінченко Володимир - ІП-83; Мартинюк Назар - ІО-82; Базова Лідія - "
      "ІВ-81; Снігурець Олег - ІВ-81; Роман Олександр - ІО-82; Дудка Максим - "
      "ІО-81; Кулініч Віталій - ІВ-81; Жуков Михайло - ІП-83; Грабко Михайло - "
      "ІВ-81; Іванов Володимир - ІО-81; Востриков Нікіта - ІО-82; Бондаренко "
      "Максим - ІВ-83; Скрипченко Володимир - ІВ-82; Кобук Назар - ІО-81; "
      "Дровнін Павло - ІВ-83; Тарасенко Юлія - ІО-82; Дрозд Світлана - ІВ-81; "
      "Фещенко Кирил - ІО-82; Крамар Віктор - ІО-83; Іванов Дмитро - ІВ-82";
  // Завдання 1
  // Заповніть словник, де:
  // - ключ – назва групи
  // - значення – відсортований масив студентів, які відносяться до відповідної
  // групи

  QMap<QString, QVector<QString>> studentsGroups;

  // Ваш код починається тут

  for (const auto &student : studentsStr.split("; ")) {
    auto pair = student.split(" - ");
    studentsGroups[pair[1]].push_back(pair[0]);
  }

  // Ваш код закінчується тут

  print("Завдання 1");
  print(studentsGroups);

  // Дано масив з максимально можливими оцінками

  QVector<int> points{12, 12, 12, 12, 12, 12, 12, 16};

  // Завдання 2
  // Заповніть словник, де:
  // - ключ – назва групи
  // - значення – словник, де:
  //   - ключ – студент, який відносяться до відповідної групи
  //   - значення – масив з оцінками студента (заповніть масив випадковими
  //   значеннями, використовуючи функцію `randomValue(maxValue: Int) -> Int`)

  QMap<QString, QMap<QString, QVector<int>>> studentPoints;

  // Ваш код починається тут

  for (const auto &group : studentsGroups.keys())
    for (const auto &student : studentsGroups[group])
      for (const auto &max : points)
        studentPoints[group][student].push_back(randomValue(max));

  // Ваш код закінчується тут

  print("Завдання 2");
  print(studentPoints);

  // Завдання 3
  // Заповніть словник, де:
  // - ключ – назва групи
  // - значення – словник, де:
  //   - ключ – студент, який відносяться до відповідної групи
  //   - значення – сума оцінок студента

  QMap<QString, QMap<QString, int>> sumPoints;

  // Ваш код починається тут

  for (const auto &group : studentPoints.keys())
    for (const auto &student : studentPoints[group].keys())
      for (const auto &mark : studentPoints[group][student])
        sumPoints[group][student] += mark;

  // Ваш код закінчується тут

  print("Завдання 3");
  print(sumPoints);

  // Завдання 4
  // Заповніть словник, де:
  // - ключ – назва групи
  // - значення – середня оцінка всіх студентів групи

  QMap<QString, double> groupAvg;

  // Ваш код починається тут

  for (const auto &group : sumPoints.keys()) {
    for (const auto &student : sumPoints[group].keys())
      groupAvg[group] += sumPoints[group][student];
    groupAvg[group] /= sumPoints[group].size();
  }

  // Ваш код закінчується тут

  print("Завдання 4");
  print(groupAvg);

  // Завдання 5
  // Заповніть словник, де:
  // - ключ – назва групи
  // - значення – масив студентів, які мають >= 60 балів

  QMap<QString, QVector<QString>> passedPerGroup;

  // Ваш код починається тут

  for (const auto &group : sumPoints.keys())
    for (const auto &student : sumPoints[group].keys())
      if (sumPoints[group][student] >= 60)
        passedPerGroup[group].push_back(student);

  // Ваш код закінчується тут

  print("Завдання 5");
  print(passedPerGroup);
}
// Приклад виведення. Ваш результат буде відрізнятися від прикладу через
// використання функції random для заповнення масиву оцінок та через інші вхідні
// дані.
//
//Завдання 1
//["ІВ-73": ["Гончар Юрій", "Давиденко Костянтин", "Капінус Артем", "Науменко
//Павло", "Чередніченко Владислав"], "ІВ-72": ["Бортнік Василь", "Киба Олег",
//"Овчарова Юстіна", "Тимко Андрій"], "ІВ-71": ["Андрющенко Данило", "Гуменюк
//Олександр", "Корнійчук Ольга", "Музика Олександр", "Трудов Антон", "Феофанов
//Іван"]]
//
//Завдання 2
//["ІВ-73": ["Давиденко Костянтин": [5, 8, 9, 12, 11, 12, 0, 0, 14], "Капінус
//Артем": [5, 8, 12, 12, 0, 12, 12, 12, 11], "Науменко Павло": [4, 8, 0, 12, 12,
// 11, 12, 12, 15], "Чередніченко Владислав": [5, 8, 12, 12, 11, 12, 12, 12,
// 15],
//"Гончар Юрій": [5, 6, 0, 12, 0, 11, 12, 11, 14]], "ІВ-71": ["Корнійчук Ольга":
//[0, 0, 12, 9, 11, 11, 9, 12, 15], "Музика Олександр": [5, 8, 12, 0, 11, 12, 0,
// 9, 15], "Гуменюк Олександр": [5, 8, 12, 9, 12, 12, 11, 12, 15], "Трудов
//Антон": [5, 0, 0, 11, 11, 0, 12, 12, 15], "Андрющенко Данило": [5, 6, 0, 12,
// 12, 12, 0, 9, 15], "Феофанов Іван": [5, 8, 12, 9, 12, 9, 11, 12, 14]],
//"ІВ-72": ["Киба Олег": [5, 8, 12, 12, 11, 12, 0, 0, 11], "Овчарова Юстіна":
//[5, 8, 12, 0, 11, 12, 12, 12, 15], "Бортнік Василь": [4, 8, 12, 12, 0, 12, 9,
// 12, 15], "Тимко Андрій": [0, 8, 11, 0, 12, 12, 9, 12, 15]]]
//
//Завдання 3
//["ІВ-72": ["Бортнік Василь": 84, "Тимко Андрій": 79, "Овчарова Юстіна": 87,
//"Киба Олег": 71], "ІВ-73": ["Капінус Артем": 84, "Науменко Павло": 86,
//"Чередніченко Владислав": 99, "Гончар Юрій": 71, "Давиденко Костянтин": 71],
//"ІВ-71": ["Корнійчук Ольга": 79, "Трудов Антон": 66, "Андрющенко Данило": 71,
//"Гуменюк Олександр": 96, "Феофанов Іван": 92, "Музика Олександр": 72]]
//
//Завдання 4
//["ІВ-71": 79.333336, "ІВ-72": 80.25, "ІВ-73": 82.2]
//
//Завдання 5
//["ІВ-72": ["Бортнік Василь", "Киба Олег", "Овчарова Юстіна", "Тимко Андрій"],
//"ІВ-73": ["Давиденко Костянтин", "Капінус Артем", "Чередніченко Владислав",
//"Гончар Юрій", "Науменко Павло"], "ІВ-71": ["Музика Олександр", "Трудов
//Антон", "Гуменюк Олександр", "Феофанов Іван", "Андрющенко Данило", "Корнійчук
//Ольга"]]
