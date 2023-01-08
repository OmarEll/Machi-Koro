//
// Created by sarah on 21/12/2022.
//
#include <stack>
#include <vector>
#include <cstdlib>
#include "HarborBoard.h"
#include "../Card/Establishment/Establishment.h"

void HarborBoard::fillBoard() {
    while(cards.size()<10){
        Establishment * cardOffDeck = getDeck()->drawCard();
        if (cardOffDeck== nullptr) {   // pioche vide donc on ne peut pas remplir le board
            return;
        }
        bool found = false;
        for(auto pair : cards){
            if (pair.first == cardOffDeck->getCardName_Enum()){
                found = true;
                pair.second.push(cardOffDeck);
            }
        }
        if (found == false){
            stack<Establishment*>* newPile = new stack<Establishment*>;
            newPile->push(cardOffDeck);
            cards.insert(pair<EstablishmentsNames,stack<Establishment*>>(cardOffDeck->getCardName_Enum(),*newPile));
        }
    }
}


HarborBoard::HarborBoard(Collection_harbor& col):Board() {

    vector<Establishment*>* v = new vector<Establishment*>;

     for(auto est : col.GetEstablishment()){
         if (est->getColor() != PURPLE){
             for (int i = 0; i < 6 ; i++){
                 v->push_back(est->Clone());}
         }
         else{
             for (int i = 0; i < 5 ; i++){
                 v->push_back(est->Clone());}
         }
     }
    deck = new Deck(v);
     fillBoard();
}

