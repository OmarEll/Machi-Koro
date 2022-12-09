#include "Establishment.h"
#include "../Player/Player.hpp"
#include "../Game/Game.h"
#include "../../UTILS/Enums.hpp"
#include <string>

bool Establishment::activate(int diceRolled){

    for(auto activationNumber : activationNumbers) {
        if (activationNumber == diceRolled)
            return true;
    }
    return false;
}


//definition de l'effet de base d'un etablissement (recevoir de l'ragent de la banque ou d'un joueur

void Establishment::launchEffect(Game& g,Player& currentPlayer){ //ne gère pas les cartes violette, a gerer dans des classes filles spécifiques
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

void Stadium::launchEffect(Game& g, Player& currentPlayer){ //méthode redefinie pour permettre de recevoir des coins de la part de l'ensemble des adversaires
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

void TvStation::launchEffect(Game& g, Player& currentPlayer){ //méthode redefinie pour permettre de choisir l'adversaire qui donne les coins au propriétaire de la carte (automatique si 2 joueurs)
    string nameOfPayer;
    int id_payer = 0;
    int id_Owner=getOwner()->getId();
    while (id_payer==0){
        cout<<"Choissisez le joueur qui doit vous payer :\n";
        for (const auto& other_player : g.getPlayers()){
            cout<<other_player.getName()<<" "; //affiche la liste des joueurs
        }
        cout<<"\n";
        cin>>nameOfPayer;
        for (const auto& other_player : g.getPlayers()){
            if(nameOfPayer==other_player.getName()){
                id_payer = other_player.getId();
            }
        }
    }
    g.getBank().playerPaysPlayer(id_payer, id_Owner, getEarnedCoins());
}



void Office::launchEffect(Game& g, Player& currentPlayer){ //echange une carte avec un autre joueur sauf de type tower (ie.les cartes violettes)
    int id_Exchanger = 0;
    Card& CardExchanger;
    Card& CardOwner;
    string nameOfExchanger;
    string nameOfCardExchanger;
    string nameOfCardOwner;
    while (id_Exchanger == 0){
        cout<<"Entrez le nom du joueur avec qui vous voulez échanger une carte :\n";
        cin>>nameOfExchanger;
        for (const auto& other_player : g.getPlayers()){
            if(nameOfExchanger==other_player.getName()){
                id_Exchanger = other_player.getId();
            }
        }
    }


    cout<<"Entrez le nom de la carte que vous souhaitez récupérer (elle ne doit pas être de type tower) :\n";
    cin>>nameOfCardExchanger;
    cout<<"Entrez le nom de la carte que vous souhaitez donner (elle ne doit pas être de type tower) :\n";
    cin>>nameOfCardOwner;

    for (const auto& card_owner : currentPlayer.getHand().getEstablishments()){ // On verifie que la carte choisi est dans la main du joueur et qu'elle n'est pas de type tower
        
    }

    for (const auto& other_player : g.getPlayers()){
        if(nameOfExchanger==other_player.getName()){
            id_payer = other_player.getId();
        }
    }


}

/*
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

