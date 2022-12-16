#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include "../Card/Establishment/Establishment.h"
using namespace std;

class Establishment;

class Board{
protected:
    map<EstablishmentsNames,stack<Establishment*>> cards;
    size_t nbCardsMax;
    static Board* board_instance;
    Board():nbCardsMax(0),cards(){}
public :
    virtual ~Board();
    Board(Board&)=delete;
    virtual void displayCards();
    virtual void fillBoard();
    virtual Board& createBoard();
    static Board* getInstance(){
        if(board_instance==nullptr){
            board_instance=new Board();
        }
        return board_instance;
    }
    // GETTERS & SETTERS
    size_t getNbCardsMax(){ return nbCardsMax; }
    map<EstablishmentsNames,stack<Establishment*>> getCards(){ return cards; }

    void setNbCardsMax(size_t nb){ nbCardsMax=nb; }
    void setCards(map<EstablishmentsNames,stack<Establishment*>> establishments){
        cards=establishments;
    }
};