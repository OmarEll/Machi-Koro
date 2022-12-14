#pragma once
#include <vector>
#include "Wallet.hpp"
using namespace std;

class Bank{
private:
    int balance;
    static Bank* uniqueBank;
    vector<Wallet*> wallets;
    Bank(size_t nbPlayers, int defaultValueWallet,int b = 99999999);
public:
    ~Bank();
    static Bank& getInstance(int nbP = 2, int def = 2){
        if (!uniqueBank)
            uniqueBank = new Bank(nbP,def);
        return *uniqueBank; }
    static void freeInstance();
    int deposit(size_t idPlayer,int amount);
    void withdraw(size_t idPlayer,int amount);
    int getBalance(int id){ return wallets[id]->getBalance(); }
    void setBalance(int id, int num) { wallets[id]->setBalance(num);}
    void playerPaysPlayer(size_t idPlayer1,size_t idPlayer2,int amount);
};
