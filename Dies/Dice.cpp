//
// Created by mabur on 03/12/2022.
//

#include "Dice.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;

int Dice::rollDice() const {
    return rand()%faces+1;
}
