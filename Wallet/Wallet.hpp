#define defaultValue 3

class Wallet
{
private:
    unsigned int solde;
public:
    Wallet():solde(defaultValue){};
    unsigned int getSolde(){ return solde; };
    bool pay(Player& player,unsigned int d);
};
