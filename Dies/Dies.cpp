//
// Created by mabur on 03/12/2022.
//

#include "Dies.h"
#include <cstdlib>
#include <iostream>
#include "../UTILS/Enums.hpp"

using std::cout;
using std::cin;

int Dies::rollDice(const Player &current_player) const {
    return rand()%faces+1;
}
