#pragma once

#include "Game.h"

class StandardExpansion : public Game {
private :


public:
    StandardExpansion(vector<Player*>);
    StandardExpansion();
    ~StandardExpansion() = default;
    void DoTurn(Player& current_player) override;
    void Do_Game() override;

};


