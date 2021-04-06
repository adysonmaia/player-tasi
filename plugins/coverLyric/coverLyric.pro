# -------------------------------------------------
# Project created by QtCreator 2009-11-21T16:46:31
# -------------------------------------------------
QT += network \
    webkit \
    xml \
    phonon
TEMPLATE = lib
CONFIG += plugin
INCLUDEPATH += ../../../player-tasi
SOURCES += coverlyric.cpp \
    controller.cpp \
    covermodel.cpp \
    lyricmodel.cpp
HEADERS += coverlyric.hpp \
    controller.hpp \
    covermodel.hpp \
    lyricmodel.hpp
TARGET = $$qtLibraryTarget(coverLyric)
DESTDIR = ../../plugins
