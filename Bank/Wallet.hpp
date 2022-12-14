#ifndef MACHIKORO_FICHIER_WALLET_H
#define MACHIKORO_FICHIER_WALLET_H


// we chose to have an int balance instead of unsigned int
// because maybe in future expantion player need to pay his debt
// so there's a possibility that player have a negative balance.:::

class Wallet
{
    
private:
    int balance;
public:
    explicit Wallet(int defaultValue):balance(defaultValue){};
    int getBalance(){ return balance; };
    void setBalance(int num) { balance = num; };
    void addCoins(int nbCoins) { balance +=nbCoins; };
    void removeCoins(int nbCoins) { balance -=nbCoins; };
};

#endif //MACHIKORO_FICHIER_WALLET_H
