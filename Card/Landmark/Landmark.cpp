//
// Created by Omar Elloumi on 08/12/2022.
//

#include "Landmark.h"

Landmark *Landmark::Clone() {
    Landmark* res = new Landmark();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->constructed = this->isConstructed();
    return res;
}
