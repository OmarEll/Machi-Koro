#include "Establishment.h"
#include "../Player/Player.hpp"
#include "../Game/Game.h"
#include "../../UTILS/Enums.hpp"

bool Establishment::activate(int diceRolled){

    for(auto activationNumber : activationNumbers) {
        if (activationNumber == diceRolled)
            return true;
    }
    return false;
}


//definition de l'effet de base d'un etablissement (recevoir de l'ragent de la banque ou d'un joueur

void Establishment::launchEffect(Game g,Player& currentPlayer){ //ne gère pas les cartes violette, a gerer dans des classes filles spécifiques
    int id_Owner=getOwner()->getId();
    if (getOrigin() == Bank && Card::getOwner()!=nullptr)
        g.getBank().withdraw(id_Owner,getEarnedCoins());

    int id_current=currentPlayer.getId();
    int balance_current=g.getBank().getBalance(id_current);
    if ((getOrigin() == PlayerRolledDice) && getOwner()!=nullptr) { //on va prendre des coins du joueur qui a lancé le dé et le donner à celui qui possède cette carte
        if (balance_current >= getEarnedCoins()) { //le joueur qui doit payer a assez de coins pour payer
            g.getBank().playerPaysPlayer(id_current, id_Owner, getEarnedCoins());
        } else {                                    //le joueur qui doit payer n'a pas assez de coins pour payer donc il donne ce qu'il a
            g.getBank().playerPaysPlayer(id_current, id_Owner, balance_current);
        }
    }
}


//redefinition des effets des cartes violettes standard

void Stadium::launchEffect(Game g, Player& currentPlayer){ //méthode redefinie pour permettre de recevoir des coins de la part de l'ensemble des adversaires
    int id_Owner=getOwner()->getId();
    for (const auto& other_player : g.getPlayers()){
        int id_other = other_player.getId();
        if (id_Owner != id_other){
            int balance_other=g.getBank().getBalance(id_other);
            if ((getOrigin() == OtherPlayers) && getOwner()!=nullptr) { //on va prendre les coins des joueurs adverse et le donner à celui qui possède cette carte (qui est aussi le current_player)
                if (balance_other >= getEarnedCoins()) { //le joueur qui doit payer a assez de coins pour payer
                    g.getBank().playerPaysPlayer(id_other, id_Owner, getEarnedCoins());
                } else {                                    //le joueur qui doit payer n'a pas assez de coins pour payer donc il donne ce qu'il a
                    g.getBank().playerPaysPlayer(id_other, id_Owner, balance_other);
                }
            }
        }
    }
}

/*
void TvStation::launchEffect(Game g, Establishment e){ //méthode redefinie pour permettre de choisir l'adversaire qui donne les coins au propriétaire de la carte (automatique si 2 joueurs)
    if (g. )

}

void TvStation::launchEffect(Game g, Establishment e){ //echange une carte avec un autre joueur sauf de type tower (ie.les cartes violettes)

}

//redfinition des effets des cartes spécifiques harbor

void MackerelBoat::launchEffect(Game g, Establishment e){ //echange une carte avec un autre joueur sauf de type tower (ie.les cartes violettes)

}



WheatField::WheatField(int i, string n, string desc, int cos, Expansions exp, Types typ, Types typ, vector<int> actNum , string ori, int num)
            :id(i),cardName(n),description(desc),cost(cos),expansion(exp), type(typ), activationNumbers(actNum), originOfCoinsEarned(ori), numberOfCoinsEarned(num);{
                n = "Wheat Field";
                desc = "Receive 1 coin from the bank";
                cos = 1;
                exp = "Standard";
                typ = "wheat";
                actNum.push_back(1);
                ori = "Bank";
                num = 1;
            }

*/

