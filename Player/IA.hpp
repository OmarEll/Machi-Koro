#ifndef MACHIKORO_FICHIER_IA_H
#define MACHIKORO_FICHIER_IA_H

#include "Player.hpp"
#include "Strategy.hpp"

class IA : public Player {
private:
    Strategy strategy;
public:
    IA(/* args */);
    ~IA();
};

#endif //MACHIKORO_FICHIER_IA_H