//
// Created by mabur on 02/12/2022.
//
#pragma once

#include "Game.h"
#include "../Collection/Collection_deluxe.h"

class DeluxeExpansion : public Game{
public:
    DeluxeExpansion(vector<Player*>,Collection_deluxe&){};
    ~DeluxeExpansion(){};
    void DoTurn(Player& current_player) override{};
    void Do_Game() override{};
    void initGame() override{};
    int dice_turn (Player& current_player) override{};

};

