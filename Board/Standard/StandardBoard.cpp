#include "StandardBoard.h"
#include "Establishment.h"
#include <string>


StandardBoard::StandardBoard(int nbCardsMax, map<EstablishmentsNames,stack<Establishment*>> cards):Board() {
    setNbCardsMax(nbCardsMax);   // inutile dans le standard non?
    setCards(cards);
}



/*
Board& StandardBoard::createBoard() {
    return nullptr;
}
*/