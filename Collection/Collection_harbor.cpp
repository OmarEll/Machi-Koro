//
// Created by mabur on 20/12/2022.
//

#include "Collection_harbor.h"


Collection_harbor::Collection_harbor() : Collection_standard(){

    Establishment_Collection.push_back(new Establishment("Flower Garden","When the card's activation number of four is rolled by any player, the player with the card gets 1 coin from the bank on anyone's turn.",BLUE,2,Harbor,wheat,
                                                         vector<int>{4},BankOrigin,1));

    Establishment_Collection.push_back(new Establishment("Pizza Joint","When the card's activation number of 7 is rolled by any player other than the card owner, the card owner gets 1 coin from the player who rolled on anyone's turn.",RED,1,Harbor,coffee,
                                                         vector<int>{7},PlayerRolledDice,1));

    Establishment_Collection.push_back(new Establishment("Hamburger Stand","When the card's activation number of 8 is rolled, then the player who owns this card takes 1 coin from the player who rolled the dice.",RED,1,Harbor,coffee,
                                                         vector<int>{8},PlayerRolledDice,1));

    Establishment_Collection.push_back(new class MackerelBoat());

    Establishment_Collection.push_back(new class TunaBoat());

    Establishment_Collection.push_back(new class FlowerShop());

    Establishment_Collection.push_back(new class FoodWarehouse());

    Establishment_Collection.push_back(new class SushiBar());

    Establishment_Collection.push_back(new class Publisher());

    Establishment_Collection.push_back(new class TaxOffice());

    Landmark_Collection.push_back(new class CityHall());

    Landmark_Collection.push_back(new class HarborCard());

    Landmark_Collection.push_back(new class Airport());

}

Collection_harbor::~Collection_harbor() {
    for (auto Est : Establishment_Collection){
        free (Est);
    }
    for (auto Lan : Landmark_Collection){
        free (Lan);
    }

}