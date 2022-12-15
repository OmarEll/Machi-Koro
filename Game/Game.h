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
#include "../Card/Establishment/Establishment.h"
#include "../Card/Landmark/Landmark.h"
using namespace std;


class Game {
protected : //protected because we can't inheret from this class if it's private
    vector <Player*> players;
    vector <Establishment*> establishments;
    vector <Landmark*> landmarks;
    Bank* bank;
    Dice* dice[2] ;
    Board* board;
    size_t gameSize[2]; // min / max
    list<Colors>activationOorder;
    static Game* Game_single;
    //string Nom_Extension;
    //Establishment& Buy_Establishment(Player& current_player);
    void buyEstablishment(Player*,EstablishmentsNames); //+
    void buyLandmark(Player*,LandmarksNames); //+

    bool buyableByPlayer(size_t id,Card*); //+
    bool isWinner(Player*); //+
    Game (); //+
public:
    //void virtual Destructor ();
    //string Get_Extension() { return Nom_Extension;}
    //const list<Player>& getPlayers() const {return Players_Game};

    //static bool CanPay(Player& CurrentPlayer, Bank& bank, int amount);

    virtual ~Game();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    static Game* getInstance ();

    virtual void startGame();
    virtual void  initGame();
    virtual void  doTurn (Player& current_player);
    int throwDice (Player& current_player);//+

    //ostream& afficher_etat_partie (ostream& standard);

    /*GETTERS*/
    Bank* getBank() {return bank;}
    vector <Player> getPlayers() const {return players;}
    Dice * getDices(){return reinterpret_cast<Dice *>(dice);}
    vector<Establishment> getEstablishments(){return establishments;}
    vector<Landmark> getLandmarks(){return landmarks;}
    Establishment* getEstablishmentByName(string estName);
    Landmark* getLandmarkByName(string landName);
    Board* getBoard() const{ return board;}
    void tradeTwoCards(Player* p1,Player* p2, EstablishmentsNames,EstablishmentsNames);
};


#endif //MACHIKORO_FICHIER_GAME_H
