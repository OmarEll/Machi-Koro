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
    // Remarque : finalement pas besoin de m�thode isEmpty()
    // avec stack on a deja cards.empty() qui renvoie bool
    explicit Deck(vector<Establishment*>);
    Establishment* drawCard();
    void addCardToDeck(Establishment* c);
};
