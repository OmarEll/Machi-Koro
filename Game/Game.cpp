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

void virtual Game::DoTurn() {
    bool is_finish = false;
    int dice;
    do{
        for (auto current_player : Players_Game){
            dice = this->Dice.rollDice(current_player);
            for (auto other_player : Players_Game){
                if (other_player.getId() != current_player.getId()) {
                    for (auto red_cards: other_player.getHand().getRedCards()){
                       // if (red_cards)
                }
            }
        }
        }
    }

}
