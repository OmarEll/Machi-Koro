#ifndef MACHIKORO_FICHIER_STRATEGY_H
#define MACHIKORO_FICHIER_STRATEGY_H

#include "Game.h"
#include "Enums.hpp"
class Strategy{
private:
    Level level;
    void easyLevelCard(Game& game);
    void mediumLevelCard(Game& game);
    void hardLevelCard(Game& game);
public:
    Strategy(Level lvl):level(lvl){}
    void chooseCard(Game& game);
    ~Strategy();
};


#endif //MACHIKORO_FICHIER_STRATEGY_H
