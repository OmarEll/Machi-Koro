//
// Created by mabur on 02/12/2022.
//

#include "HarborExpansion.h"
#include "../Collection/Collection_harbor.h"
#include "../Board/Harbor/HarborBoard.h"
#include "../Bank/Bank.hpp"

HarborExpansion::HarborExpansion(vector<Player *> joueur, Collection_harbor &col) {
    players = joueur;
    establishments = col.GetEstablishment();
    landmarks = col.GetLandmark();
    minPlayers = 2;
    maxPlayers = 5;
    board_Game = Board::getInstance(col);
    dices.push_back(Dice());
    dices.push_back(Dice());
    bank_game = Bank::getInstance(joueur,2);
    Activation_order.push_back(RED);
    Activation_order.push_back(BLUE);
    Activation_order.push_back(GREEN);
    Activation_order.push_back(PURPLE);
    expansionName = Harbor;

}

void HarborExpansion::DoTurn(Player &current_player) {
    // Variables
    int dice = 0;
    string choice;
    // Fonction
    for (auto pl : players) {
        cout << pl->getName() << " dispose de " << bank_game->getBalance(pl->getId()) << endl;
    }
    //bank_game->playerPaysPlayer(current_player.getId(),players.at(2)->getId(),1);
    // Lance le dés
    cout << "\n\nC est au tour de " << current_player.getName() << endl;
    for (auto car : current_player.getHand()->getEstablishments())
        cout <<"\n" <<  car.second.top()->getCardName() << "\t quantite : " << car.second.size() << "\n" << endl;

    for (auto pl : players){
        cout << pl->getName()<< " dispose de "<< bank_game->getBalance(pl->getId()) << endl;
    }
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
            for (auto red_card : other_player->getHand()->getColorCards(RED)){
                if (red_card->activate(dice)){
                    cout << red_card->getOwner()->getName() << " recoit " << red_card->getEarnedCoins() * other_player->getHand()->
                            getEstablishments()[red_card->getCardName_Enum()].size() << " de " << current_player.getName() << "par" << red_card->getCardName() << endl;
                    for (int i = 0 ; i < other_player->getHand()->getEstablishments()[red_card->getCardName_Enum()].size();i++){
                        red_card->launchEffect(*this, current_player);
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
            if (current_player.getId() == all_players->getId() && cards->getColor() != RED && cards->activate(dice)){
                if (cards->getColor() != PURPLE && cards->getCardName_Enum() != FurnitureFactory && cards->getCardName_Enum() != CheeseFactory && cards->getCardName_Enum() != ProduceMarket){
                    cout << current_player.getName() << " gagne " << cards->getEarnedCoins() * current_player.getHand()->getEstablishments()[cards->getCardName_Enum()].size() << " coins grace a " << cards->getCardName()<< endl;
                    for (int i = 0 ; i < current_player.getHand()->getEstablishments()[cards->getCardName_Enum()].size();i++){
                        cards->launchEffect(*this,current_player);
                    }
                }
                else {
                    cards->launchEffect(*this,current_player); //si la carte est violette ou verte avec un gain avec type l'affichage est gérée directement dans le launch effect
                }
            }

            // Si le joueur est différent du current player et que la carte est bleue et qu'elle doit être activé
            if (current_player.getId() != all_players->getId() &&
                cards->getColor() == BLUE &&
                cards->activate(dice)){
                cout << all_players->getName() << " gagne " << cards->getEarnedCoins() * (all_players->getHand()->getEstablishments()[cards->getCardName_Enum()].size()) << " coins " <<cards->getCardName()<< endl;
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

void HarborExpansion::Do_Game() {
}

void HarborExpansion::initGame() {
}
