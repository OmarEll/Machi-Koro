#pragma once

#include <string>
#include <iostream>
#include "Hand/Hand.hpp"



class Establishment;
class Landmark;
class Wallet;
class Hand;

using namespace std;

class Player{
protected:
    int idPlayer;
    string name;
    Hand hand;
public:
    static int id_counter;
    Player(const string& nm,Collection_standard& g):idPlayer(id_counter++),name(nm),hand(g){};

    /* GETTERS & SETTERS*/
    const int& getId() const { return idPlayer; };
    const string& getName() const { return name; };
    Hand* getHand() { return &hand;};

    /* OTHER */
    Landmark* hasLandmark (LandmarksNames) const;
    Establishment* hasEstablishment(EstablishmentsNames) const;
    Establishment* hasEstablishment(string) const ;

    /* virtual methods */
    virtual bool isAI()=0;
    virtual ~Player() = default;
};

