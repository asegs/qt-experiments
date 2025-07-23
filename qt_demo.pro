TEMPLATE = app
TARGET = qt_demo

QT = core gui
greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

SOURCES += \
    adjustor.cpp \
    gradient_bar.cpp \
    main.cpp \
    window.cpp

DISTFILES +=

RESOURCES += \
    qt_demo.qrc

HEADERS += \
    adjustor.h \
    gradient_bar.h \
    window.h

CONFIG += c++20

QMAKE_CXXFLAGS += -std=c++20

QMAKE_CXX = /usr/bin/g++-13
QMAKE_CC = /usr/bin/gcc-13
