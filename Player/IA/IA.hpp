#pragma once
#include "Player.hpp"

class IA : public Player {
private:
    Level level;
    Card* easyLevelCard(Game& game);
    Card* mediumLevelCard(Game& game);
    Card* hardLevelCard(Game& game);
public:
    IA(vector<Establishment*> a,vector<Landmark*> b, Level lvl) : Player(("IA"+std::to_string(Player::id_counter)),a,b),level(lvl) {}
    Card* chooseCard(Game& game);
    ~IA();
};
