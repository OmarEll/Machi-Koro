#include <iostream>
#include "Deck.h"

using namespace std;

Deck::Deck(vector<Establishment*> *cards){
    size_t nb = cards->size();
    for (size_t i=0; i<nb;i++){
        nb = cards->size();
        srand(time(NULL));
        size_t j = rand()%cards->size() ;
        addCardToDeck(cards->at(j));
        cards->erase(cards->begin() + j);
    }
}

Establishment* Deck::drawCard(){
    if (!cardsDeck.empty()){
        Establishment* card=cardsDeck.top();
        cardsDeck.pop();
        return card;
    }
    cout<<"la pile est vide, impossible de piocher";
    return nullptr;
};

void Deck::addCardToDeck(Establishment* c){
    cardsDeck.push(c);
}