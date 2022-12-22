//
// Created by sarah on 21/12/2022.
//
#include <stack>
#include "HarborBoard.h"
#include "Establishment.h"



HarborBoard::HarborBoard(Collection_harbor& col):Board() {   // pb : comment on fait pour que les cartes soient aléatoires
                                                                // il faut que elles soient toutes dans la pioche et ensuite
                                                                // qu'on les lire et qu'on les mette sur board
                                                                //-------------------------------------------------------------
    stack<Establishment*>* pile = nullptr;
    for (auto est : col.GetEstablishment()){
        pile = new stack<Establishment*>;
        if (est->getColor() != PURPLE){
            for (int i = 0; i < 6 ; i++){
                pile->push(est->Clone());}
        }
        else{
            for (int i = 0; i < 5 ; i++){
                pile->push(est->Clone());}
        }
        cards.insert(pair<EstablishmentsNames,stack<Establishment*>>(est->getCardName_Enum(),*pile));
    }
}

void HarborBoard::fillBoard() {
    while(cards.size()<10){
        Establishment * cardOffDeck = this->getDeck()->drawCard();  // marche pas incomplete type --------------------------
        if (cardOffDeck== nullptr) {   // pioche vide donc on ne peut pas remplir le board
            return;
        }
        for(auto pair : cards){
            if (pair.first == cardOffDeck->getCardName_Enum()){
                pair.second.push(cardOffDeck);
            }
        }
    }
}
