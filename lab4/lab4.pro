QT       += core gui charts printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addmoviedialog.cpp \
    listviewwidget.cpp \
    movie.cpp \
    qcustomplot/qcustomplot.cpp \
    drawingviewwidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    addmoviedialog.h \
    listdata.h \
    listviewwidget.h \
    movie.h \
    qcustomplot/qcustomplot.h \
    drawingviewwidget.h \
    mainwindow.h

FORMS += \
    addmoviedialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle.properties \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

RESOURCES += \
    files.qrc
