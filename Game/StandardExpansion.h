#pragma once

#include "Game.h"
#include "../Collection/Collection_standard.h"
class StandardExpansion : public Game {
private :
    StandardExpansion(Collection_standard&);

public:
    StandardExpansion(vector<Player *> joueur, Collection_standard &col);
    friend class Game;
    ~StandardExpansion() = default;
    void DoTurn(Player& current_player) override;
    void Do_Game() override;
    void initGame() override;

};


