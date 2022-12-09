#include "../Card.hpp"
class Card;

/* Classe non abstract */
class Establishment : public Card
{
protected:
    Types type;
    Colors color;
    vector<int> activationNumbers;
    OriginsOfCoins originOfCoinsEarned;
    int numberOfCoinsEarned;
public:
    Establishment(string name, string desc, Colors col, int cos, Expansions exp, Types typ, vector<int> actNum, OriginsOfCoins ori, int num)
        :Card(name,desc,cos,exp),color(col),type(typ),activationNumbers(actNum),originOfCoinsEarned(ori),numberOfCoinsEarned(num){}
    ~Establishment();
    /* GETTERS & SETTERS */
    Types getType(){ return type ;}
    vector<int> getActivationNumbers() { return activationNumbers; }
    OriginsOfCoins getOrigin(){ return originOfCoinsEarned; }
    int getEarnedCoins() const{ return numberOfCoinsEarned; }
    Colors getColor(){ return color; }

    void setNumberOfCoinsEarned(int num) {numberOfCoinsEarned = num;}
    void setOriginOfCoinsEarned(OriginsOfCoins name){ originOfCoinsEarned = name; }

    /* REST */
    bool activate(int DiceRolled); //méthode réutilisée pour les différentes cartes
    void launchEffect(Game,Player&) override;
};


/* Définition des establishment violets de la version standard */
class Stadium : public Establishment {
public:
    Stadium(): Establishment("Stadium","Receive 2 coins from each of your fellow players.",PURPLE, 6,Standard, tower,6,OtherPlayers,2){}
    void Establishment::launchEffect(Game g,Player& currentPlayer) override;
};

class TvStation : public Establishment {
public:
    TvStation(): Establishment("TV Station","Choose one player who has to give you 5 coins.",PURPLE, 6,Standard, tower,6,OtherPlayers,5){}
    void Establishment::launchEffect(Game g,Player& currentPlayer) override;
};

class Office : public Establishment {
public:
    Office(): Establishment("Office","Exchange a card with another player. No tower type establishment.",PURPLE, 8,Standard, tower,6,OtherPlayers,0){}
    void Establishment::launchEffect(Game g,Player& currentPlayer) override;
};
