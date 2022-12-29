//
// Created by sarah on 29/12/2022.
//
#include "DeluxeBoard.h"

DeluxeBoard::DeluxeBoard(Collection_harbor& colHarbor, Collection_deluxe& colGV): HarborBoard(colHarbor){

    vector<Establishment*>* v = new vector<Establishment*>;

    for(auto est : colGV.GetEstablishment()){
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

    fillBoard();  // pb le constructeur de Harbor à déjà fillBoard non?-----------------------------------------------
                    // et idem pour le deck ... on peut pas utiliser le constructeur de harbor non? mais du coup on enlève héritage?
}