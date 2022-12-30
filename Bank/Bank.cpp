//
// Created by Omar Elloumi on 04/12/2022.
//

#include "Bank.hpp"
#include "Player.hpp"

Bank* Bank::uniqueBank = nullptr;

Bank::Bank(vector<Player*> player, int defaultValueWallet,int b):balance(b){
    auto init = player.begin();
        for(auto i=0;i<player.size();i++){
            wallets.push_back(new Wallet(defaultValueWallet,(*init)->getId()));
            init++;
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

Bank *Bank::getInstance(vector<Player*> g, int def) {
    if (!uniqueBank)
        uniqueBank = new Bank(g,def);
    return uniqueBank; }
