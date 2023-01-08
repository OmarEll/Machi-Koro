//
// Created by Omar Elloumi on 24/12/2022.
//

#include "Strategy.h"
#include "../../../Board/Board.h"

Card* EasyLevel::chooseCard(Player* ia,int balance,Board* board){
    auto landCards=ia->getHand()->getLandmarks();
    auto boardCards=board->getCards();
    for(auto landmark: landCards){
        if(landmark.second->getCost()<=balance){
            std::cout<<ia->getName()<<" a choisi d'acheter "<<landmark.second->getCardName()<<std::endl;
            return dynamic_cast<Card*>(landmark.second);
        }
    }
    for(auto establishment: boardCards){
        if(establishment.second.top()->getCost()<=balance){
            std::cout<<ia->getName()<<" a choisi d'acheter "<<establishment.second.top()->getCardName()<<std::endl;
            return dynamic_cast<Card*>(establishment.second.top());
        }
    }
    std::cout<<ia->getName()<<" a choisi de rien acheter"<<std::endl;
    return nullptr;
}

