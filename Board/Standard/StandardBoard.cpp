#include "StandardBoard.h"

StandardBoard::StandardBoard(int nbCardsMax, map<EstablishmentsNames,stack<Establishment*>> cards):Board() {
    setNbCardsMax(nbCardsMax);
    setCards(cards);
}