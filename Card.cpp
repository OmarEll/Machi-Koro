#include "Card.hpp"


//definition des différents méthodes activate en fonction de la couleur des cartes

void Establishment::activate(int DiceRolled){//méthode réutilisée pour les différentes cartes
            activated = false;
		    for(int i=0; i<activationNumbers.size(); i++){
 			    if(iActivationNumber[i] == diceRolled) bActivated = true;
            }
        }

void Red::activate(int DiceRolled){
            Establishment::activate(int DiceRolled);
            if ((ActivePlayer != owner) && activated==true) activated=true;
            else activated = false;
        };

void Green::activate(int DiceRolled) { 
            Establishment::activate(int DiceRolled);
            if ((ActivePlayer == owner) && activated==true) activated=true;
            else activated = false;
        }

void Purple::activate(int DiceRolled) { 
            Establishment::activate(int DiceRolled);
            if ((ActivePlayer == owner) && activated==true) activated=true;
            else activated = false;
        }


//definition des effets

void Establishment::launchEffect(Game g, Establishment e){ //ne gère pas les cartes violette, a gerer dans des classes filles spécifiques 

    if (e.getOriginOfCoinsEarned() == "Bank" && e.getOwner()!=nullptr) 
        e.getOwner().getWallet().addCoins(e.getNumberOfcoinsEarned());
    }

    if (e.getOriginOfCoinsEarned() == "PlayerWhoRolledDice" && e.getOwner()!=nullptr){ //on va prendre des ous du jeour qui à lancer le dé et le donner à celui qui possède cette carte
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