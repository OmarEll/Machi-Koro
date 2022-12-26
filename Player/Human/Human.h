//
// Created by Omar Elloumi on 24/12/2022.
//

#pragma once
#include "../Player.hpp"

class Player;

class Human : public Player{
public:
    Human(const string& nm,Collection& g): Player(nm,g){};
    bool isAI() override { return false;}
};



