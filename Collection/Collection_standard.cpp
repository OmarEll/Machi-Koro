//
// Created by mabur on 20/12/2022.
//

#include "Collection_standard.h"
#include "Card.hpp"
#include "Landmark.h"
#include "Establishment.h"
#include "Enums.hpp"


void Collection_standard::Clone(vector<Establishment *>, vector<Landmark *>) {


}

Collection_standard::Collection_standard() {
    Establishment_Collection.push_back(new Establishment("Wheat Field","You get 1 coin from the bank, on anyone's turn",BLUE,1,Standard,wheat,
                                                           vector<int>{1},BankOrigin,1));
    Establishment_Collection.push_back(new Establishment("Ranch","Get one coin from the bank on anyone's turn",BLUE,1,Standard,cow,
                                                         vector<int>{2},BankOrigin,1));
    Establishment_Collection.push_back(new Establishment("Forest","Get 1 coin from the bank, on anyone's turn",BLUE,3,Standard,wheel,
                                       vector<int>{5},BankOrigin,1));
    Establishment_Collection.push_back(new Establishment("Mine","Get 5 coins from the bank, on anyone's turn.",BLUE,6,Standard,wheel,
                                                         vector<int>{9},BankOrigin,5));
    Establishment_Collection.push_back(new Establishment("Apple Orchard","Get 3 coins from the bank, on anyone's turn.",BLUE,3,Standard,wheat,
                                                         vector<int>{10},BankOrigin,3));
    Establishment_Collection.push_back(new Establishment("Bakery","When the card's activation numbers of two or three are rolled by the player with the card, the player with the card gets one coin from the bank",GREEN,1,Standard,bread,
                                                         vector<int>{2,3},BankOrigin,1));
    Establishment_Collection.push_back(new Establishment("Convenience Store","When the card's activation number of 4 is rolled by the player with the card, the player with the card gets 3 coins from the bank",GREEN,2,Standard,bread,
                                                         vector<int>{4},BankOrigin,3));
    //Establishment_Collection.push_back(new CheeseFactory());
}
