#ifndef MACHIKORO_FICHIER_CARD_H
#define MACHIKORO_FICHIER_CARD_H

#include "UTILS/Enums.hpp"
#include "Player/Player.hpp"
#include <string>
#include <vector>

using namespace std;

class Card
{
    protected:
        int id;
        string cardName;
        string description;
        Colors color; 
        Player& owner;
        Player& activePlayer; //a chercher d'ailleurs avec un getCurrentPlayer 
        int cost;
        Expansions expansion;
    public:
        Card(int i, string n, string desc, Colors col, int cos, Expansions exp)
            :id(i),cardName(n),description(desc),color(col),owner(nullptr),activePlayer(nullptr),cost(cos),expansion(exp); //surement a revoir
        ~Card(); //est-ce qu'il y a besoin de redefinir le destructeur ? Il n'y a rien d'alloué dynamiquement dans Card
        bool sameCard(Card); //a revoir ce qui est mis en paramètre 
        void setOwner(Player& o) {owner = o;}; //a revoir
        Player getOwner(Player&) const {return owner;}; //a revoir
        void setActivePlayer(Player& a) {activePlayer = a;}; //a revoir
        Player getActivePlayer(Player&) const {return activePlayer}; //a revoir

};

class Establishment : public Card
{
    protected:
        bool activated;
        Types type; 
        vector<int> activationNumbers;
        string originOfCoinsEarned; //a revoir
        int numberOfCoinsEarned;
    public:
        Establishment(bool act = false, Types typ = nullptr, vector<int> actNum.push_back(0) , string ori= nullptr, int num= 0)
            :activated(act), type(typ), activationNumbers(actNum), originOfCoinsEarned(ori), numberOfCoinsEarned(num);
        void activate(int DiceRolled); //méthode réutilisée pour les différentes cartes
        void deactivate{ activated=false; }
        virtual void launchEffect(Game);
        void setNumberOfCoinsEarned(int num) {numberOfCoinsEarned = num;}
        void getNumberOfCoinsEarned() {return numberOfCoinsEarned;}
        void setOriginOfCoinsEarned(string name){ originOfCoinsEarned = name; }
        void getOriginOfCoinsEarned(){ return originOfCoinsEarned; }
        void launchEffect(Game g, Establishment e);
};

//Déclaration des classes correspondant aux couleurs des cartes establishment
class Red : public Establishment{ //ne peut être activé que pendant le tour des adversaires
    public:
        Red(Colors col= "RED", string ori= "PlayerWhoRolledDice"):color(col), originOfCoinsEarned(ori);
        void activate(int DiceRolled);
};

class Blue : public Establishment{ //peut-être activé pendant le tour de n’importe quel joueurs
    public:
        Blue(Colors col= "BLUE", string ori= "Bank"):color(col), originOfCoinsEarned(ori);
        void activate(int DiceRolled); //méthode inchangé
};

class Green : public Establishment{ //peut être activé uniquement pendant le tour du propriétaire de la carte 
    public:
        Green(Colors col= "GREEN", string ori= "Bank"):color(col), originOfCoinsEarned(ori);
        void activate(int DiceRolled);
};

class Purple : public Establishment{ //peut être activé uniquement pendant le tour du propriétaire de la carte 
    public:
        Purple(Card::Colors col):color(col = "PURPLE");
        void activate(int DiceRolled);
};

/* A revoir (est-ce necessaire de déclarer les cartes classiques ?)
// Déclaration des classes de cartes bleu establishment individuelles 
class WheatField : public Blue{
    public:
        WheatField();
        launchEffet(Game);
};
*/

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

class Landmarks : public Card {
    protected:
        bool constructed;
    public:
        virtual void lauchEffect(Game);
        void isConstructed() const {constructed = true};
};

#endif //MACHIKORO_FICHIER_CARD_H