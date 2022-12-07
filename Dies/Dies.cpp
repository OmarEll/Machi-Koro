//
// Created by mabur on 03/12/2022.
//

#include "Dies.h"
#include <cstdlib>
#include "../UTILS/Enums.hpp"
int Dies::rollDice(const Player &current_player) {
        if (current_player.hasLandmark(TrainStation))
            return rand()%(faces*2)+1;

    return ::rand()%faces+1;
}
