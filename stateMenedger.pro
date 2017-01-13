TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/include/SDL2
LIBS += -lSDL2

SOURCES += main.cpp \
    menustate.cpp \
    playstate.cpp \
    game.cpp \
    map.cpp \
    snake.cpp \
    pausestate.cpp

HEADERS += \
    gamestate.h \
    menustate.h \
    playstate.h \
    cell.h \
    game.h \
    map.h \
    snake.h \
    pch.h \
    pausestate.h
