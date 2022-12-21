#include "StandardBoard.h"
#include <string>


StandardBoard::StandardBoard(int nbCardsMax, map<EstablishmentsNames,stack<Establishment*>> cards):Board() {
    setNbCardsMax(nbCardsMax);   // inutile dans le standard non?
    setCards(cards);
}

void StandardBoard::displayCards() {  // méthode à mettre dans le plateau directement non?
    for (auto card : cards){
        cout<<card.second.size()<<" "<<card.second.top()->getCardName()<<"\n" ;
        cout<<"   Color : "<<card.second.top()->getColor()<<"\n" ;
        cout<<"   Earned coins : "<<card.second.top()->getEarnedCoins()<<"\n" ;
        cout<<"   Price : "<<card.second.top()->getCost()<<"\n" ;
        cout<<"   "<<card.second.top()->getDescription()<<"\n" ;
    }
}

/*
Board& StandardBoard::createBoard() {
    return nullptr;
}
*/