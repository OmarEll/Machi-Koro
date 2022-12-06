//
// Created by mabur on 03/12/2022.
//

#include "Dies.h"
#include <cstdlib>

int Dies::rollDice(const Player &current_player) {
    for (auto radio : current_player.getHand().GetLandmarks()){
        if (radio.GetName() == "TrainStation" && TrainStation.construct())
            return rand()%12+1;
    }
    return ::rand()%6+1;
}
