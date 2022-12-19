//
// Created by mabur on 02/12/2022.

#pragma once
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "../Bank/Bank.hpp"
#include "../Player/Player.hpp"
#include "../Board/Board.h"
#include "../UTILS/Enums.hpp"
#include "../Dice/Dice.h"
#include "../Card/Establishment/Establishment.h"
#include "../Card/Landmark/Landmark.h"
#include "../Player/Hand/Hand.hpp"
#include "Landmark.h"

using namespace std;

class Player;
class Establishment;
class Landmark;
class Board;

class Game {
protected :
    vector <Player*> players;
    vector <Establishment*> establishments;
    vector <Landmark*> landmarks;
    size_t minPlayers;
    size_t maxPlayers;
    Board* board_Game;
    list<Dice> dices ;
    Bank* bank_game;
    static Game* Game_single;
    list<Colors>Activation_order;
    Expansions expansionName;
    Game ();
     //+
public:
    void virtual initGame();
    void virtual DoTurn (Player& current_player);
    bool Iswin(Player& current_player);
    void virtual Destructor ();
    ostream& Afficher_etat_partie (ostream& standard);
    static Game* Singleton (string NomEdition);
    Expansions Get_Extension() { return expansionName;}
    Bank* getBank() {return bank_game;}
    Board* getBoard(){ return board_Game; }
    void Do_Game();
    //const list<Player>& getPlayers() const {return Players_Game};
    vector<Player*> getPlayers() const {return players;}
    int dice_turn (Player& current_player);
    //Dice * GetDices(){return reinterpret_cast<Dice *>(dices);}
    list <Dice> GetDices(){return dices; }
    vector<Establishment*> getEstablishments(){return establishments;}
    Establishment* getEstablishmentByName(string estName);
    vector<Landmark*> getLandmarks(){return landmarks;}
};

