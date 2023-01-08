#include "StandardBoard.h"
#include "../../Card/Establishment/Establishment.h"
#include <string>


StandardBoard::StandardBoard(Collection_standard& col):Board() {
    stack<Establishment*>* pile = nullptr;
    for (auto est : col.GetEstablishment()){
        pile = new stack<Establishment*>;
        if (est->getColor() != PURPLE){
            for (int i = 0; i < 6 ; i++){
                pile->push(est->Clone());}
            }
        else{
            for (int i = 0; i < 4 ; i++){
                pile->push(est->Clone());}
        }
        cards.insert(pair<EstablishmentsNames,stack<Establishment*>>(est->getCardName_Enum(),*pile));
    }
}

