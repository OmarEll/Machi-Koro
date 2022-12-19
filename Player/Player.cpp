//
// Created by mabur on 19/12/2022.
//

#include "Landmark.h"

Landmark *Player::hasLandmark(LandmarksNames name) const {
    auto it=hand.getLandmarks().find(name);
    if(it!=hand.getLandmarks().end())
        return (*it).second;
    else return nullptr;
}

Establishment *Player::hasEstablishment(EstablishmentsNames name) const {
    auto it=hand.getEstablishments().find(name);
    return ((it!=hand.getEstablishments().end())? (*it).second.top() : nullptr);
}

Establishment *Player::hasEstablishment(string name) const {
    EnumParser<EstablishmentsNames> fieldTypeParser;
    EstablishmentsNames val = fieldTypeParser.ParseSomeEnum(name);
    return hasEstablishment(val);
}
