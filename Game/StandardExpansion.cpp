#include "../Card/Establishment/Establishment.h"
#include "../Card/Landmark/Landmark.h"
#include "../UTILS/Enums.hpp"
#include "../Player/Player.hpp"
#include "../Board/Board.h"
#include "../Bank/Bank.hpp"
#include "StandardExpansion.h"


StandardExpansion::StandardExpansion (vector<Player*> joueur, Collection_standard& col){
    players = joueur;
    establishments = col.GetEstablishment();
    landmarks = col.GetLandmark();
    minPlayers = 2;
    maxPlayers = 4;
    board_Game = Board::getInstance(col);
    dices.push_back(Dice());
    dices.push_back(Dice());
    bank_game = Bank::getInstance(joueur,2);
    Activation_order.push_back(RED);
    Activation_order.push_back(BLUE);
    Activation_order.push_back(GREEN);
    Activation_order.push_back(PURPLE);
    expansionName = Standard;

}

void StandardExpansion::DoTurn(Player &current_player) {
    // Variables
    int dice = 0;
    string choice;
    // Fonction
    // Lance le dés
cout << "\n\nC est au tour de " << current_player.getName() << endl;
    dice = dice_turn(current_player);
    if (current_player.hasLandmark(RadioTower) != nullptr){
        cout << "Voulez vous relancer vos des ?" << endl;
        cin >> choice;
        if (choice == "oui"){
            dice = dice_turn(current_player);
        }
    }

    // On regarde les cartes rouges des autres joueurs
    for (auto other_player : players){
        if (other_player->getId() != current_player.getId()) {

            // On regarde si le nombre correspond à la carte rouge d'un autre joueur;
            for (auto vIter = other_player->getHand()->getColorCards(RED).begin();
                 vIter != other_player->getHand()->getColorCards(RED).end() &&
                 bank_game->getBalance(current_player.getId()) >0;
                 (*vIter)++) {
                if ((*vIter)->activate(dice))
                if ((**vIter).activate(dice) ){
                    for (int i = 0 ; i < other_player->getHand()->getEstablishments()[(*vIter)->getCardName_Enum()].size();i++){
                        (**vIter).launchEffect(*this, *other_player);
                        cout << (*vIter)->getOwner() << " recoit " << (*vIter)->getEarnedCoins() << " de " << current_player.getName() << "par" << (*vIter)->getCardName() << endl;
                    }
                }
            }
        }
    }
    // On a finit de regarder les cartes rouges des autres joueurs
    // Maintenant, on va activer toutes les cartes bleus des autres joueurs (current player compris)
    // Et toutes les cartes du current player qui doivent être activés
    for (auto all_players : players){

        // On regarde les établissement de tout le monde
        for ( auto pair_cards : all_players->getHand()->getEstablishments()){
            Establishment* cards = pair_cards.second.top();
            // Si le joueur est le current player et que sa cartes n'est pas rouge et doit être activé
            if (current_player.getId() == all_players->getId() &&
                cards->getColor() != RED &&
                cards->activate(dice)){
                cout << current_player.getName() << " gagne " << cards->getEarnedCoins() * current_player.getHand()->getEstablishments()[cards->getCardName_Enum()].size() << " coins grace a " << cards->getCardName()<< endl;
                for (int i = 0 ; i < current_player.getHand()->getEstablishments()[cards->getCardName_Enum()].size();i++)
                    cards->launchEffect(*this,current_player);
                }

            // Si le joueur est différent du current player et que la carte est bleue et qu'elle doit être activé
            if (current_player.getId() != all_players->getId() &&
                cards->getColor() == BLUE &&
                cards->activate(dice)){
                cout << all_players->getName() << " gagne " << cards->getEarnedCoins() * current_player.getHand()->getEstablishments()[cards->getCardName_Enum()].size() << " coins " <<cards->getCardName()<< endl;
                for (int i = 0 ; i < all_players->getHand()->getEstablishments()[cards->getCardName_Enum()].size();i++)
                    cards->launchEffect(*this,*all_players);
            }
        }
    }
    // On regarde si le joueur veut acheter un landmark
    choice = "";
    cout << current_player.getName() << " vous disposez de " << bank_game->getBalance(current_player.getId()) << " coins" << endl;
    cout<< "Voulez-vous acheter un etablissement ou un landmark ?\nEstablishment\nLandmark\nNothing" << endl;
    cin >> choice;
    if (choice == "Establishment"){
        int test = 0;
        while(test == 0) {
            cout << "Quel Establishment voulez-vous acheter ?" << endl;
            board_Game->displayCards();
            ::fflush(stdin);
            getline(cin, choice);
            Establishment *tmp = board_Game->foundEstablishmentOnBoard(choice);
            if (tmp != nullptr && bank_game->getBalance(current_player.getId()) - tmp->getCost() >= 0) {
                current_player.getHand()->addEstablishment(tmp, current_player);
                bank_game->deposit(current_player.getId(), tmp->getCost());
                test = 1;
            } else
                cout << "L etablissement n'existe pas && il n'a pas assez de money ! " << endl;
        }
    }
    else {
        if (choice == "Landmark"){
            int test = 0;
            while(test == 0) {
                cout << "Quel Landmark voulez-vous acheter ?" << endl;
                for (auto Land : current_player.getHand()->getLandmarks()){
                    if (!Land.second->isConstructed()){
                        cout << Land.second->getCardName() << "\nPrix = " << Land.second->getCost() << endl;
                    }
                }
                ::fflush(stdin);
                getline(cin,choice);
                EnumParser<LandmarksNames> fieldTypeParser;
                LandmarksNames val = fieldTypeParser.ParseSomeEnum(choice);
                // On regarde si l'établissement existe et qu'il a l'argent nécessaire
                if (!current_player.hasLandmark(val) &&
                    bank_game->getBalance(current_player.getId()) - GetCostLandmark(val) >= 0) {
                    current_player.getHand()->addLandmark(val);
                    bank_game->deposit(current_player.getId(), GetCostLandmark(val));
                    test = 1;
                } else {
                    cout << "Impossible : soit l'etablissement n'existe pas soit vous n'avez pas l'argent" << endl;
                }
            }
        }
        else
            cout << "Vous choisissez de ne faire aucune action" << endl;
    }
}

void StandardExpansion::Do_Game() {
    initGame();
    Player* test = nullptr;
    vector <Player*>::iterator current_player = players.begin();
    do{
        if (current_player == players.end()){
            current_player = players.begin();
        }
        test = *current_player;
        DoTurn(**current_player);
        if ((*current_player)->hasLandmark(AmusementPark) &&
            dices.front().GetResult() == dices.back().GetResult()){
            DoTurn(**current_player);
        }
        current_player++;
    } while (!Iswin(*test));
}

void StandardExpansion::initGame() {
    Establishment* baker= nullptr;
    Establishment* wheat= nullptr;
    for (auto bak : establishments){
        if (bak->getCardName_Enum() == Bakery){
            baker = bak;
        }
        if (bak->getCardName_Enum() == WheatField)
            wheat = bak;
    }
    for(auto joueur : players){
        joueur->getHand()->addEstablishment(baker->Clone(),*joueur);
        joueur->getHand()->addEstablishment(wheat->Clone(),*joueur);
        }
}




// Fin du tour d'un joueur


