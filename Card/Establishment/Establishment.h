#include "../Card.hpp"
#include <vector>
class Card;

/* Classe non abstract */
class Establishment : public Card
{
protected:
    Colors color;
    vector<int> activationNumbers;
    OriginsOfCoins originOfCoinsEarned;
    int numberOfCoinsEarned;
public:
    Establishment(string name, string desc, Colors col, int cos, Expansions exp, Types typ, vector<int> actNum, OriginsOfCoins ori, int num)
        :Card(name,desc,cos,exp,typ),color(col),activationNumbers(actNum),originOfCoinsEarned(ori),numberOfCoinsEarned(num){}
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
    bool activate(int DiceRolled);
    void launchEffect(Game&,Player&) override;
    int numberGainWithType(Player* owner, vector<Types> t) const;
    bool hasHarbor();

};


/* Définition des establishment violets de la version standard */
class Stadium : public Establishment {
public:
    Stadium(): Establishment("Stadium","Receive 2 coins from each of your fellow players.",PURPLE, 6,Standard, tower,{6},OtherPlayers,2){}
    void launchEffect(Game& g,Player& currentPlayer) final;
};

class TvStation : public Establishment {
public:
    TvStation(): Establishment("TV Station","Choose one player who has to give you 5 coins.",PURPLE, 6,Standard, tower,{6},OtherPlayers,5){}
    void launchEffect(Game& g,Player& currentPlayer) final;
};

class Office : public Establishment {
public:
    Office(): Establishment("Office","Exchange a card with another player. No tower type establishment.",PURPLE, 8,Standard, tower,{6},OtherPlayers,0){}
    void launchEffect(Game& g,Player& currentPlayer) final;
};

/* Definition des establishments avec un effet de type "For each of your 'type' establishments, gain x coins"*/
//Standard
class CheeseFactory : public Establishment {
public:
    CheeseFactory(): Establishment("Cheese Factory","Receive 3 coins from the bank for each of your 'cow' type establishments.",GREEN, 5,Standard, factory,{7},Bank,3){}
    void launchEffect(Game& g,Player& currentPlayer) final;
};

class FurnitureFactory : public Establishment {
public:
    FurnitureFactory(): Establishment("Furniture Factory","Receive 3 coins from the bank for each of your 'wheel' type establishments.",GREEN, 3,Standard, factory,{8},Bank,3){}
    void launchEffect(Game& g,Player& currentPlayer) final;
};

class ProduceMarket : public Establishment {
public:
    ProduceMarket(): Establishment("Produce Market","Receive 2 coins from the bank for each of your 'wheat' type establishments.",GREEN, 2,Standard, apple,{11,12},Bank,2){}
    void launchEffect(Game& g,Player& currentPlayer) final;
};

//Harbor
class FoodWarehouse : public Establishment {
public:
    FoodWarehouse(): Establishment("Food Warehouse","Get 2 coins from the bank for each 'coffee' type establishment that you own, on your turn only.",GREEN, 2,Harbor, factory,{12,13},Bank,2){}
    void launchEffect(Game& g,Player& currentPlayer) final;
};

/* Definition des establishments avec un effet de type "If you have a Harbor, gain x coins"*/
class MackerelBoat : public Establishment {
public:
    MackerelBoat(): Establishment("Mackerel Boat","If you have a Harbor, get 3 coins from the bank on anyone's turn.",BLUE, 2,Harbor, boat,{8},Bank,3){}
    void launchEffect(Game& g,Player& currentPlayer) final;
};

class SushiBar : public Establishment {
public:
    SushiBar(): Establishment("Sushi Bar","If you have a Harbor, get 3 coins from the player who rolled the dice.",RED, 4,Harbor, coffee,{1},PlayerRolledDice,3){}
    void launchEffect(Game& g,Player& currentPlayer) final;
};


/* Définition des cartes violettes harbor */
class Publisher : public Establishment {
public:
    Publisher(): Establishment("Publisher","Take 1 coins from each opponent for each 'coffee' and 'bread' type establishment they own, on your turn only.",PURPLE, 5,Harbor, tower,{7},OtherPlayers,1){}
    void launchEffect(Game& g,Player& currentPlayer) final;
};
