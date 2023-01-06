//
// Created by mabur on 03/12/2022.
//

#include "Dice.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;

void Dice::rollDice() {
    srand(time(NULL));
    result = 8;
    //result = rand()%faces+1;
}
