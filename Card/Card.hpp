#include "../UTILS/Enums.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.h"
#include <string>
#include <vector>

using namespace std;

class Player;
class Game;

class Card
{
    protected:
        string cardName;
        string description;
        Player* owner = nullptr;
        int cost;
        Expansions expansion;
        Types type;
    public:
        Card(string name, string desc, int cos, Expansions exp, Types typ,)
            :cardName(name),description(desc),cost(cos),expansion(exp), type(typ){}
        virtual ~Card()=default; //destructeur en virtual parcque Card est abstraite
        /* GETTERS & SETTERS */
        string getCardName(){ return cardName;}
        string getDescription(){ return description;}
        Player* getOwner() const {return owner;};
        int getCost() { return cost; }
        Expansions getExpansion() { return expansion;}

        void setOwner(Player* o) {owner = o;} //a revoir

        /* REST */
        bool sameCard(Card); //a revoir ce qui est mis en paramètre
        virtual int gainWithType();
        virtual void launchEffect(Game&,Player& currentPlayer);

};





/* A revoir (est-ce necessaire de déclarer les cartes classiques ?)
// Déclaration des classes de cartes bleu establishment individuelles 
class WheatField : public Blue{
    public:
        WheatField();
        launchEffet(Game);
};


//Déclaration des cartes violettes de la version standard (remarque : il y a 3 cartes violettes et un joueur peut posséder les trois mais pas en avoir une en plusieurs exemplaire)
class Stadium : public Purple {
    public:
    void launchEffect(Game g, Establishment e); //méthode redefinie pour permettre de recevoir des coins de la part de l'ensemble des adversaires
}

class TvStation : public Purple {
    public:
    void launchEffect(Game g, Establishment e); //méthode redefinie pour permettre de choisir l'adversaire qui donne les coins au propriétaire de la carte (automatique si 2 joueurs)
}

class Office : public Purple { //unique establishement standard qui fait autre chose que gagner des coins
    public:
    void launchEffect(Game g, Establishment e);
    //void tradeCards(); //echange une carte avec un autre joueur sauf de type tower (ie.les cartes violettes)
};

//Déclaration des cartes spécifiques de la version harbor (a voir avec doc word, il y a surement des methodes general a faire)

class MackerelBoat : public Blue {
public:
    void launchEffect(Game g, Establishment e);
    //If you have a Harbor, get 3 coins from the bank on anyone's turn.
}

class TunaBoat : public Blue {
public:
    void launchEffect(Game g, Establishment e);
    //On anyone's Turn: The current player rolls 2 dice. If you have a harbor you get as many coins as the dice total.
}


*/
