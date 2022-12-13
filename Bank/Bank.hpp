#ifndef MACHIKORO_FICHIER_BANK_H
#define MACHIKORO_FICHIER_BANK_H

#include <vector>
#include "Wallet.hpp"
using namespace std;

class Bank{
private:
    int balance;
    static Bank* uniqueBank;
    vector<Wallet*> wallets;
public:
    Bank(size_t nbPlayers, int defaultValueWallet,int b);
    ~Bank();
    static Bank& getInstance(){ return *uniqueBank; }
    static Bank& makeIfNotInstance(size_t nbPlayersint,int defaultValueWallet,int b);
    static void freeInstance();
    int deposit(size_t idPlayer,int amount);
    void withdraw(size_t idPlayer,int amount);
    int getBalance(int id){ return wallets[id]->getBalance(); }
    void playerPaysPlayer(size_t idPlayer1,size_t idPlayer2,int amount);
};

#endif