//
// Created by mabur on 19/12/2022.
//
#include "GreenValleyBoard.h"
#include "Establishment.h"

void GreenValleyBoard::addEstablishmentToBoard(Establishment *e) {  // pour international exibit hall
    for (auto& establishment : cards){
        if(establishment.first == e->getCardName_Enum()){
            establishment.second.push(e);
        }
    }
}