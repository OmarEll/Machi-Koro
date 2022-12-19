//
// Created by mabur on 19/12/2022.
//
#include "Board.h"

Establishment *Board::foundEstablishmentOnBoard(string choice) {
    EnumParser<EstablishmentsNames> fieldTypeParser;
    EstablishmentsNames val = fieldTypeParser.ParseSomeEnum(choice);
    Establishment* tmp = nullptr;
    for (auto establishment : cards){
        if (val == establishment.first){
            tmp = establishment.second.top();
            establishment.second.pop();
            return tmp;
        }
    }
    return nullptr;
}

