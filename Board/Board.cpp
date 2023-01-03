//
// Created by mabur on 19/12/2022.
//
#include "Board.h"
#include "Establishment.h"
#include "Standard/StandardBoard.h"
#include "../Collection/Collection_harbor.h"
#include "HarborExpansion.h"
#include "Harbor/HarborBoard.h"
#include "../Collection/Collection_GreenValley.h"
#include "GreenValleyBoard.h"
#include "../Collection/Collection_deluxe.h"
#include "Deluxe/DeluxeBoard.h"

Board* Board::board_instance = nullptr;

Establishment* Board::foundEstablishmentOnBoard(string choice) {
    EnumParser<EstablishmentsNames> fieldTypeParser;
    EstablishmentsNames val = fieldTypeParser.ParseSomeEnum(choice);
    Establishment* tmp = nullptr;
    for (auto establishment : cards){
        if (val == establishment.first){
            tmp = establishment.second.top();
            this->cards[val].pop();
            return tmp;
        }
    }
    return nullptr;
}

void Board::displayVector(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void Board::displayCards() {
    string colorName;
    string typeName;

    for (auto card : cards){
        if (card.second.top()!= nullptr){
        cout<<card.second.size()<<" "<<card.second.top()->getCardName()<<"\n" ;
        switch(card.second.top()->getColor()){
            case 0:
                colorName = "Red";
                break;
            case 1:
                colorName = "Blue";
                break;
            case 2:
                colorName = "Purple";
                break;
            case 3:
                colorName = "Green";
                break;
            default :
                colorName = "Couleur inconnue";
        }
        cout<<"   Color : "<<colorName<<"\n" ;
        switch(card.second.top()->getType()){
            case 0:
                typeName = "wheat";
                break;
            case 1:
                typeName = "cow";
                break;
            case 2:
                typeName = "bread";
                break;
            case 3:
                typeName = "coffee";
                break;
            case 4:
                typeName = "wheel";
                break;
            case 5:
                typeName = "tower";
                break;
            case 6:
                typeName = "factory";
                break;
            case 7:
                typeName = "apple";
                break;
            case 8:
                typeName = "boat";
                break;
            case 9:
                typeName = "suitcase";
                break;
            default :
                typeName = "Type inconnu";
        }
        cout<<"   Type : "<<typeName<<"\n" ;
        cout<<"   Earned coins : "<<card.second.top()->getEarnedCoins()<<"\n" ;
        cout<<"   Price : "<<card.second.top()->getCost()<<"\n" ;
        cout<<"   Activation Number(s) : ";
        displayVector(card.second.top()->getActivationNumbers());
        cout<<"   "<<card.second.top()->getDescription()<<"\n" ;
        }
    }
}


Board *Board::getInstance(Collection& g) { // faire switch avec en paramètre en string ou enum pour extension
    if(board_instance==nullptr){

        Collection_standard *pt1 = dynamic_cast<Collection_standard*>(&g);
        if (pt1)
            board_instance= new StandardBoard(dynamic_cast<Collection_standard&>(g));

        Collection_harbor *pt2 = dynamic_cast<Collection_harbor*>(&g);
        if (pt2)
            board_instance =new HarborBoard(dynamic_cast<Collection_harbor&>(g));

        Collection_GreenValley* pt3 = dynamic_cast<Collection_GreenValley*>(&g);
        if (pt3)
            board_instance= new GreenValleyBoard(dynamic_cast<Collection_GreenValley&>(g));

        Collection_deluxe* pt4 = dynamic_cast<Collection_deluxe*>(&g);
        if (pt4)
            board_instance = new DeluxeBoard(dynamic_cast<Collection_deluxe&>(g));
    }
    return board_instance;
}


