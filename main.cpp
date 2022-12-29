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
    Collection_standard* test = new Collection_standard ();
    Gamer.push_back(new Human("Omar",*test));
    Gamer.push_back(new Human("Sarah",*test));
    Gamer.push_back(new Human("Julie",*test));
    Gamer.push_back(new Human("Marius",*test));
    cout << "Hello World" << endl;

    //Board* test2 = new StandardBoard(*test);
    //test2->displayCards();
    StandardExpansion party(Gamer,*test);
    party.Do_Game();
    //test2->displayCards();


    return 0;
}


