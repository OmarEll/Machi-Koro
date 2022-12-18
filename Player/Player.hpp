#pragma once

#include <string>
#include <iostream>
#include "Hand/Hand.hpp"
#include "../Bank/Bank.hpp"
#include "../Bank/Wallet.hpp"

class Hand;
class Establishment;
class Landmark;

using namespace std;

class Player{
protected:
    int idPlayer;
    string name;
    Hand hand;
public:
    static int id_counter;

    Player(string nm,vector<Establishment*> a,vector<Landmark*> b):idPlayer(++id_counter),name(nm),hand(a,b){};
    int getId() const { return idPlayer; };
    string getName() const { return name; };
    Hand getHand() const { return hand;};
    Landmark* hasLandmark(LandmarksNames name) const{
        auto it=hand.getLandmarks().find(name);
        if(it!=hand.getLandmarks().end())
            return (*it).second;
        else return nullptr;
    }
    //
    Establishment* hasEstablishment(EstablishmentsNames name) const{
        auto it=hand.getEstablishments().find(name);
        return ((it!=hand.getEstablishments().end())? (*it).second.top() : nullptr);
    }
    Establishment* hasEstablishment(string name) const{
        EnumParser<EstablishmentsNames> fieldTypeParser;
        EstablishmentsNames val = fieldTypeParser.ParseSomeEnum(name);
        return hasEstablishment(val);
    }

    virtual ~Player();
};

