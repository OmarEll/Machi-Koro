#pragma once

#include "Player.hpp"

class Game;
class Card;

class IA : public Player {
private:
    Level level;

public:
    IA(Level lvl,Collection& g) : Player(("IA"+std::to_string(Player::id_counter)),g),level(lvl){}
    Card* chooseCard(Game&);
    Card* easyLevelCard(Game&);
    Card* mediumLevelCard(Game&);
    Card* hardLevelCard(Game&);
    ~IA() = default;
};
