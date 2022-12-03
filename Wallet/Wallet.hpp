#define defaultValue 3
#include "../Player/Player.hpp"
class Wallet
{
private:
    unsigned int solde;
public:
    Wallet():solde(defaultValue){};
    unsigned int getSolde(){ return solde; };
    void addCoins(int nbCoins) { solde = solde + nbCoins; };
    bool pay(Player& player,unsigned int d);
};
