
#include "GreenValleyBoard.h"
#include "Establishment.h"

void GreenValleyBoard::addEstablishmentToBoard(Establishment *e) {  // pour international exibit hall
    for (auto& establishment : cards){
        if(establishment.first == e->getCardName_Enum()){
            establishment.second.push(e);
        }
    }
}

GreenValleyBoard::GreenValleyBoard(Collection_GreenValley& col) : Board(){
    stack<Establishment*>* pile = nullptr;
    for (auto est : col.GetEstablishment()){
        pile = new stack<Establishment*>;
        if (est->getColor() != PURPLE){
            for (int i = 0; i < 6 ; i++){
                pile->push(est->Clone());}
        }
        else{
            for (int i = 0; i < 5 ; i++){
                pile->push(est->Clone());}
        }
        cards.insert(pair<EstablishmentsNames,stack<Establishment*>>(est->getCardName_Enum(),*pile));
    }
}
