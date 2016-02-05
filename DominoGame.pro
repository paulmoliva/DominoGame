
QT += core gui \
    multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = DominoGame



TEMPLATE = app

SOURCES += main.cpp \
    game.cpp \
    cdomino.cpp \
    board.cpp \
    crandom.cpp \
    cplayer.cpp \
    button.cpp \
    startbutton.cpp

HEADERS += \
    game.h \
    cdomino.h \
    board.h \
    crandom.h \
    cplayer.h \
    button.h \
    startbutton.h



RESOURCES += \
    resouces.qrc





