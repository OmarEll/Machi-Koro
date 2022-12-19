//
// Created by Omar Elloumi on 18/12/2022.
//
#include "IA.hpp"
Card* IA::chooseCard(Game& game){
    switch (level) {
        case Easy: easyLevelCard(game);break;
        case Medium:mediumLevelCard(game);break;
        case Hard:hardLevelCard(game);break;
        default:break;
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

    }
