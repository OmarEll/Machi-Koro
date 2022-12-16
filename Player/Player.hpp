#ifndef MACHIKORO_FICHIER_PLAYER_H
#define MACHIKORO_FICHIER_PLAYER_H

#include <string>
#include <iostream>
#include "../Player/Hand/Hand.hpp"
#include "../Bank/Bank.hpp"
#include "../Bank/Wallet.hpp"

class Hand;

using namespace std;

class Player{
private:
    int idPlayer;
    string name;
    Hand hand;
public:
    static int id_counter;
    Player(string nm,Expansions myExpansion):idPlayer(++id_counter),name(nm),hand(myExpansion){};
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
        if(it!=hand.getEstablishments().end())
            return (*it).second.first;
        else return nullptr;
    }
    Establishment* hasEstablishment(string name) const{
        EnumParser<EstablishmentsNames> fieldTypeParser;
        EstablishmentsNames val = fieldTypeParser.ParseSomeEnum(name);
        auto it=hand.getEstablishments().find(val);
        if(it!=hand.getEstablishments().end())
            return (*it).second.first;
        else return nullptr;
    }

    virtual ~Player();
};

#endif //MACHIKORO_FICHIER_PLAYER_H