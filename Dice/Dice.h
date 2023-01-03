//
// Created by mabur on 03/12/2022.
//

#pragma once

//#include "../Player/Player.hpp"

class Player;

class Dice {
private :
    int faces;
    int result;
public :
    Dice() : faces(6) {};
    ~Dice() = default;
    void rollDice();
    void reset_dice(){result = 0;}
    int GetResult(){return result;}
};


