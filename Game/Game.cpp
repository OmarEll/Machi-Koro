//
// Created by mabur on 02/12/2022.
//
#include "Card.hpp"
#include "Game.h"
#include "Establishment/Establishment.h"
#include "Landmark/Landmark.h"
#include "Enums.hpp"
#include "Player.hpp"
#include "Board.h"
#include "Bank.hpp"
#include <iterator>

using namespace std;

Game* Game::Game_single = nullptr;

Game :: Game() {

}

Game* Game::Singleton(string NomEdition) {
    if (Game::Game_single == nullptr)
        Game::Game_single = new Game();
    return Game::Game_single;
}

bool Game::Iswin(Player& current_player) {
    for (auto land_check : current_player.getHand().getLandmarks() ){
        if (!land_check.second->isConstructed())
            return false;
    }
    return true;
}

// A METTRE DANS STANDARD
void Game::DoTurn(Player& current_player) {
    // Variables
    int dice = 0;

    string choice;
    // Fonction
            // Lance le dés
            dice = dice_turn(current_player);
            if (current_player.hasLandmark(RadioTower))
                cout << "Voulez vous relancez vos dés ?" << endl;
                cin >> choice;
                if (choice == "oui"){
                    dice = dice_turn(current_player);
                }
            // On regarde les cartes rouges des autres joueurs
            for (auto other_player : players){
                if (other_player->getId() != current_player.getId()) {

                    // On regarde si le nombre correspond à la carte rouge d'un autre joueur;
                    for (vector <Establishment*>::iterator vIter = other_player->getHand().getColorCards(RED).begin();
                            vIter != other_player->getHand().getColorCards(RED).end() &&
                            bank_game->getBalance(current_player.getId()) >0;
                            (*vIter)++) {
                        if ((**vIter).activate(dice) ){
                            (**vIter).launchEffect(*this, *other_player);

                        }
                    }
                }
            }
            // On a finit de regarder les cartes rouges des autres joueurs
            // Maintenant, on va activer toutes les cartes bleus des autres joueurs (current player compris)
            // Et toutes les cartes du current player qui doivent être activés
            for (auto all_players : players){

                // On regarde les établissement de tout le monde
                for ( auto pair_cards : all_players->getHand().getEstablishments()){
                    Establishment* cards = pair_cards.second.top();
                    // Si le joueur est le current player et que sa cartes n'est pas rouge et doit être activé
                    if (current_player.getId() == all_players->getId() &&
                        cards->getColor() != RED &&
                        cards->activate(dice)){

                        cards->launchEffect(*this,current_player);
                    }

                    // Si le joueur est différent du current player et que la carte est bleue et qu'elle doit être activé
                    if (current_player.getId() != all_players->getId() &&
                        cards->getColor() == BLUE &&
                        cards->activate(dice))

                        cards->launchEffect(*this,*all_players);
                }
            }
            // On regarde si le joueur veut acheter un landmark
            choice = "";
            cout<< "Voulez-vous acheter un établissement ou un landmark ?\nEstablishment\nLandmark\nNothing" << endl;
            cin >> choice;
            if (choice == "Establishment"){
                cout << "Quel Establishment voulez-vous acheter ?" << endl;
                board_Game->displayCards();
                cin >> choice;
                Establishment* tmp = board_Game->foundEstablishmentOnBoard(choice);
                EnumParser<EstablishmentsNames> fieldTypeParser;
                EstablishmentsNames val2 = fieldTypeParser.ParseSomeEnum(choice);
                if (tmp && bank_game->getBalance(current_player.getId()) - establishments[val2]->getCost()>=0)
                    current_player.getHand().addEstablishment(board_Game->foundEstablishmentOnBoard(choice));
                else
                    cout << "L etablissement n'existe pas ! " << endl;
            }
            else {
                if (choice == "Landmark"){
                    cout << "Quel Landmark voulez-vous acheter ?" << endl;
                    cout << "Trainstation\nRadiotower\nAmusementPark\nCommercialCenter\n"<< endl;
                    cin >> choice;
                    EnumParser<LandmarksNames> fieldTypeParser;
                    LandmarksNames val = fieldTypeParser.ParseSomeEnum(choice);
                    // On regarde si l'établissement existe et qu'il a l'argent nécessaire
                    if (!current_player.hasLandmark(val) &&
                    bank_game->getBalance(current_player.getId()) - landmarks[val]->getCost()>=0)
                    current_player.getHand().addLandmark(val);
                    else
                        cout << "Impossible : soit l'établissement n'existe pas soit vous n'avez pas l'argent" << endl;
                }
                else
                    cout << "Vous choisissez de ne faire aucune action" << endl;
            }
        }
        // Fin du tour d'un joueur

void Game::Do_Game(){
    vector <Player*>::iterator current_player = players.begin();
    do{
        if (current_player == players.end()){
            current_player = players.begin();
        }
        DoTurn(**current_player);
        if ((*current_player)->hasLandmark(AmusementPark) &&
        dices.front().GetResult() == dices.back().GetResult()){
            DoTurn(**current_player);
        }
        current_player++;
    } while (Iswin(**current_player));
}

int Game::dice_turn(Player& current_player) {
    string choice;
    dices.front().rollDice();
    if (current_player.hasLandmark(TrainStation)){
        cout << "Voulez vous relancer un dé ? " << endl;
        cin >> choice;
        if (choice == "oui"){
            dices.back().rollDice();
            return dices.front().GetResult()+dices.back().GetResult() ;
        }
    }
    return dices.front().GetResult();
}

Establishment *Game::getEstablishmentByName(string estName) {
    for (auto e : establishments){
        if (e->getCardName()==estName)
            return e;
    }
    return nullptr;
}


/*
 int somme = red_cards.laucheffect()
 if (other_player.hasLandmark(ShoppingMall))
 somme +=1
 BankGame.playerpaysplayer(current_player,other_player,somme);
 */

