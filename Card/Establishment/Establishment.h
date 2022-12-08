#include "../Card.hpp"
class Card;

class Establishment : public Card
{
protected:
    Types type;
    vector<int> activationNumbers;
    OriginsOfCoins originOfCoinsEarned;
    int numberOfCoinsEarned;
public:
    Establishment(string name, string desc, Colors col, int cos, Expansions exp, Types typ, vector<int> actNum, OriginsOfCoins ori, int num): Card(name,desc,col,cos,exp),type(typ),activationNumbers(actNum),originOfCoinsEarned(ori),numberOfCoinsEarned(num){}
    ~Establishment();
    /* GETTERS & SETTERS */
    Types getType(){ return type ;}
    vector<int> getActivationNumbers() { return activationNumbers; }
    OriginsOfCoins getOrigin(){ return originOfCoinsEarned; }
    int getEarnedCoins() const{ return numberOfCoinsEarned; }
    void setNumberOfCoinsEarned(int num) {numberOfCoinsEarned = num;}
    void setOriginOfCoinsEarned(OriginsOfCoins name){ originOfCoinsEarned = name; }

    /* REST */
    bool activate(int DiceRolled); //méthode réutilisée pour les différentes cartes
};

/**************************/
//Déclaration des classes correspondant aux couleurs des cartes establishment
class Red : public Establishment{ //ne peut être activé que pendant le tour des adversaires
public:
    Red(string name, string desc, int cos, Expansions exp,Types typ, vector<int> actNum, OriginsOfCoins ori, int num): Establishment(name,desc,RED,cos,exp,typ,actNum,PlayerRolledDice,num){}
    bool activate(int DiceRolled) override;
};

class Blue : public Establishment{ //peut-être activé pendant le tour de n’importe quel joueurs
public:
    Blue(string name, string desc, int cos, Expansions exp,Types typ, vector<int> actNum, int num): Establishment(name,desc,BLUE,cos,exp,typ,actNum,Bank,num){}
    bool activate(int DiceRolled) override; //méthode inchangé
};

class Green : public Establishment{ //peut être activé uniquement pendant le tour du propriétaire de la carte
public:
    Green(string name, string desc, int cos, Expansions exp,Types typ, vector<int> actNum, int num): Establishment(name,desc,GREEN,cos,exp,typ,actNum,Bank,num){}
    bool activate(int DiceRolled) override;
};

class Purple : public Establishment { //peut être activé uniquement pendant le tour du propriétaire de la carte
public:
    Purple(string name, string desc, int cos, Expansions exp,Types typ, vector<int> actNum, int num): Establishment(name,desc,PURPLE,cos,exp,typ,actNum,OtherPlayers,num){}
    bool activate(int DiceRolled) override;
};