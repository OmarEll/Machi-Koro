#ifndef HARBORBOARD_H_INCLUDED
#define HARBORBOARD_H_INCLUDED

#include "../Board/Board.h"
#include "Deck/Deck.h"

class HarborBoard : public Board {
private :
    Deck* deck;

public :
    //from super class
    void initBoard();
    void displayCards();
    void fillBoard(); //initialisation de marketplace
    Board& createBoard();
    //new to this class
    Deck* getDeck() { return deck;}
};


#endif // HARBORBOARD_H_INCLUDED