#-------------------------------------------------
#
# Project created by QtCreator 2020-09-06T18:24:19
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MJPGCam
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    tvform.cpp

HEADERS += \
        mainwindow.h \
    tvform.h

FORMS += \
        mainwindow.ui \
    tvform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

CONFIG += link_pkgconfig
PKGCONFIG += gstreamer-1.0 gstreamer-video-1.0 gstreamer-plugins-base-1.0 gstreamer-base-1.0 gstreamer-audio-1.0 gstreamer-pbutils-1.0 glib-2.0

INCLUDEPATH += /usr/local/include/Qt5GStreamer/

LIBS += -L/usr/local/lib -lQt5GStreamer-1.0 -lQt5GLib-2.0 -lQt5GStreamerQuick-1.0 -lQt5GStreamerUi-1.0 -lQt5GStreamerUtils-1.0
LIBS += -L/usr/local/lib/arm-linux-gnueabihf/gstreamer-1.0
