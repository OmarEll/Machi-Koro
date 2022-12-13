//
// Created by Omar Elloumi on 04/12/2022.
//

#include "Bank.hpp"


Bank::Bank(size_t nbPlayers, int defaultValueWallet,int b):balance(b){
        for(auto i=0;i<nbPlayers;i++){
            wallets.push_back(new Wallet(defaultValueWallet));
        }
};

int Bank::deposit(size_t idPlayer,int amount){
    int playerBalance= wallets[idPlayer]->getBalance();
    if(balance>=amount){
        wallets[idPlayer]->addCoins(-amount);
        balance+=amount;
        return amount;
    }
    else{
        wallets[idPlayer]->addCoins(-playerBalance);
        balance+=playerBalance;
        return playerBalance;
    }
}
void Bank::withdraw(size_t idPlayer,int amount){
    wallets[idPlayer]->addCoins(amount);
}

void Bank::playerPaysPlayer(size_t idPlayer1,size_t idPlayer2,int amount){
    int amountToWithdraw=deposit(idPlayer1,amount);
    withdraw(idPlayer2,amountToWithdraw);
}

Bank::~Bank(){
    for(auto elt: wallets){
        delete elt;
    }
}
void Bank::freeInstance(){
    delete uniqueBank;
    uniqueBank= nullptr;
}