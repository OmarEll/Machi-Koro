//
// Created by mabur on 03/12/2022.
//

#ifndef MACHI_KORO_DIES_H
#define MACHI_KORO_DIES_H
#include "../Player/Player.hpp"

class Dies {
private :
    int faces;
public :
    Dies() : faces(6) {};
    ~Dies();
    int rollDice(const Player& current_player );
};


#endif //MACHI_KORO_DIES_H
