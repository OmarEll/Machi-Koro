//
// Created by mabur on 20/12/2022.
//

#include "Collection_standard.h"
#include "Card.hpp"
#include "Landmark.h"
#include "../Establishment/Establishment.h"
#include "Enums.hpp"


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
    Establishment_Collection.push_back(new class CheeseFactory());

    Establishment_Collection.push_back(new class FurnitureFactory());

    Establishment_Collection.push_back(new class ProduceMarket());

    Establishment_Collection.push_back(new Establishment("Cafe","Get 1 coin from the player who rolled the dice",RED,2,Standard,coffee,
                                                         vector<int>{3},PlayerRolledDice,1));
    Establishment_Collection.push_back(new Establishment("Family Restaurant","Get 2 coins from the player who rolled the dice",RED,3,Standard,coffee,
                                                         vector<int>{9,10},PlayerRolledDice,2));
    Establishment_Collection.push_back(new class Stadium());

    Establishment_Collection.push_back(new class TvStation());

    Establishment_Collection.push_back(new class Office());

    Landmark_Collection.push_back(new class TrainStation());

    Landmark_Collection.push_back(new class ShoppingMall());

    Landmark_Collection.push_back(new class AmusementPark());

    Landmark_Collection.push_back(new class RadioTower());
}

Collection_standard::~Collection_standard() {
    for (auto Est : Establishment_Collection){
        delete (Est);
    }
    for (auto Lan : Landmark_Collection){
        delete (Lan);
    }


}


