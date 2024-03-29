#pragma once

#include "../Card.hpp"
//#include "../Game/Game.h"
#include <vector>
//#include "Enums.hpp"


class Game;

/* Classe non abstract */
class Establishment : public Card
{
protected:
    Colors color;
    vector<int> activationNumbers;
    OriginsOfCoins originOfCoinsEarned;
    int numberOfCoinsEarned;
    bool underRenovation=false;

public:
    Establishment(string name, string desc, Colors col, int cos, Expansions exp, Types typ, vector<int> actNum, OriginsOfCoins ori, int num)
            :Card(name,desc,cos,exp,typ),color(col),activationNumbers(actNum),originOfCoinsEarned(ori),numberOfCoinsEarned(num){}
    Establishment (): Card(){};
    ~Establishment() = default;
    /* GETTERS & SETTERS */
    Types getType(){ return type ;}
    vector<int> getActivationNumbers() { return activationNumbers; }
    OriginsOfCoins getOrigin() const { return originOfCoinsEarned; }
    int getEarnedCoins() const{ return numberOfCoinsEarned; }
    virtual Colors getColor(){ return color; }
    bool getRenovation(){return underRenovation;}
    EstablishmentsNames getCardName_Enum(){
        EnumParser<EstablishmentsNames> fieldTypeParser;
        EstablishmentsNames val = fieldTypeParser.ParseSomeEnum(cardName);
        return val ;
    }
    void setNumberOfCoinsEarned(int num) {numberOfCoinsEarned = num;}
    void setOriginOfCoinsEarned(OriginsOfCoins name){ originOfCoinsEarned = name; }
    void setRenovation(bool r){ underRenovation=r;}

    /* REST */
    bool activate(int);
    virtual void launchEffect(Game&,Player&);
    int gainWithType() override{return 0;}
    int numberGainWithType(Player&, vector<Types>) const;
    bool hasHarbor();
    int numberOfLandmarks(Player*);
    int numberOfLandmarks(Player&);
    virtual Establishment* Clone ();
};


/* Définition des establishment violets de la version standard */
class Stadium : public Establishment {
public:
    Stadium(): Establishment("Stadium","Receive 2 coins from each of your fellow players.",PURPLE, 6,Standard, tower,{6},OtherPlayers,2){}
    ~Stadium() = default;
    virtual void launchEffect(Game& g,Player& currentPlayer) final;
    Stadium* Clone()override;
};

class TvStation : public Establishment {
public:
    TvStation(): Establishment("Tv Station","Choose one player who has to give you 5 coins.",PURPLE, 6,Standard, tower,{6},OtherPlayers,5){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    TvStation* Clone()override;
};

class Office : public Establishment {
public:
    Office(): Establishment("Office","Exchange a card with another player. No tower type establishment.",PURPLE, 8,Standard, tower,{6},OtherPlayers,0){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    Office* Clone() override;
};

/* Definition des establishments avec un effet de type "For each of your 'type' establishments, gain x coins"*/
//Standard
class CheeseFactory : public Establishment {
public:
    CheeseFactory(): Establishment("Cheese Factory","Receive 3 coins from the bank for each of your 'cow' type establishments.",GREEN, 5,Standard, factory,{7},BankOrigin,3){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    CheeseFactory* Clone() override;
};

class FurnitureFactory : public Establishment {
public:
    FurnitureFactory(): Establishment("Furniture Factory","Receive 3 coins from the bank for each of your 'wheel' type establishments.",GREEN, 3,Standard, factory,{8},BankOrigin,3){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    FurnitureFactory* Clone() override;
};

class ProduceMarket : public Establishment {
public:
    ProduceMarket(): Establishment("Produce Market","Receive 2 coins from the bank for each of your 'wheat' type establishments.",GREEN, 2,Standard, apple,{11,12},BankOrigin,2){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    ProduceMarket* Clone() override;
};

//Harbor
class FoodWarehouse : public Establishment {
public:
    FoodWarehouse(): Establishment("Food Warehouse","Get 2 coins from the bank for each 'coffee' type establishment that you own, on your turn only.",GREEN, 2,Harbor, factory,{12,13},BankOrigin,2){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    FoodWarehouse* Clone() override;
};

class FlowerShop : public Establishment {
public:
    FlowerShop(): Establishment("Flower Shop","Get 1 coin from the bank for Flower Garden you own, on your turn only.",GREEN, 1,Harbor, bread,{6},BankOrigin,1){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    FlowerShop* Clone() override;
};

/* Definition des establishments avec un effet de type "If you have a Harbor, gain x coins"*/
class MackerelBoat : public Establishment {
public:
    MackerelBoat(): Establishment("Mackerel Boat","If you have a Harbor, get 3 coins from the bank on anyone's turn.",BLUE, 2,Harbor, boat,{8},BankOrigin,3){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    MackerelBoat* Clone() override;
};

class SushiBar : public Establishment {
public:
    SushiBar(): Establishment("Sushi Bar","If you have a Harbor, get 3 coins from the player who rolled the dice.",RED, 4,Harbor, coffee,{1},PlayerRolledDice,3){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    SushiBar* Clone () override;
};

class TunaBoat : public Establishment {
public:
    TunaBoat(): Establishment("Tuna Boat","On anyone's turn: The current player rolls 2 dice. If you have a harbor you get as many coins as the dice total.",BLUE, 5,Harbor, boat,{12, 14},BankOrigin,0){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    TunaBoat* Clone() override;
};


/* Définition des cartes violettes harbor */
class Publisher : public Establishment {
public:
    Publisher(): Establishment("Publisher","Take 1 coins from each opponent for each 'coffee' and 'bread' type establishment they own, on your turn only.",PURPLE, 5,Harbor, tower,{7},OtherPlayers,1){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    Publisher* Clone() override;
};

class TaxOffice : public Establishment {
public:
    TaxOffice(): Establishment("Tax Office","From each opponent with 10 or more coins: take half their coins, rounded down. This only applies in your turn.",PURPLE, 4,Harbor, tower,{8,9},OtherPlayers,0){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    TaxOffice* Clone() override;
};

/* Définition des cartes violettes Green Valley */

class Park : public Establishment { //Arboretum dans la version francaise
public:
    Park(): Establishment("Park","Redistribute all players' coins evenly among all players, on your turn only. If there is an uneven amount of coins, take coins from the bank to make up the difference.",PURPLE, 3,GreenValley, tower,{11,13},OtherPlayers,0){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    Park* Clone() override;
};

class RenovationCompany : public Establishment {
public:
    RenovationCompany(): Establishment("Renovation Company","Choose a non-tower type building. All buildings owned by any player of that type are closed for renovations. Get 1 coin from each player for each of their buildings closed for renovation, on your turn only.",PURPLE, 4, GreenValley, tower,{8},OtherPlayers,1){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    RenovationCompany* Clone() override;
};

class TechStartup : public Establishment {
private :
    int investment = 0;
public:
    TechStartup(): Establishment("Tech Startup","At the end of each of your turns, you may place 1 coin on this card. The total placed here is your investment. When activated, get an amount equal to your investment from all player, on your turn only.",PURPLE, 1,GreenValley, tower,{10},OtherPlayers,0){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    void oneCoinInvestment(){ numberOfCoinsEarned ++; }
    TechStartup* Clone() override;

};

class InternationalExhibitHall : public Establishment {
public:
    InternationalExhibitHall(): Establishment("International Exhibit Hall","You may choose to activate another of your non tower type establishments in place of this one, on your turn only. If you do, return this card to the market.",PURPLE, 7,GreenValley, tower,{10},OtherPlayers,0){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    InternationalExhibitHall* Clone()override;
};

/* Définition des cartes spéciales GREEN VALLEY */

class CornField : public Establishment {
public:
    CornField(): Establishment("Corn Field","If you have less than 2 landmarks built, get 1 coin from the bank",BLUE, 2,GreenValley, wheat,{3,4},BankOrigin,1){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    CornField* Clone() override;
};

class GeneralStore: public Establishment {
public:
    GeneralStore(): Establishment("General Store","If you have less than 2 constructed landmarks, get 2 coins from the bank, on your turn only",GREEN, 0,GreenValley, bread,{2},BankOrigin,2){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    GeneralStore* Clone() override;
};

class MembersOnlyClub: public Establishment {
public:
    MembersOnlyClub(): Establishment("Members Only Club","If the player who rolled this number has 3 or more constructed landmarks, get all of their coins",RED, 4,GreenValley, coffee,{12, 14},PlayerRolledDice,0){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    MembersOnlyClub* Clone() override;
};

class FrenchRestaurant: public Establishment {
public:
    FrenchRestaurant(): Establishment("French Restaurant","If the player who rolled this number has 2 or more constructed landmarks, get 5 coins from the player who rolled the dice",RED, 3,GreenValley, coffee,{5},PlayerRolledDice,5){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    FrenchRestaurant* Clone()override;
};

class SodaBottlingPlant: public Establishment {
public:
    SodaBottlingPlant(): Establishment("Soda Bottling Plant","Get 1 coin from the bank for each coffee type establishments owned by all players (on your turn only)",GREEN, 5,GreenValley, factory,{11},OtherPlayers,1){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    SodaBottlingPlant* Clone() override;
};

class DemolitionCompany: public Establishment {
public:
    DemolitionCompany(): Establishment("Demolition Company","Demolish 1 of your built landmarks (flip it back over). When you do, get 8 coins from the bank (your turn only)",GREEN, 2,GreenValley, suitcase,{4},BankOrigin,8){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    DemolitionCompany* Clone() override;
};

class MovingCompany: public Establishment {
public:
    MovingCompany(): Establishment("Moving Company","You must give a non-tower type building that you own to another player. When you do so, get 4 coins from the bank, on your turn only",GREEN, 2,GreenValley, suitcase,{9,10},BankOrigin,4){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    MovingCompany* Clone() override;
};

class LoanOffice: public Establishment { //Fait (en vrai il y a pas besoin de faire cette classe mais comme les valeurs sont négative elle est faites au cas ou il y est un pb a gérer
public:
    LoanOffice(): Establishment("Loan Office","When you construct this building, get 5 coins from the bank. When this building is activated, pay 2 coins to the bank, on your turn only.",GREEN, -5,GreenValley, suitcase,{5,6},BankOrigin,-2){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    LoanOffice* Clone() override;
};

class Winery: public Establishment {
public:
    Winery(): Establishment("Winery","Get 6 coins for each vineyard you own, on your turn only. Then, close this building for renovation.",GREEN, 3,GreenValley, factory,{9},BankOrigin,6){}
    void launchEffect(Game& g,Player& currentPlayer) final;
    Winery* Clone() override;

};

/* Carte classique standard */

class WheatField: public Establishment {
public:
    WheatField(): Establishment("Wheat Field","Receive 1 coin from the bank",BLUE, 1,Standard, wheat,{1},BankOrigin,1){}
};

class Ranch: public Establishment {
public:
    Ranch(): Establishment("Livestock Farm","Receive 1 coin from the bank",BLUE, 1,Standard, cow,{2},BankOrigin,1){}
};

class Bakery: public Establishment {
public:
    Bakery(): Establishment("Bakery","Receive 1 coin from the bank",GREEN, 1,Standard, bread,{2,3},BankOrigin,1){}
};

class Cafe: public Establishment {
public:
    Cafe(): Establishment("Cafe","Receive 1 coin from the player who rolled a '3'.",RED, 2,Standard, coffee,{3},PlayerRolledDice,1){}
};

class ConvenienceStore: public Establishment {
public:
    ConvenienceStore(): Establishment("Convenience Store","Receive 3 coins from the bank.",GREEN, 2,Standard, bread,{4},BankOrigin,3){}
};

class Forest: public Establishment {
public:
    Forest(): Establishment("Forest","Receive 1 coin from the bank.",BLUE, 3,Standard, wheel,{5},BankOrigin,1){}
};

class Mine: public Establishment {
public:
    Mine(): Establishment("Mine","Receive 5 coins from the bank.",BLUE, 6,Standard, wheel,{9},BankOrigin,5){}
};

class Restaurant: public Establishment {
public:
    Restaurant(): Establishment("Restaurant","Receive 2 coins from the player who rolled a '9' or a '10'.",RED, 3,Standard, coffee,{9,10},PlayerRolledDice,2){}
};

class AppleOrchard: public Establishment {
public:
    AppleOrchard(): Establishment("Apple Orchard","Receive 3 coins from the bank.",BLUE, 3,Standard, wheat,{10},BankOrigin,3){}
};

/* Carte classique Harbor */

class FlowerGarden: public Establishment {
public:
    FlowerGarden(): Establishment("Flower Garden","Receive 1 coin from the bank.",BLUE, 2,Standard, wheat,{4},BankOrigin,1){}
};

class PizzaJoint: public Establishment {
public:
    PizzaJoint(): Establishment("Pizza Joint","Receive 1 coin from the player who rolled the dice.",RED, 1,Harbor, coffee,{7},PlayerRolledDice,1){}
};

class HamburgerStand: public Establishment {
public:
    HamburgerStand(): Establishment("Hamburger Stand","Receive 1 coin from the player who rolled the dice.",RED, 1,Harbor, coffee,{8},PlayerRolledDice,1){}
};

/* Carte classique Green Valley*/
class Vineyard: public Establishment {
public:
    Vineyard(): Establishment("Vineyard","Receive 3 coins from the bank.",BLUE, 3,Harbor, wheat,{7},BankOrigin,3){}
};