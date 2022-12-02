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
