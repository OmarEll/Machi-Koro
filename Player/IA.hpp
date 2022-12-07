#ifndef MACHIKORO_FICHIER_IA_H
#define MACHIKORO_FICHIER_IA_H

#include "Player.hpp"
#include "Strategy/Strategy.hpp"

class IA : public Player {
private:
    Strategy strategy;
public:
    IA(Expansions myExpansion1, Expansions myExpansion, Level lvl) : Player(("IA"+std::to_string(Player::id_counter)), myExpansion1),
    strategy(lvl) {}
    ~IA();
};

#endif //MACHIKORO_FICHIER_IA_H