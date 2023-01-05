#pragma once

#include "Player.hpp"
#include "IA/Strategy/Strategy.h"
#include "../../Game/Game.h"

class Game;
class Card;
class EasyLevel;

class IA : public Player {
private:
    Strategy* strategy;
public:
    friend class Game;
    IA(Level lvl,Collection_standard& g) : Player(("IA"+std::to_string(Player::id_counter)),g){
        switch (lvl) {
            case Easy: strategy=new EasyLevel();break;
            case Medium: strategy=new MediumLevel();break;
            case Hard: strategy=new HardLevel();break;
            default:strategy= nullptr; break;

        }
    }
    ~IA();
    Card* chosenCardByAi(){ return strategy->chooseCard();}
    bool isAI() override{ return true; }
};

