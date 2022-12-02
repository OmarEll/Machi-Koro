#include "Game.hpp"

class Strategy
{
public:
    Strategy(/* args */);
    virtual void chooseCard(Game);
    ~Strategy();
};