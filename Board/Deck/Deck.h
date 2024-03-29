#pragma once

#include <stack>
#include <vector>
//#include "../../Card/Card.hpp"

class Card;
class Establishment;

using namespace std;

class Deck{
protected :
    stack<Establishment*> cardsDeck;
public :
    explicit Deck(vector<Establishment*>*);
    Establishment* drawCard();
    void addCardToDeck(Establishment* c);
    bool is_empty(){ return cardsDeck.empty();}
};
