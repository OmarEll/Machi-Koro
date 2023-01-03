#include <iostream>
#include "Bank/Bank.hpp"
#include "Bank/Wallet.hpp"
#include "Board/Board.h"
#include "Board/GreenValleyBoard.h"
#include "Deluxe/DeluxeBoard.h"
#include "Board/Deck/Deck.h"
#include "Board/Harbor/HarborBoard.h"
#include "Standard/StandardBoard.h"
#include "Card/Establishment/Establishment.h"
#include "Card/Landmark/Landmark.h"
#include "Card/Card.hpp"
#include "Dice/Dice.h"
#include "Game/DeluxeExpansion.h"
#include "Game/Game.h"
#include "Game/GreenValleyExpansion.h"
#include "Game/HarborExpansion.h"
#include "Game/StandardExpansion.h"
#include "Player/Hand/Hand.hpp"
#include "Player/IA/IA.hpp"
#include "Player/Human/Human.h"
#include "UTILS/Enums.hpp"
#include "Collection/Collection.h"
#include "Collection/Collection_standard.h"
#include "Collection/Collection_GreenValley.h"
#include "Collection/Collection_harbor.h"
#include "Collection/Collection_deluxe.h"
using namespace std;
// C'est Marius
// C'est Sarah
int main(){
    vector<Player*> Gamer;
    /*
    Collection_standard* test = new Collection_standard ();
    Gamer.push_back(new Human("Omar",*test));
    Gamer.push_back(new Human("Sarah",*test));
    Gamer.push_back(new Human("Julie",*test));
    Gamer.push_back(new Human("Marius",*test));
    cout << "Hello World" << endl;
    //Board* test2 = new StandardBoard(*test);
    //test2->displayCards();
    Game *party = Game::Singleton("Standard",Gamer);
    cout << party->Get_Extension()<< endl;
    party->getBoard()->displayCards();
    party->Do_Game();
    //test2->displayCards();
    */
    
    //main general
    Collection_standard* test = new Collection_standard ();
    Game *party = Game::Singleton("Standard",Gamer);
    string choixExtension;
    cout << "A quelle extension du jeu Machi Koro voulez-vous jouer ? (Standard, Harbor, Green Valley ou Deluxe) \n";
    ::fflush(stdin);
    getline(cin,choixExtension);
    bool bonChoixExtension = false;
    while (!bonChoixExtension){
        if (choixExtension == "Standard") {
            Collection_standard* test = new Collection_standard ();
            Game *party = Game::Singleton("Standard",Gamer);
            bonChoixExtension = true;
        }
        else if (choixExtension == "Harbor") {
            Collection_harbor* test = new Collection_harbor ();
            Game *party = Game::Singleton("Harbor",Gamer);
            bonChoixExtension = true;
        }
        else if (choixExtension == "Green Valley") {
            Collection_GreenValley* test = new Collection_GreenValley();
            Game *party = Game::Singleton("Green Valley",Gamer);
            bonChoixExtension = true;
        }
        else if (choixExtension == "Deluxe") {
            Collection_deluxe* test = new Collection_deluxe();
            Game *party = Game::Singleton("Deluxe",Gamer);
            bonChoixExtension = true;
        }
        else cout << "Le choix d'extension est invalide\n";
    }

    int nbJoueurs = 0;
    cout << "Quel est le nombre de joueurs ?\n";
    ::fflush(stdin);
    cin >> nbJoueurs;

    for (int i = 1; i <= nbJoueurs; i++){
        string nomJoueur;
        cout << "Entrez le nom du " << i << "e joueur : \n";
        ::fflush(stdin);
        getline(cin,nomJoueur);
        Gamer.push_back(new Human(nomJoueur,*test));
    }

    party->getBoard()->displayCards();
    party->Do_Game();


    return 0;
}


