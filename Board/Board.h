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

    vector<stack<Card>> cards;
    size_t nbCards;
    size_t nbCardsMax;
    static Board* board_instance;

    Board(); //a implémenter
    ~Board();//a implémenter
    Board(Board&); //a implémenter
    Board& operator=(Board&); //a implémenter

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
        for (auto& it : cards){
            if(it.top()==c){ //sameCard
                it.push(c);
                exist=true;
            }
        }

        /*
        for(stack<Card> card_iter = cards.begin(); card_iter != cards.end(); card_iter++){
            if(card_iter.top()==c){
                card_iter.push(c);
                exist=true;
            }
        }
        */
        if(!exist){
            stack<Card> new_pile;
            new_pile.push(c);
            cards.push_back(new_pile);
        }
        nbCards++;
    };

    virtual void initBoard(); // à faire

    void removeCard(Card c){
        for (auto& it : cards){
            if(it.top()==c){
                it.pop();
                nbCards--;
            }
        }
    };

};

#endif // BOARD_H_INCLUDED
