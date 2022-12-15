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
    void buyEstablishment(Player*,Establishment*);
    void buyLandmark(size_t ,Landmark*);
    bool buyableByPlayer(size_t id,Landmark*); //+
    bool buyableByPlayer(size_t id,Establishment*); //+
    bool isWinner(Player*);
    Game ();
public:
    //void virtual Destructor ();
    //string Get_Extension() { return Nom_Extension;}
    //const list<Player>& getPlayers() const {return Players_Game};
<<<<<<< Updated upstream
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
=======
    //static bool CanPay(Player& CurrentPlayer, Bank& bank, int amount);

    virtual ~Game();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    static Game* singleton (string NomEdition);

    void startGame();
    void virtual initGame();
    void virtual doTurn (Player& current_player);
    int throwDice (Player& current_player);

    ostream& afficher_etat_partie (ostream& standard);

    /*GETTERS*/
    Bank* getBank() {return bank;}
    vector<Player*> getPlayers() const {return players;}
    Dice * getDices(){return reinterpret_cast<Dice *>(Dices);}
    vector<Establishment> getEstablishments(){return Establishments;}
    vector<Landmark> getLandmarks(){return Landmarks;}
    Establishment* getEstablishmentByName(string estName);
    Establishment* getLandmarkByName(string landName);
    Board* getBoard() const{ return board;}
    void tradeTwoCards(Player* p1,Player p2, Establishment* cardP1,Establishment* cardP2);
>>>>>>> Stashed changes
};


#endif //MACHIKORO_FICHIER_GAME_H
