//
// Created by mabur on 02/12/2022.
#include <iostream>
#include <list>
#include <string>

using namespace std;
//

#ifndef MACHIKORO_FICHIER_GAME_H
#define MACHIKORO_FICHIER_GAME_H


class Game {
private :
    Vector <Player> players;
    Vector <Card> Establishments;
    Vector <Card> Landmarks;
    size_t minPlayers;
    size_t maxPlayers;
    board Board_Game;
    list<dies> Dice;
    Bank Bank_Game;
    list <player> Players_Game;
    static Game* Game_single;
    List<colors> Activation_order;
    string Nom_Extension;
    Game ();
public:
    void virtual initGame();
    void virtual DoTurn ();
    bool Iswin(player& current_player);
    void virtual Destructor ();
    ostream& Afficher_etat_partie (ostream& standard);
    static Game* Singleton (string NomEdition);
    Establishment& Buy_Establishment(player& current_player);
    void Buy_Landmark(player& current_player);
    string Get_Extension() { return Nom_Extension;}
};


#endif //MACHIKORO_FICHIER_GAME_H
