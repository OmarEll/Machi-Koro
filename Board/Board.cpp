//
// Created by mabur on 19/12/2022.
//
#include "Board.h"
#include "Establishment.h"
#include "Standard/StandardBoard.h"

Board* Board::board_instance = nullptr;

Establishment* Board::foundEstablishmentOnBoard(string choice) {
    EnumParser<EstablishmentsNames> fieldTypeParser;
    EstablishmentsNames val = fieldTypeParser.ParseSomeEnum(choice);
    Establishment* tmp = nullptr;
    for (auto establishment : cards){
        if (val == establishment.first){
            tmp = establishment.second.top();
            this->cards[val].pop();
            return tmp;
        }
    }
    return nullptr;
}

void Board::displayCards() {
    for (auto card : cards){
        cout<<card.second.size()<<" "<<card.second.top()->getCardName()<<"\n" ;
        cout<<"   Color : "<<card.second.top()->getColor()<<"\n" ;
        cout<<"   Type : "<<card.second.top()->getType()<<"\n" ;
        cout<<"   Earned coins : "<<card.second.top()->getEarnedCoins()<<"\n" ;
        cout<<"   Price : "<<card.second.top()->getCost()<<"\n" ;
        cout<<"   "<<card.second.top()->getDescription()<<"\n" ;
    }
}


Board *Board::getInstance(Collection& g) { // faire switch avec en paramètre en string ou enum pour extension
    if(board_instance==nullptr){
        board_instance=new StandardBoard(dynamic_cast<Collection_standard&>(g));
    }
    return board_instance;
}


