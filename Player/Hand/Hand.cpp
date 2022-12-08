//
// Created by Omar Elloumi on 04/12/2022.
//
#include "Hand.hpp"

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
void Hand::addEstablishment(Establishment* card){
    if(establishments.find(card)!=establishments.end())
        establishments[card]++;
    else{
        establishments.insert(pair<Establishment*,size_t>(card,1));
    }
}

void Hand::removeEstablishment(Establishment* card){
    if(establishments.find(card)!=establishments.end()){
        establishments[card]--;
        if(establishments[card]<=0){
            establishments.erase(card);
        }
    }
}
vector<Establishment*> Hand::getColorCards(Colors color){
    vector<Establishment*> cards;
    for(auto establishment : establishments){
        if((establishment.first)->getColor()==color)
            cards.push_back(establishment.first);
    }
    return cards;
}
vector<Establishment*> Hand::getTypeCards(Types type){
    vector<Establishment*> cards;
    for(auto establishment : establishments){
        if((establishment.first)->getType()==type)
            cards.push_back(establishment.first);
    }
    return cards;
}
