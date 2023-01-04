//
// Created by mabur on 02/12/2022.
//
#pragma once

#include "Game.h"
#include "../Collection/Collection_GreenValley.h"

class GreenValleyExpansion : public Game{
public:
    friend class Game;
    GreenValleyExpansion(Collection_GreenValley&){};
    ~GreenValleyExpansion(){};
    void DoTurn(Player& current_player) override{};
    void Do_Game() override{};
    void initGame() override{};
    int dice_turn (Player& current_player) override{};

};

