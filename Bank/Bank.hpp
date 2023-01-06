#pragma once

#include <vector>
#include "Wallet.hpp"
#include "Player.hpp"

using namespace std;

//class Wallet;

class Bank{
private:
    int balance;
    static Bank* uniqueBank;
    vector<Wallet*> wallets;
    Bank(vector<Player*> , int defaultValueWallet,int b = 99999999);
public:
    ~Bank();
    static Bank* getInstance(vector<Player*>, int def = 2);
    static void freeInstance();
    int deposit(size_t idPlayer,int amount);
    void withdraw(size_t idPlayer,int amount);

    int getBalance(size_t id) const { return wallets[id]->getBalance(); }
    void setBalance(size_t id, int num) { wallets[id]->setBalance(num);}
    void playerPaysPlayer(size_t idPlayer1,size_t idPlayer2,int amount);
    friend class Game;
};