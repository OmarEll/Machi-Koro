#ifndef MACHIKORO_FICHIER_PLAYER_H
#define MACHIKORO_FICHIER_PLAYER_H

#include <string>
#include <iostream>
#include "../Hand/Hand.hpp"
#include "Bank/Wallet.hpp"
using namespace std;

class Player{
    private:
        int idPlayer;
        static int id_counter;
        string name;
        Hand hand;
    public:
        Player(string nm):idPlayer(id_counter++),name(nm){};
        int getId() const { return idPlayer; };
        string getName() const { return name; };
        Hand getHand() const { return hand;};
        bool hasLandmark(LandmarksNames name) const;
        virtual ~Player();
};

#endif //MACHIKORO_FICHIER_PLAYER_H
