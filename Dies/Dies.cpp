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
        if (current_player.hasLandmark(TrainStation)){
            unsigned int nb;
            cout<<"Voulez-vous utiliser un ou deux dés? (Tapez 1 ou 2)\n";
            cin>>nb;
            if(nb==2){
                return rand()%(faces*2)+1;
            }
        }
    return rand()%faces+1;
}
