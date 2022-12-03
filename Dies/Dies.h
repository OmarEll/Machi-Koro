//
// Created by mabur on 03/12/2022.
#include "Player.hpp"
//

#ifndef MACHI_KORO_DIES_H
#define MACHI_KORO_DIES_H


class Dies {
private :
    int faces;
public :
    Dies();
    ~Dies();
    int rollDice(const Player& current_player );
};


#endif //MACHI_KORO_DIES_H
