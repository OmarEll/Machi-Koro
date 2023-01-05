//
// Created by mabur on 02/12/2022.
//

#pragma once

#include "Game.h"
#include "../Collection/Collection_harbor.h"



class HarborExpansion : public Game {
    HarborExpansion(Collection_harbor&);
public :
    HarborExpansion(vector<Player *> joueur, Collection_standard &col);

    friend class Game;
    ~HarborExpansion(){};
    void DoTurn(Player& current_player) override;
    void Do_Game() override;
    void initGame() override;
    int dice_turn (Player& current_player) override;

};


