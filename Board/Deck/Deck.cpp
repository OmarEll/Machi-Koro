#include "Deck.h"

Deck::Deck(vector<Establishment*> cards){
    for(auto card : cards){
        addCardToDeck(card);
    }
}

Establishment* Deck::drawCard(){
    if (!cards.empty()){
        Establishment* card=cards.top();
        cards.pop();
        return card;
    }
    cout<<"la pile est vide, impossible de piocher";
    return nullptr;
};

void Deck::addCardToDeck(Establishment* c){
    cards.push(c);
}