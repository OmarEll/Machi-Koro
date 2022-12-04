#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include "../Card.hpp"
using namespace std;

class Board{
private :

    vector<stack<Card>> cards;
    size_t nbCards;
    size_t nbCardsMax;
    static Board* board_instance;

    Board();
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

    void addCard(Card c){
        bool exist=false;
        for(card_iter = cards.begin(); card_iter != cards.end(); card_iter++){
            if(card_iter.top()==c){
                card_iter.push(c);
                exist=true;
            }
        }
        if(exist==false){
            stack<Card> new_pile;
            new_pile.push(c);
            cards.push_back(new_pile);
        }
        nbCards++;
    };

    virtual void initBoard();

    void removeCard(Card){
        for(card_iter = cards.begin(); card_iter != cards.end(); card_iter++){
            if(card_iter.top()==c){
                card_iter.pop();
                nbCards--;
            }
    };

};

#endif // BOARD_H_INCLUDED
