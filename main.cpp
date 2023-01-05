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
#include "Collection/Collection_standard.h"
#include "Collection/Collection_GreenValley.h"
#include "Collection/Collection_harbor.h"
#include "Collection/Collection_deluxe.h"
using namespace std;
// C'est Marius
// C'est Sarah
int main(){



    //main general
    string choixExtension;
    cout << "A quelle extension du jeu Machi Koro voulez-vous jouer ? (Standard, Harbor, Green Valley ou Deluxe) \n";
    //A REMETTRE
    /*
    while(choixExtension != "Standard" && choixExtension != "Harbor" && choixExtension != "Green Valley" && choixExtension != "Deluxe"){
        ::fflush(stdin);
        getline(cin,choixExtension);
    }
     */
    choixExtension = "Harbor"; //POUR TEST
    const char * c = choixExtension.c_str();
    Game *party = Game::Singleton(c);
    party->getBoard()->displayCards();
    party->Do_Game();

    return 0;
}


