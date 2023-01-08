QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#INCLUDEPATH +=Card/Establishment
SOURCES += \
    *.cpp \
    ../Card/Establishment/Establishment.cpp \
    ../Board/GreenValleyBoard.cpp \
    ../Board/Board.cpp \
    ../Board/Standard/StandardBoard.cpp \
    ../Board/Deluxe/DeluxeBoard.cpp \
    ../Board/Harbor/HarborBoard.cpp \
    ../Bank/Bank.cpp \
    ../Game/game.cpp \
    ../Game/StandardExpansion.cpp \
    ../Game/HarborExpansion.cpp \
    ../Game/GreenValleyExpansion.cpp \
    ../Dice/dice.cpp \
    ../Card/Landmark/Landmark.cpp \
    ../Player/Hand/Hand.cpp \
    ../Player/Player.cpp \
    ../Collection/Collection_standard.cpp \
    ../Collection/Collection_harbor.cpp \
    ../Collection/Collection_GreenValley.cpp \
    ../Board/Deck/Deck.cpp
HEADERS += \
    *.h \
    ../Card/Establishment/Establishment.h \
    ../Board/GreenValleyBoard.h  \
    ../Board/Board.h  \
    ../Board/Standard/StandardBoard.h \
    ../Board/Deluxe/DeluxeBoard.h \
    ../Board/Harbor/HarborBoard.h \
    ../Card/Landmark/Landmark.h \
    ../Bank/Bank.hpp \
    ../Game/game.h \
    ../Game/StandardExpansion.h \
    ../Game/HarborExpansion.h \
    ../Game/GreenValleyExpansion.h \
    ../Dice/dice.h \
    ../Player/Hand/Hand.hpp \
    ../Player/Player.h \
    ../Collection/Collection_standard.h \
    ../Collection/Collection_harbor.h \
    ../Collection/Collection_GreenValley.h \
    ../Board/Deck/Deck.h
FORMS += \
       *.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    style.css


