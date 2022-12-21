//
// Created by Omar Elloumi on 18/12/2022.
//
#include "IA.hpp"
#include "Game.h"
#include "Bank.hpp"
#include "Landmark.h"
#include "Board.h"
#include "Establishment.h"

using namespace std;

Card* IA::chooseCard(Game& game){
    switch (level) {
        case Easy: return easyLevelCard(game);break;
        case Medium: return mediumLevelCard(game);break;
        case Hard: return hardLevelCard(game);break;
        default: return nullptr;break;
    }
}

Card* IA::easyLevelCard(Game& game){
    int iaBalance=game.getBank()->getBalance(idPlayer);

        for(auto landmark : hand.getLandmarks()){
            if(!landmark.second->isConstructed() && (landmark.second->getCost() <= iaBalance)){
                return landmark.second;
            }
        }

        for (auto possibleCard : game.getBoard()->getCards()){
            if(possibleCard.second.top()->getCost()<=iaBalance){
                return possibleCard.second.top();
            }
        }
    return nullptr;
    }

Card *IA::mediumLevelCard(Game & game) {
    return nullptr;
}

Card *IA::hardLevelCard(Game & game) {
    return nullptr;
}
