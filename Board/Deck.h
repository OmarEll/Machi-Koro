#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include "../Card/Card.hpp"


class Deck{
private :
    stack<Card*> cards;

public :
    // Remarque : finalement pas besoin de m�thode isEmpty()
    // avec stack on a deja cards.empty() qui renvoie bool

    Card* drawCard(){
        if (!cards.empty()){
            return cards.pop();
        }
        cout<<"la pile est vide, impossible de piocher";
        return nullptr;
    };

    void addCardToDeck(Card* c){
        cards.push(c);
    }
};

#endif // DECK_H_INCLUDED
