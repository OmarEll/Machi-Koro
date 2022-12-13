#include "Strategy.hpp"

void Strategy::chooseCard(Game& game){
    switch (level) {
        case Easy:easyLevelCard(game);break;
        case Medium:mediumLevelCard(game);break;
        case Hard:hardLevelCard(game);break;
        default:break;
    }
}

void Strategy::easyLevelCard(Game& game){
    
}