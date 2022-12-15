//
// Created by mabur on 02/12/2022.
//
#include "Card.hpp"
#include "Game.h"
#include "Establishment/Establishment.h"
#include "../Card/Landmark/Landmark.h"
#include "Enums.hpp"
#include <iterator>

using namespace std;

Game* Game::Game_single = nullptr;

Game :: Game():board(nullptr),bank(nullptr),players(),establishments(),landmarks(),dice(),activationOorder(){}

 Game* Game::getInstance() {
    if (Game::Game_single == nullptr){
        Game::Game_single = new Game();
    }
    return Game::Game_single;
}

bool Game::isWinner(Player* current_player) {
    for (auto land_check : current_player->getHand().getLandmarks() ){
        if (!land_check.second->isConstructed())
            return false;
    }
    return true;
}

Establishment* Game::getEstablishmentByName(string estName){
    for (auto establishment : establishments){
        if (establishment->getCardName()==estName)
        return establishment;
    }
    return nullptr;
}
Landmark* Game::getLandmarkByName(string landName){
    for (auto landmark : landmarks){
        if (landmark->getCardName()==landName)
            return landmark;
    }
    return nullptr;
}
bool Game::buyableByPlayer(size_t idPlayer,Card* card){
    return bank->getBalance(idPlayer)>=card->getCost();
}

void Game::buyLandmark(Player* player,LandmarksNames landmarkName){
    Landmark* landmark=player->hasLandmark(landmarkName);
    if(landmark != nullptr){
        if (buyableByPlayer(player->getId(),landmark)){
            bank->deposit(player->getId(),landmark->getCost());
            landmark->setConstruction();
        }else{
            cout << "Vous n'avez pas assez d'argent";
        }
    }

}

void Game::buyEstablishment(Player* player,EstablishmentsNames establishmentName){
    Establishment* establishment=player->hasEstablishment(establishmentName);
    if(establishment != nullptr){
        if (buyableByPlayer(player->getId(),establishment)){
            bank->deposit(player->getId(),establishment->getCost());
            player->getHand().addEstablishment(establishmentName);
        }else{
            cout << "Vous n'avez pas assez d'argent";
        }
    }

}

int Game::throwDice(Player& current_player) {
    string choice;
    dice[0]->rollDice();
    if (current_player.hasLandmark(TrainStation)){
        cout << "Voulez vous relancer un dé ? " << endl;
        cin >> choice;
        if (choice == "oui"){
            dice[1]->rollDice();
            return dice[0]->GetResult()+dice[1]->GetResult() ;
        }
    }
    return dice[0]->GetResult();
}



void Game::tradeTwoCards(Player* p1,Player* p2, EstablishmentsNames cardP1,EstablishmentsNames cardP2){
    p1->getHand().removeEstablishment(cardP1);
    p2->getHand().addEstablishment(cardP2);
}