#ifndef MACHIKORO_FICHIER_CARD_H
#define MACHIKORO_FICHIER_CARD_H

#include "UTILS/Enums.hpp"
#include "Player/Player.hpp"
#include <string>

using namespace std;

class Card
{
    protected:
        int id;
        string cardName;
        string description;
        Colors color; 
        Player& owner;
        Player& activePlayer;
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
        list<int> activationNumbers;
        string originOfCoinsEarned; //a revoir
        int numberOfCoinsEarned;
    public:
        Establishment(bool act = false, Types typ = nullptr, /* voir comment on gere list*/ , string ori= nullptr, int num= 0)
            :activated(act), type(typ), /* voir comment on gere list*/, originOfCoinsEarned(ori), numberOfCoinsEarned(num);
        void activate(int DiceRolled){//méthode réutilisée pour les différentes cartes
            activated = false;
		    for(int i=0; i<activationNumbers.size(); i++){
 			    if(iActivationNumber[i] == diceRolled) bActivated = true;
            }
        }
        void deactivate{ activated=false; };
        virtual void launchEffect(Game);
        void setNumberOfCoinsEarned();
        void setOriginOfCoinsEarned();
};

//Déclaration des classes correspondant aux couleurs des cartes establishment
class Red : public Establishment{ //ne peut être activé que pendant le tour des adversaires
    public:
        Red(Card::Colors col):color(col = "RED");
        void activate(int DiceRolled){
            Establishment::activate(int DiceRolled);
            if ((ActivePlayer != owner) && activated=true) activated=true;
            else activated = false;

        };
};

class Blue : public Establishment{ //peut-être activé pendant le tour de n’importe quel joueurs
    public:
        Blue(Card::Colors col):color(col = "BLUE");
        void activate(int DiceRolled); //méthode inchangé
};

class Green : public Establishment{ //peut être activé uniquement pendant le tour du propriétaire de la carte 
    public:
        Green(Card::Colors col):color(col = "GREEN");
        void activate(int DiceRolled) { 
            Establishment::activate(int DiceRolled);
            if ((ActivePlayer == owner) && activated=true) activated=true;
            else activated = false;
        }
};

class Purple : public Establishment{ //peut être activé uniquement pendant le tour du propriétaire de la carte 
    public:
        Purple(Card::Colors col):color(col = "PURPLE");
        void activate(int DiceRolled) { 
            Establishment::activate(int DiceRolled);
            if ((ActivePlayer == owner) && activated=true) activated=true;
            else activated = false;
        }
};

// Déclaration des classes de cartes bleu establishment individuelles 
class WheatField : public Blue{
    public:
        WheatField();
        launchEffet(Game);
};


class BusinessCenter : public Purple { //unique establishement standard qui fait autre chose que gagner des coins
    public:
    void tradeCards();
};

class Landmarks : public Card {
    protected:
        bool constructed;
    public:
        virtual void lauchEffect(Game);
        void isConstructed() const {constructed = true};
};

#endif //MACHIKORO_FICHIER_CARD_H