#pragma once

#include <stack>
#include <vector>
//#include "../../Card/Card.hpp"

class Card;
class Establishment;

using namespace std;

class Deck{
private :
    stack<Establishment*> cards;
public :
    explicit Deck(vector<Establishment*>);
    Establishment* drawCard();
    void addCardToDeck(Establishment* c);
};
