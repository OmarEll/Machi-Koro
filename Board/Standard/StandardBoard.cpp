#include "StandardBoard.h"

StandardBoard::StandardBoard(int nbCardsMax, map<EstablishmentsNames,stack<Establishment*>> cards):Board() {
    setNbCardsMax(nbCardsMax);
    setCards(cards);
}

void StandardBoard::displayCards() {

}

/*
Board& StandardBoard::createBoard() {
    return nullptr;
}
*/