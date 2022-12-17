
#include "Hand.hpp"
#include "../Card/Establishment/Establishment.h"

Hand::Hand(Expansions myExpansion){
    switch (myExpansion) {
        case Standard:
            //establishments : add bakery + wheat field
            //landmarks: Train Station, Shopping Mall, Amusement Park & Radio Tower – face down (Under Construction).
            break;
        case Harbor:
            //establishments : add bakery + wheat field
            //landmarks: city hall (already built), harbor, airport, Train Station, Shopping Mall, Amusement Park & Radio Tower
            break;
        case GreenValley:
            //establishments : add bakery + wheat field
            //landmarks: Train Station, Shopping Mall, Amusement Park & Radio Tower – face down (Under Construction).
            break;
        case Deluxe:
            //landmarks: Train Station, Shopping Mall, Amusement Park & Radio Tower – face down (Under Construction).
            break;
        default:break;
    }
}
void Hand::addEstablishment(EstablishmentsNames cardName){
    if(establishments.find(cardName)!=establishments.end())
        establishments[cardName].second++;
    else
        cout<< cardName << "n'existe pas.";
}

void Hand::removeEstablishment(EstablishmentsNames cardName){
    if(establishments.find(cardName)!=establishments.end()){
        establishments[cardName].second--;
        if(establishments[cardName].second<=0){
            establishments.erase(cardName);
        }
    }
    else
        cout<< cardName << "n'existe pas.";
}
vector<Establishment*> Hand::getColorCards(Colors color){
    vector<Establishment*> cards;
    for(auto establishment : establishments){
        if((establishment.second.first)->getColor()==color)
            cards.push_back(establishment.second.first);
    }
    return cards;
}

vector<Establishment*> Hand::getTypeCards(Types type){
    vector<Establishment*> cards;
    for(auto establishment : establishments){
        if(establishment.second.first->getType()==type)
            cards.push_back(establishment.second.first);
    }
    return cards;
}
