#pragma once

#include "../UTILS/Enums.hpp"
/*#include "../Player/Player.hpp"
#include "../Game/Game.h"*/
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
        Card(string name, string desc, int cos, Expansions exp, Types typ)
            :cardName(name),description(desc),cost(cos),expansion(exp), type(typ){}
        Card(){};
        virtual ~Card()=default; //destructeur en virtual parcque Card est abstraite
        /* GETTERS & SETTERS */
        string getCardName(){ return cardName;}
        string getDescription(){ return description;}
        Player* getOwner() const {return owner;};
        int getCost() { return cost; }
        Expansions getExpansion() { return expansion;}
        void setOwner(Player* o) {owner = o;} //a revoir
        /* REST */
        virtual int gainWithType() =0;
        virtual void launchEffect(Game&,Player&) =0;

};
