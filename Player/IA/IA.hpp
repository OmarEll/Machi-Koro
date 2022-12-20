#pragma once

#include "Player.hpp"

class Game;
class Card;

class IA : public Player {
private:
    Level level;

public:
    IA(vector<Establishment*> a,vector<Landmark*> b, Level lvl) : Player(("IA"+std::to_string(Player::id_counter)),a,b),level(lvl) {}
    Card* chooseCard(Game&);
    Card* easyLevelCard(Game&);
    Card* mediumLevelCard(Game&);
    Card* hardLevelCard(Game&);
    ~IA() = default;
};
