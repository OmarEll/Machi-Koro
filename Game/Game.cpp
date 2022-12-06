//
// Created by mabur on 02/12/2022.
//

#include "Game.h"

using namespace std;

Game* Game::Game_single = NULL;

Game :: Game() {

}

Game* Game::Singleton(string NomEdition) {
    if (Game::Game_single == NULL)
        Game::Game_single = new Game();
    return Game::Game_single;
}

bool Game::Iswin(Player& current_player) {
    for (auto land_check : current_player.getHand().GetLandmarks() ){
        if (!land_check.construct())
            return false;
    }
    return true;
}

// A METTRE DANS STANDARD
void virtual Game::DoTurn() {
    // Variables
    bool is_finish = false;
    int dice;
    char choice;
    // Fonction
    do{
        // Chaque joueur
        for (auto current_player : Players_Game){
            // Lance le dés
            dice = this->Dice.rollDice(current_player);
            // On regarde les cartes rouges des autres joueurs
            for (auto other_player : Players_Game){
                if (other_player.getId() != current_player.getId()) {
                    // On regarde si le nombre correspond à la carte rouge d'un autre joueur;
                    for (Red red_cards: other_player.getHand().getRedCards()){
                        red_cards.activate(dice);
                        // Si la carte est considéré comme activated
                        if (red_cards.get_activated()){
                            // On paye
                            current_player.getWallet().removeCoins(red_cards.getNumberOfCoinsEarned());
                            (red_cards.getOwner()).getWallet().addCoins(red_cards.getNumberOfCoinsEarned);
                            red_cards.deactivate();
                        }
                    }
                }
            }
            // On a finit de regarder les cartes rouges des autres joueurs
            // Il faut trouver moyen de regarder les cartes bleus des autres joueurs en même temps
            cout<< "Voulez vous achetez un établissement ?\na-oui\nb-non" << endl;
            cin >> choice;

        }
    }

}
