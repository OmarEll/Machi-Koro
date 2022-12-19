#ifndef GREENVALLEYBOARD_H_INCLUDED
#define GREENVALLEYBOARD_H_INCLUDED

#include "../Board/Board.h"

class GreenValleyBoard : public Board {

public :
    virtual void initBoard();
    void addEstablishmentToBoard(Establishment* e){  // pour international exibit hall
        for (auto& establishment : cards){
            if(establishment.first == e->getCardName_Enum()){
                establishment.second.push(e);
            }
        }
    }
};


#endif // GREENVALLEYBOARD_H_INCLUDED
