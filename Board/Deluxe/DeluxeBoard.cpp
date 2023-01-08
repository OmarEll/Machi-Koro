//
// Created by sarah on 29/12/2022.
//
#include "DeluxeBoard.h"
#include "../Board.h"
#include <stack>
#include <vector>
#include <cstdlib>
#include "../Card/Establishment/Establishment.h"
/*
DeluxeBoard::DeluxeBoard(Collection_deluxe& col) : Board(){

    vector<Establishment*>* v = new vector<Establishment*>;

    for(auto est : col.Collection_harbor::GetEstablishment()){
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



void DeluxeBoard::fillBoard() {
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
*/
void DeluxeBoard::fillBoard() {
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


DeluxeBoard::DeluxeBoard(Collection_deluxe& col) : Board() {

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
