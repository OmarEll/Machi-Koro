//
// Created by mabur on 19/12/2022.
//

#include "Player.hpp"

int Player::id_counter = 0;

Landmark* Player::hasLandmark(LandmarksNames name) const{
    auto it=hand.getLandmarks()[name];
    if(it!= nullptr && it->isConstructed())
        return it;
    else return nullptr;
}

Establishment* Player::hasEstablishment(EstablishmentsNames name)const {
    //Establishment* hasEst= nullptr;
    for(auto it :hand.getEstablishments() ){
        if(it.first == name) return it.second.top();
    }
    return nullptr;

}

Establishment* Player::hasEstablishment(string name)const {
    EnumParser<EstablishmentsNames> fieldTypeParser;
    EstablishmentsNames val = fieldTypeParser.ParseSomeEnum(name);
    return hasEstablishment(val);
}
