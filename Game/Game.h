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
#include "../Dice/Dice.h"
#include "../Card.hpp"

using namespace std;


class Game {
private :
    vector <Player*> players;
    vector <Establishment*> establishments;
    vector <Landmark*> landmarks;
    Bank* bank;
    Dice* dice[2] ;
    Board* board;
    size_t minPlayers;
    size_t maxPlayers;
    list<Colors>Activation_order;
    static Game* Game_single;
    //string Nom_Extension;
    Game ();
public:
    void virtual initGame();
    void virtual DoTurn (Player& current_player);
    bool Iswin(Player& current_player);
    void virtual Destructor ();
    ostream& Afficher_etat_partie (ostream& standard);
    static Game* Singleton (string NomEdition);
    Establishment& Buy_Establishment(Player& current_player);
    void Buy_Landmark(Player& current_player);
    string Get_Extension() { return Nom_Extension;}
    Bank getBank() {return Bank_Game;}
    void Do_Game();
    //const list<Player>& getPlayers() const {return Players_Game};
    vector <Player> getPlayers() const {return players;}
    int dice_turn (Player& current_player);
    static bool CanPay(Player& CurrentPlayer, Bank& bank, int amount);
    Dice * GetDices(){return reinterpret_cast<Dice *>(dice);}
    vector<Establishment> getEstablishments(){return establishments;}
    Establishment* getEstablishmentByName(string estName){
        for (auto e : establishments){
            if (e.getCardName()==estName)
                return &e;
        }
        return nullptr;
    }
    vector<Landmark> getLandmarks(){return landmarks;}
};


#endif //MACHIKORO_FICHIER_GAME_H
