#pragma once

#include "Game.h"
#include "../Collection/Collection_standard.h"
class StandardExpansion : public Game {
private :
    StandardExpansion(vector<Player*>,Collection_standard&);

public:
    friend class Game;
    ~StandardExpansion() = default;
    void DoTurn(Player& current_player) override;
    void Do_Game() override;
    void initGame() override;

};


