#ifndef HARBORBOARD_H_INCLUDED
#define HARBORBOARD_H_INCLUDED

class HarborBoard : public Board {
private :
    Deck deck;
    size_t nb_card_dif;

public :
    virtual void initBoard();
    void fillBoard();
};


#endif // HARBORBOARD_H_INCLUDED
