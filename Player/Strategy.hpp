#include "../Game/Game.h"

class Strategy{
public:
    Strategy(/* args */);
    virtual void chooseCard(Game);
    ~Strategy();
};