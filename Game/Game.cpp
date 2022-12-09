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
    for (auto land_check : current_player.getHand().GetLandmark() ){
        if (!land_check.construct())
            return false;
    }
    return true;
}

// A METTRE DANS STANDARD
void Game::DoTurn() {
    // Variables
    int dice;
    string choice;
    bool is_finish = false;
    // Fonction
    do{
        // Chaque joueur
        //for (auto current_player : Players_Game){
        for (vector <Player>::iterator current_player = players.begin();
             current_player != players.end() ||
             Iswin(*current_player);
             current_player++){

            // Lance le dés
            dice = this->Dice.rollDice(current_player);
            // On regarde les cartes rouges des autres joueurs
            for (auto other_player : Players_Game){
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
            for (auto all_players : Players_Game){

                // On regarde les établissement de tout le monde
                for ( Establishment cards : all_players.getHand().GetEstablishment()){

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
            cout<< "Voulez vous achetez un établissement ?\noui\nnon" << endl;
            cin >> choice;
            if (choice == "oui"){
                cout << "Quelle landmark voulez vous achetez ?" << endl;
                cout << "Trainstation\nRadiotower\nAmusementPark\nCommercialCenter\n"<< endl;
                cin >> choice;
                // On regarde si l'établissement existe et qu'il a l'argent nécessaire
                if (!(*current_player).hasLandmark(choice) &&
                current_player.getWallet().GetBalance - FoundPriceLandmark(choice) >= 0 )
                    Buy_Landmark(current_player);
                else
                    cout << "Impossible : soit l'établissement n'existe pas soit vous n'avez pas l'argent" << endl;
            }
            // On regarde si le joueur gagne la partie après avoir acheter le dernier LandMark
            if (Iswin(*current_player)){
                is_finish = true;
                cout << "Player" << current_player.getName() << "a gagné ! " << endl;
            }
        }
        // Fin de la boucle
    } while (!is_finish);
}


static bool Game::CanPay(Player &CurrentPlayer, class Bank &bank, int amount) {
    if (bank.getBalance(CurrentPlayer.getId()) - amount >= 0 )
        return true;
    else
        return false;
}


