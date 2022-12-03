#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

class Deck{
private :
    stack<Card> cards;

public :
    // Remarque : finalement pas besoin de méthode isEmpty()
    // avec stack on a deja cards.empty() qui renvoie bool

    Card drawCard(){
        if (!cards.empty()){
            Card c = cards.top();
            cards.pop();
            return c;
        }
        cout<<"la pile est vide, impossible de piocher";
        return nullptr;
    };

    void addCardToDeck(Card c){
        cards.push(c);
    }
};

#endif // DECK_H_INCLUDED
