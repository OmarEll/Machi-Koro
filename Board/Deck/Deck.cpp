#include "Deck.h"

Deck::Deck(vector<Card*> cards){
    for(auto card : cards){
        addCardToDeck(card);
    }
}

Card* Deck::drawCard(){
    if (!cards.empty()){
        Card* card=cards.top();
        cards.pop();
        return card;
    }
    cout<<"la pile est vide, impossible de piocher";
    return nullptr;
};

void Deck::addCardToDeck(Card* c){
    cards.push(c);
}