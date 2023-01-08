#include "Hand.hpp"
#include "../../Card/Establishment/Establishment.h"
#include "../../Card/Landmark/Landmark.h"
#include "../Player.hpp"

Hand::Hand(Collection_standard& g){
    for (auto est : g.GetLandmark()){
        landmarks.insert(pair<LandmarksNames,Landmark*>(est->getLandmarks(),est->Clone()));
    }
}

void Hand::addEstablishment(Establishment* card, Player& p){
    EstablishmentsNames cardName=card->getCardName_Enum();
    if (card->getColor() != PURPLE || (card->getColor() == PURPLE && p.getHand()->getEstablishments().find(cardName) != p.getHand()->getEstablishments().end())){
        card->setOwner(&p);
        if(establishments.find(card->getCardName_Enum())!=establishments.end()){
            establishments[cardName].push(card);
        }
        else{
            stack<Establishment*>* pile = new stack<Establishment*>;
            pile->push(card);
            establishments.insert(pair<EstablishmentsNames,stack<Establishment*>>(card->getCardName_Enum(),*pile));
        }
    }
    else{
        cout << "Impossible, vous possedez deja cette carte violette" << endl;
    }
}


void Hand::removeEstablishment(Establishment* card){
    EstablishmentsNames cardName=card->getCardName_Enum();
    if(establishments.find(cardName)!=establishments.end()){
        establishments[cardName].pop();
        if (establishments[cardName].size()==0){
            establishments.erase(cardName);
        }
    }
    else{
        cout << "L'etablissement n'est pas dans la main" << endl;
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

void Hand::addToListLandmark(Landmark* card){
    LandmarksNames cardName=card->getLandmarks();
    landmarks[cardName]=card;
};
void Hand::addLandmark(LandmarksNames name) {
    for (auto Land : landmarks){
        if (name == Land.first){
            Land.second->setConstruction();
        }
    }
}

int Hand::numberOfConstructedLandmarks(){
    int nb = 0;
    for (auto Land : landmarks){
        if (Land.second->isConstructed()){
            nb++;
        }
    }
    return nb;
}
