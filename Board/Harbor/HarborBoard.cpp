//
// Created by sarah on 21/12/2022.
//
#include <stack>
#include <vector>
#include <cstdlib>
#include "HarborBoard.h"
#include "Establishment.h"

void HarborBoard::fillBoard() {
    while(cards.size()<10){
        Establishment * cardOffDeck = getDeck()->drawCard();
        if (cardOffDeck== nullptr) {   // pioche vide donc on ne peut pas remplir le board
            return;
        }
        for(auto pair : cards){
            if (pair.first == cardOffDeck->getCardName_Enum()){
                pair.second.push(cardOffDeck);
                return;
            }
        }
        stack<Establishment*>* newPile = nullptr;
        newPile->push(cardOffDeck);
        cards.insert(pair<EstablishmentsNames,stack<Establishment*>>(cardOffDeck->getCardName_Enum(),*newPile));
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

     size_t nb = v->size();
     for (size_t i=0; i<nb;i++){
         size_t j = rand()%v->size() +1;
         getDeck()->addCardToDeck(v[j].back());
         v->erase(v->begin() + j);
     }

     fillBoard();
}

