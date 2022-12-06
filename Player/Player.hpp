#ifndef MACHIKORO_FICHIER_PLAYER_H
#define MACHIKORO_FICHIER_PLAYER_H

#include <string>
#include <iostream>
#include "../Hand/Hand.hpp"

class Hand;

using namespace std;

class Player{
    static int id_counter;
    private:
        int idPlayer;
        string name;
        Hand hand;
    public:
        Player(string nm,Expansions myExpansion):idPlayer(++id_counter),name(nm),hand(myExpansion){};
        int getId() const { return idPlayer; };
        string getName() const { return name; };
        Hand getHand() const { return hand;};
        Wallet getWallet() const {return wallet; }
        bool hasLandmark(LandmarksNames name) const{return hand.getLandmarks().find(name)!=hand.getLandmarks().end();}
        virtual ~Player();
};

#endif //MACHIKORO_FICHIER_PLAYER_H
