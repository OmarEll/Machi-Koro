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
    Landmark* hasLandmark(LandmarksNames name) const;
    Establishment* hasEstablishment(EstablishmentsNames name) const;
    Establishment* hasEstablishment(string name) const;
    virtual ~Player();
};

