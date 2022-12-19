//
// Created by mabur on 03/12/2022.
//

#pragma once

#include "../Player/Player.hpp"

class Dice {
private :
    int faces;
    int result;
public :
    Dice() : faces(6) {};
    ~Dice();
    void rollDice();
    int GetResult(){return result;}
};


