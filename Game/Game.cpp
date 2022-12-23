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
#include "StandardExpansion.h"

using namespace std;

Game* Game::Game_single = nullptr;

Game :: Game() {

}

Game* Game::Singleton(string NomEdition, vector<Player*> joueurs, Collection&g) {
    if (Game::Game_single == nullptr)
        Game::Game_single = new StandardExpansion(joueurs, dynamic_cast<Collection_standard&>(g));
    return Game::Game_single;
}

bool Game::Iswin(Player& current_player) {
    for (auto land_check : current_player.getHand().getLandmarks() ){
        if (!(land_check.second->isConstructed()))
            return false;
    }
    return true;
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

void Game::initGame() {

}

