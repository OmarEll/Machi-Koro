#include <string> 
#include <iostream>
#include "../Hand/Hand.hpp"
using namespace std;

class Player{
    private:
        int idPlayer;
        static int id_counter;
        string name;
        Wallet wallet;
        Hand hand;
    public:
        Player(string nm):idPlayer(id_counter++),name(nm){};
        int getId() const { return idPlayer; };
        string getName() const { return name; };
        Hand getHand() const { return hand;};
        Wallet getWallet() const { return wallet;};
        ~Player();
};
