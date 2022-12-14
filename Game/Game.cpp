//
// Created by mabur on 02/12/2022.
//
#include "Card.hpp"
#include "Game.h"
#include "Establishment/Establishment.h"
#include "Landmark/Landmark.h"
#include "Enums.hpp"
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
                if (other_player.getId() != current_player.getId()) {

                    // On regarde si le nombre correspond à la carte rouge d'un autre joueur;
                    for (vector <Establishment*>::iterator vIter = other_player.getHand().getColorCards(RED).begin();
                            vIter != other_player.getHand().getColorCards(RED).end() ||
                            CanPay(current_player,Bank_Game,(**vIter).getCost());
                            (*vIter)++) {
                        if ((**vIter).activate(dice) ){
                            (**vIter).launchEffect();

                        }
                    }
                }
            }
            // On a finit de regarder les cartes rouges des autres joueurs
            // Maintenant, on va activer toutes les cartes bleus des autres joueurs (current player compris)
            // Et toutes les cartes du current player qui doivent être activés
            for (auto all_players : players){

                // On regarde les établissement de tout le monde
                for ( Establishment cards : all_players.getHand().getEstablishments()){

                    // Si le joueur est le current player et que sa cartes n'est pas rouge et doit être activé
                    if (current_player.getId() == all_players.getId() &&
                        cards.getColor() != RED &&
                        cards.activate(dice)){

                        cards.launchEffect();
                    }

                    // Si le joueur est différent du current player et que la carte est bleue et qu'elle doit être activé
                    if (current_player.getId() != all_players.getId() &&
                        cards.getColor() == BLUE &&
                        cards.activate(dice))

                        cards.launchEffect();
                }
            }
            // On regarde si le joueur veut acheter un landmark
            choice = "";
            cout<< "Voulez vous achetez un établissement ou un landmark ?\nEstablishment\nLandmark\nNothing" << endl;
            cin >> choice;
            if (choice == "Establishment"){
                cout << "Quelle Establishment voulez vous achetez ?" << endl;
                Board_Game.Affiche();
                cin >> choice;
                Buy_Establishment(current_player);
            }
            else {
                if (choice == "Landmark"){
                    cout << "Quel Landmark voulez-vous acheter ?" << endl;
                    cout << "Trainstation\nRadiotower\nAmusementPark\nCommercialCenter\n"<< endl;
                    cin >> choice;
                    // On regarde si l'établissement existe et qu'il a l'argent nécessaire
                    if (!current_player.hasLandmark(choice) &&
                    Bank_Game.getBalance(current_player.getId()) - FoundPriceLandmark(choice) >= 0 )
                        Buy_Landmark(current_player);
                    else
                        cout << "Impossible : soit l'établissement n'existe pas soit vous n'avez pas l'argent" << endl;
                }
                else
                    cout << "Vous choisissez de ne faire aucune action" << endl;
            }
        }
        // Fin du tour d'un joueur

void Game::Do_Game(){
    vector <Player>::iterator current_player = players.begin();
    do{
        if (current_player == players.end()){
            current_player = players.begin();
        }
        DoTurn(*current_player);
        if (current_player->hasLandmark(AmusementPark) &&
        Dices[0]->GetResult() == Dices[1]->GetResult()){
            DoTurn(*current_player);
        }
        current_player++;
    } while (Iswin(*current_player));
}



static bool Game::CanPay(Player &CurrentPlayer, class Bank &bank, int amount) {
    if (bank.getBalance(CurrentPlayer.getId()) - amount >= 0 )
        return true;
    else
        return false;
}

int Game::dice_turn(Player& current_player) {
    string choice;
    Dices[1] = 0;
    Dices[0]->rollDice();
    if (current_player.hasLandmark(TrainStation)){
        cout << "Voulez vous relancer un dé ? " << endl;
        cin >> choice;
        if (choice == "oui"){
            Dices[1]->rollDice();
            return Dices[0]->GetResult()+Dices[1]->GetResult() ;
        }
    }
    return Dices[0]->GetResult();
}


