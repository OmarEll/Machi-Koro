//
// Created by mabur on 19/12/2022.
//
#include "Board.h"

Board* Board::board_instance = nullptr;

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

/*
Board *Board::getInstance() {
    if(board_instance==nullptr){
        board_instance=new Board();
    }
    return board_instance;
}
 */

