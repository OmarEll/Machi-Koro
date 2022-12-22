#include <iostream>
#include "Deck.h"

using namespace std;

Deck::Deck(vector<Establishment*> cards){
    for(auto card : cards){
        addCardToDeck(card);
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