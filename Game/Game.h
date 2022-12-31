//
// Created by mabur on 02/12/2022.

#pragma once
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "../UTILS/Enums.hpp"
#include "../Dice/Dice.h"
#include "../Collection/Collection.h"
#include "../Collection/Collection_standard.h"
/*
#include "../Bank/Bank.hpp"
#include "../Player/Player.hpp"
#include "../Board/Board.h"
#include "../Dice/Dice.h"
#include "../Card/Establishment/Establishment.h"
#include "../Card/Landmark/Landmark.h"
#include "../Player/Hand/Hand.hpp"
#include "Landmark.h"*/

using namespace std;
class Bank;
class Board;
class Hand;
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
    void virtual initGame() = 0;
    virtual  ~Game() = default;
    int GetCostLandmark (LandmarksNames);
    void virtual DoTurn (Player& current_player) = 0;
    void virtual Do_Game() = 0;
    bool Iswin(Player& current_player);
    ostream& Afficher_etat_partie (ostream& standard);
    static Game* Singleton (string NomEdition, vector<Player*>, Collection&);
    Expansions Get_Extension() { return expansionName;}
    Bank* getBank() {return bank_game;}
    Board* getBoard(){ return board_Game; }
    //const list<Player>& getPlayers() const {return Players_Game};
    vector<Player*> getPlayers() const {return players;}
    int dice_turn (Player& current_player);
    //Dice * GetDices(){return reinterpret_cast<Dice *>(dices);}
    list <Dice> GetDices(){return dices; }
    vector<Establishment*> getEstablishments(){return establishments;}
    Establishment* getEstablishmentByName(string estName);
    vector<Landmark*> getLandmarks(){return landmarks;}
    //

};

