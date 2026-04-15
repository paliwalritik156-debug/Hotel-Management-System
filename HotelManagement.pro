QT += core gui widgets sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql
CONFIG += c++17
TARGET = HotelManagement
TEMPLATE = app
SOURCES += main.cpp mainwindow.cpp
HEADERS += mainwindow.h models.h
DEFINES += QT_DEPRECATED_WARNINGS
