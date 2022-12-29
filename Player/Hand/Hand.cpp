#include "Hand.hpp"
#include "Establishment.h"
#include "Landmark.h"
#include "../Collection/Collection_standard.h"
#include "Card.hpp"
#include "Player.hpp"


Hand::Hand(Collection& g){
    for (auto est : g.GetLandmark()){
        landmarks.insert(pair<LandmarksNames,Landmark*>(est->getLandmarks(),est->Clone()));
    }
}

void Hand::addEstablishment(Establishment* card){
    EstablishmentsNames cardName=card->getCardName_Enum();
    if(establishments.find(card->getCardName_Enum())!=establishments.end()){
        establishments[cardName].push(card);
    }

}

void Hand::removeEstablishment(Establishment* card){
    EstablishmentsNames cardName=card->getCardName_Enum();
    if(establishments.find(cardName)!=establishments.end()){
        establishments[cardName].pop();
    }
}


vector<Establishment*> Hand::getColorCards(Colors color){
    vector<Establishment*> cards;
    for(auto establishment : establishments){
        if((establishment.second.top())->getColor()==color){
            stack<Establishment*> tmp;
            //ajouter tout les cartes identique dans cards (resultat)
            while(!establishment.second.empty()){
                auto est=establishment.second.top();
                cards.push_back(est);
                establishment.second.pop();
                tmp.push(est);
            }
            //rajouter tout les cartes enlever dans l'iteration precedente dans la pile de hand
            while(!tmp.empty()){
                establishment.second.push(tmp.top());
                tmp.pop();
            }

        }

    }
    return cards;
}

vector<Establishment*> Hand::getTypeCards(Types type){
    vector<Establishment*> cards;
    for(auto establishment : establishments){
        if((establishment.second.top())->getType()==type){
            stack<Establishment*> tmp;
            //ajouter tout les cartes identique dans cards (resultat)
            while(!establishment.second.empty()){
                auto est=establishment.second.top();
                cards.push_back(est);
                establishment.second.pop();
                tmp.push(est);
            }
            //rajouter tout les cartes enlever dans l'iteration precedente dans la pile de hand
            while(!tmp.empty()){
                establishment.second.push(tmp.top());
                tmp.pop();
            }
        }

    }
    return cards;
}

void Hand::addLandmark(LandmarksNames name) {
    for (auto Land : landmarks){
        if (name == Land.first){
            Land.second->setConstruction();
        }
    }

}
