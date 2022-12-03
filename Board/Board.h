#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Board{
private :

    vector<stack<Card>> cards;
    size_t nbCards;
    size_t nbCardsMax;
    static Board* board_instance;

    Board Board();
    ~Board();
    Board(Board);
    Board& operator=(Board&);

public :
    Board& createBoard(){
        if (board_instance == nullptr){
            static Board& b;
            return b;
        }
        else return board_instance;
    };

    void addCard(Card);

    virtual void initBoard();

    void removeCard(Card);

};

#endif // BOARD_H_INCLUDED
