#include "Card.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.h"

//definition des différents méthodes activate en fonction de la couleur des cartes

void Establishment::activate(int DiceRolled){//méthode réutilisée pour les différentes cartes
            activated = false;
		    for(int i=0; i<activationNumbers.size(); i++){
 			    if(activationNumbers[i] == diceRolled) activated = true;
            }
        }

void Red::activate(int DiceRolled){
            Establishment::activate(int DiceRolled);
            if ((activePlayer != owner) && activated==true) activated=true;
            else activated = false;
        };

void Green::activate(int DiceRolled) { 
            Establishment::activate(int DiceRolled);
            if ((activePlayer == owner) && activated==true) activated=true;
            else activated = false;
        }

void Purple::activate(int DiceRolled) { 
            Establishment::activate(int DiceRolled);
            if ((activePlayer == owner) && activated==true) activated=true;
            else activated = false;
        }



//definition des effets

void Establishment::launchEffect(Game g, Establishment e){ //ne gère pas les cartes violette, a gerer dans des classes filles spécifiques 

    if (e.getOriginOfCoinsEarned() == "Bank" && e.getOwner()!=nullptr) 
        e.getOwner().getWallet().addCoins(e.getNumberOfcoinsEarned());
    }

    if (e.getOriginOfCoinsEarned() == "PlayerWhoRolledDice" && e.getOwner()!=nullptr){ //on va prendre des coins du joueur qui a lancé le dé et le donner à celui qui possède cette carte
        if (e.getActivePlayer().getWallet().getBalance() >= e.getNumberOfcoinsEarned()){ //le joueur qui doit payer a assez de coins pour payer
            e.getActivePlayer().getWallet().removeCoins(e.getNumberOfcoinsEarned());
            e.getOwner().getWallet().addCoins(e.getNumberOfcoinsEarned());
        }
        else {                                                                       //le joueur qui doit payer n'a pas assez de coins pour payer donc donne ce qu'il a
            int num = e.getActivePlayer().getWallet().getBalance();
            e.getOwner().getWallet().addCoins(num);
            e.getActivePlayer().getWallet().removeCoins(num);
        }
         
    }


}

//redefinition des effets des cartes violettes 

void Stadium::launchEffect(Game g, Establishment e){ //méthode redefinie pour permettre de recevoir des coins de la part de l'ensemble des adversaires
    //comment est-ce qu'on parcours la liste des joueurs ? 
    if(g.getPlayers().size() == 2){ //s'il n'y a que deux joueurs les coins sont payés par l'adversaire (ie. celui qui n'est pas le propriétaire de la carte)
        
    }
}

void TvStation::launchEffect(Game g, Establishment e){ //méthode redefinie pour permettre de choisir l'adversaire qui donne les coins au propriétaire de la carte (automatique si 2 joueurs)
    if (g. )

}

void TvStation::launchEffect(Game g, Establishment e){ //echange une carte avec un autre joueur sauf de type tower (ie.les cartes violettes)

}


/*

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
<<<<<<< Updated upstream

*/
=======
>>>>>>> Stashed changes
