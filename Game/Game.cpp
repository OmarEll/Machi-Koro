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
#include "../Collection/Collection_harbor.h"
#include "../Collection/Collection_standard.h"
#include "../Collection/Collection_GreenValley.h"
#include "../Collection/Collection_deluxe.h"
#include "HarborExpansion.h"
#include "GreenValleyExpansion.h"
#include "DeluxeExpansion.h"
#include "Human/Human.h"

using namespace std;

Game* Game::Game_single = nullptr;

Game :: Game() {

}

// Conversion string en int pour switch
constexpr unsigned int str2int(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

Game* Game::Singleton(const char *const NomEdition) {
    if (Game::Game_single == nullptr) {
        Collection *g = nullptr;
        switch (str2int(NomEdition)) {
            case str2int("Standard"): {
                g = new Collection_standard();
                Game::Game_single = new StandardExpansion(dynamic_cast<Collection_standard &>(*g));
                break;
            }
            case str2int("Harbor"): {
                g = new Collection_harbor();
                Game::Game_single = new HarborExpansion(dynamic_cast<Collection_harbor &>(*g));
                break;
            }
            case str2int("Green Valley"): {
                g = new Collection_GreenValley();
                Game::Game_single = new GreenValleyExpansion(dynamic_cast<Collection_GreenValley &>(*g));
                break;
            }
            case str2int("Deluxe"): {
                g = new Collection_deluxe();
                Game::Game_single = new DeluxeExpansion(dynamic_cast<Collection_deluxe &>(*g));
                break;
            }
        }
    }
    return Game::Game_single;
}

bool Game::Iswin(Player& current_player) {
    for (auto land_check : current_player.getHand()->getLandmarks() ){
        if (!(land_check.second->isConstructed()))
            return false;
    }
    return true;
}

int Game::dice_turn(Player& current_player) {
    string choice;
    dices.back().reset_dice();
    dices.front().rollDice();
    cout << " Le resultat du de donne " << dices.front().GetResult() << endl;
    if (current_player.hasLandmark(TrainStation)){
        cout << "Voulez vous lancer un autre de ? " << endl;
        cin >> choice;
        if (choice == "oui"){
            dices.back().rollDice();
            cout << "Vous avez lance " << dices.front().GetResult() << " et " << dices.back().GetResult() << endl;
            cout << " Le resultat des des donnent " << dices.front().GetResult()+dices.back().GetResult() << endl;
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

int Game::GetCostLandmark(LandmarksNames name) {
    for (auto Land : landmarks){
        if (Land->getLandmarks() == name)
            return Land->getCost();
    }
    return 0;
}

