//
// Created by mabur on 02/12/2022.

#ifndef MACHIKORO_FICHIER_GAME_H
#define MACHIKORO_FICHIER_GAME_H

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "../Bank/Bank.hpp"
#include "../Player/Player.hpp"
#include "../Board/Board.h"
#include "../UTILS/Enums.hpp"
#include "../Dies/Dies.h"

using namespace std;



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
    list <Player> Players_Game; //quel est la dif avec "vector <Player> players" qu'il y a déjà plus haut ?
    static Game* Game_single;
    list<Colors>Activation_order;
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
    void getBank() {return Bank_Game;}
    const vector<Player>& getPlayers() const {return players}; //pas sur, comment on recupere un vector ? (j'en ai besoin pour les cartes violettes)
};


#endif //MACHIKORO_FICHIER_GAME_H
