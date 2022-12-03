//
// Created by mabur on 02/12/2022.
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "Bank.hpp"
#include "Player.hpp"
#include "Board.h"
#include "Enums.hpp"
#include "Dies/Dies.h"

using namespace std;
//

#ifndef MACHIKORO_FICHIER_GAME_H
#define MACHIKORO_FICHIER_GAME_H


class Game {
private :
    vector <Player> players;
    vector <Card> Establishments;
    vector <Card> Landmarks;
    size_t minPlayers;
    size_t maxPlayers;
    Board Board_Game;
    Dies Dice;
    Bank Bank_Game;
    list <Player> Players_Game;
    static Game* Game_single;
    list<Color>Activation_order;
    string Nom_Extension;
    Game ();
public:
    void virtual initGame();
    void virtual DoTurn ();
    bool Iswin(Player& current_player);
    void virtual Destructor ();
    ostream& Afficher_etat_partie (ostream& standard);
    static Game* Singleton (string NomEdition);
    Establishment& Buy_Establishment(Player& current_player);
    void Buy_Landmark(Player& current_player);
    string Get_Extension() { return Nom_Extension;}
};


#endif //MACHIKORO_FICHIER_GAME_H
