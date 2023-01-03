//
// Created by mabur on 02/12/2022.
//

#pragma once

#include "Game.h"
#include "../Collection/Collection_harbor.h"



class HarborExpansion : public Game {
public :
    HarborExpansion(vector<Player*>,Collection_harbor&);
    ~HarborExpansion(){};
    void DoTurn(Player& current_player) override;
    void Do_Game() override;
    void initGame() override;;

};


