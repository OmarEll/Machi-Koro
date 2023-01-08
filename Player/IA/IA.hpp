#pragma once

#include "Player.hpp"
#include "./Strategy/Strategy.h"
#include "../../Game/Game.h"

class Strategy;
class Game;
class Card;
class EasyLevel;


class IA : public Player {
private:
    Strategy* strategy;
    Board* board;
public:
    friend class Game;
    IA(Strategy* strat,Collection_standard& g,Board* brd) : Player(("IA"+std::to_string(Player::id_counter)),g),strategy(strat),board(brd){}
    ~IA();
    Strategy* getStrategy() { return strategy; }
    bool isAI() override { return true; }
};


/*Card* chosenCardByAi(int balance){
    if(strategy!= nullptr)
        return strategy->chooseCard(dynamic_cast<Player*>(this),balance,board);
    else return nullptr;
}*/