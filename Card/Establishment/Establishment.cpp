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


/* Definition de l'effet de base d'un etablissement (recevoir de l'argent de la banque ou d'un joueur) */

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

/* Definition de méthodes qui permetterons de redefinir des effets pour plusieurs cartes */

int Establishment::numberGainWithType(Player* owner, vector<Types> t) const{  //fonction à utiliser pour les cartes comme cheese factory
    // ici on calcule le nb de cartes d'un certain type que possède un joueur et on le multiplie par le gain de la carte
    int nb = getEarnedCoins();
    int sum=0;
    for (auto& it : t){
        sum += owner->getHand().getTypeCards(it).size();
    }
    return sum*nb;
}

bool Establishment::hasHarbor(){ //fonction qui permet de regarder si le joueur propriètaire de la carte possède un Harbor dans sa main
    //utilisée pour les effets avec "If you have a harbor"
    return getOwner()->hasLandmark(HarborCard);
}



/* Redefinition des effets des cartes violettes standard */

void Stadium::launchEffect(Game& g, Player& currentPlayer){ //méthode redefinie pour permettre de recevoir des coins de la part de l'ensemble des adversaires
    int id_Owner=getOwner()->getId();
    for (const auto& other_player : g.getPlayers()){
        int id_other = other_player->getId();
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
    int id_payer = -1;
    int id_Owner=getOwner()->getId();
    while (id_payer==-1){
        cout<<"Choissisez le joueur qui doit vous payer :\n";
        for (const auto& other_player : g.getPlayers()){
            cout<<other_player->getName()<<" "; //affiche la liste des joueurs
        }
        cout<<"\n";
        cin>>nameOfPayer;
        for (const auto& other_player : g.getPlayers()){
            if(nameOfPayer==other_player->getName()){
                id_payer = other_player->getId();
            }
        }
    }
    g.getBank().playerPaysPlayer(id_payer, id_Owner, getEarnedCoins());
}



void Office::launchEffect(Game& g, Player& currentPlayer){ //echange une carte avec un autre joueur sauf de type tower (ie.les cartes violettes)
    Establishment* CardExchanger= nullptr;
    Establishment* CardOwner= nullptr;
    Player* playerExchanger= nullptr;
    string nameOfExchanger;
    string nameOfCardExchanger;
    string nameOfCardOwner;
    while (playerExchanger == nullptr){
        cout<<"Entrez le nom du joueur avec qui vous voulez échanger une carte :\n";
        cin>>nameOfExchanger;
        for (const auto& other_player : g.getPlayers()){
            if(nameOfExchanger==other_player->getName()){
                playerExchanger = other_player;
            }
        }
    }

    while (CardExchanger== nullptr || CardOwner== nullptr){
        cout<<"Entrez le nom de la carte que vous souhaitez récupérer (elle ne doit pas être de type tower) :\n";
        cin>>nameOfCardExchanger;
        cout<<"Entrez le nom de la carte que vous souhaitez donner (elle ne doit pas être de type tower) :\n";
        cin>>nameOfCardOwner;

        //Owner
        for (const auto&  card : currentPlayer.getHand().getEstablishments()){ // On verifie que la carte choisi est dans la main du joueur et qu'elle n'est pas de type tower
            if((nameOfCardOwner==(card.first)->getCardName()) && ((card.first)->getType()!=tower) ){
                CardOwner=card.first;
            }
        }
        //Exchanger
        for (const auto&  card : playerExchanger->getHand().getEstablishments()){ // On verifie que la carte choisi est dans la main du joueur et qu'elle n'est pas de type tower
            if((nameOfCardExchanger==(card.first)->getCardName()) && ((card.first)->getType()!=tower) ){
                CardExchanger=card.first;
            }
        }

    }
    //add
    currentPlayer.getHand().addEstablishment(CardExchanger);
    playerExchanger->getHand().addEstablishment(CardOwner);
    //remove
    currentPlayer.getHand().removeEstablishment(CardOwner);
    playerExchanger->getHand().removeEstablishment(CardExchanger);
}


/* Redefinition des establishments avec un effet de type "For each of your 'type' establishments, gain x coins"*/
//Standard
void CheeseFactory::launchEffect(Game& g, Player& currentPlayer){
    setNumberOfCoinsEarned(numberGainWithType(getOwner(), {cow}));
    Establishment::launchEffect(g, currentPlayer);
}

void FurnitureFactory::launchEffect(Game& g, Player& currentPlayer){
    setNumberOfCoinsEarned(numberGainWithType(getOwner(), {wheel}));
    Establishment::launchEffect(g, currentPlayer);
}

void ProduceMarket::launchEffect(Game& g, Player& currentPlayer){
    setNumberOfCoinsEarned(numberGainWithType(getOwner(), {wheat}));
    Establishment::launchEffect(g, currentPlayer);
}

//Harbor
void FoodWarehouse::launchEffect(Game& g, Player& currentPlayer){
    setNumberOfCoinsEarned(numberGainWithType(getOwner(), {coffee}));
    Establishment::launchEffect(g, currentPlayer);
}

/* Redefinition des establishments avec un effet de type "If you have a Harbor, gain x coins"*/
void MackerelBoat::launchEffect(Game& g, Player& currentPlayer){
    if (hasHarbor()) Establishment::launchEffect(g, currentPlayer);
}

void SushiBar::launchEffect(Game& g, Player& currentPlayer){
    if (hasHarbor()) Establishment::launchEffect(g, currentPlayer);
}


/* Redéfinition des cartes violettes harbor */

void Publisher::launchEffect(Game& g, Player& currentPlayer){
    //setNumberOfCoinsEarned a redefinir pour regarder les cartes des adversaires
    setNumberOfCoinsEarned(numberGainWithType(getOwner(), {coffee,bread}));
    Establishment::launchEffect(g, currentPlayer);
}



