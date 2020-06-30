TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "C:/SFML-2.5.1/include"
SOURCES += \
        Enemy.cpp \
        Friendly_postac.cpp \
        Player.cpp \
        coin.cpp \
        klasa_abstrakcyjna.cpp \
        menu.cpp \
        platforma.cpp \
        projekt.cpp \
        serce.cpp
LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    Enemy.h \
    Friendly_postac.h \
    Player.h \
    coin.h \
    klasa_abstrakcyjna.h \
    menu.h \
    platforma.h \
    serce.h
