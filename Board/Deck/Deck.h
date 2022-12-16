#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include "Card.hpp"


class Deck{
private :
    stack<Card*> cards;

public :
    // Remarque : finalement pas besoin de m�thode isEmpty()
    // avec stack on a deja cards.empty() qui renvoie bool
    explicit Deck(vector<Card*>);
    Card* drawCard();
    void addCardToDeck(Card* c);
};

#endif // DECK_H_INCLUDED