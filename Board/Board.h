#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include "../Card/Card.hpp"

using namespace std;

class Board{
protected:
    vector<Establishment*> cards;
    size_t nbCards;
    size_t nbCardsMax;
    static Board* board_instance;
public :
    Board();
    virtual ~Board();
    Board(Board&)=delete;
    virtual void displayCards();
    virtual void fillBoard();
    virtual Board& createBoard();
    virtual void initBoard(); // à faire
};

#endif // BOARD_H_INCLUDED
