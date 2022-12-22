#pragma once
/*#include "../Board/Board.h"
#include "Deck/Deck.h"*/
#include "Board.h"

class Deck;
class Board;

class HarborBoard : public Board {
private :
    Deck* deck;

public :
    HarborBoard(int,map<EstablishmentsNames,stack<Establishment*>>);
    //from super class
    void displayCards();
    void fillBoard(); //initialisation de marketplace
    Board& createBoard();
    //new to this class
    Deck* getDeck() { return deck;}
};


