#pragma once

// we chose to have an int balance instead of unsigned int
// because maybe in future expantion player need to pay his debt
// so there's a possibility that player have a negative balance.:::

class Wallet
{
    
private:
    int balance;
    std::size_t id_player;
public:
    explicit Wallet(int defaultValue, std::size_t id):balance(defaultValue), id_player(id){};
    int getBalance(){ return balance; };
    void setBalance(int num) { balance = num; };
    void addCoins(int nbCoins) { balance +=nbCoins; };
    void removeCoins(int nbCoins) { balance -=nbCoins; };
};

