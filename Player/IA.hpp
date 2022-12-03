#include "Player.hpp"
#include "Strategy.hpp"

class IA : public Player {
private:
    Strategy strategy;
public:
    IA(/* args */);
    ~IA();
};