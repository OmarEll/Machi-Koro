//
// Created by mabur on 02/12/2022.
//
#pragma once

#include "Game.h"
#include "../Collection/Collection_GreenValley.h"

class GreenValleyExpansion : public Game{
private :
    GreenValleyExpansion(Collection_GreenValley&);
public:
    friend class Game;
    GreenValleyExpansion(Collection_GreenValley&,vector<Player*>);
    ~GreenValleyExpansion(){};
    void DoTurn(Player& current_player) override;
    void Do_Game() override;
    void initGame() override;

};

