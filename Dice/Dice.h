//
// Created by mabur on 03/12/2022.
//

#ifndef MACHI_KORO_DICE_H
#define MACHI_KORO_DICE_H
#include "../Player/Player.hpp"

class Dice {
private :
    int faces;
public :
    Dice() : faces(6) {};
    ~Dice();
    int rollDice() const;
};


#endif //MACHI_KORO_DICE_H
