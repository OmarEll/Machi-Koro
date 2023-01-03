#pragma once
#include <string>
#include <map>
#include <iostream>

using namespace std;

enum Colors{
    RED,
    BLUE,
    PURPLE,
    GREEN
};
enum Level{
    Easy,
    Medium,
    Hard
};
enum LandmarksNames{
    RadioTower,TrainStation,ShoppingMall,AmusementPark, CityHall, HarborCard, Airport, harbor, MoonTower
};
enum EstablishmentsNames{
    WheatField, LivestockFarm, Bakery, Cafe, ConvenienceStore, Forest, Stadium, TvStation, Office, CheeseFactory,
    FurnitureFactory, Mine, Restaurant, AppleOrchard, ProduceMarket, FlowerGarden, MackerelBoat, TunaBoat, FlowerShop,
    FoodWarehouse, SushiBar, PizzaJoint, HamburgerStand, Publisher, TaxOffice, Diamine, InternationalExhibitHall,
    Vineyard, Ranch, FamilyRestaurant
};

enum Expansions{
    Standard, Harbor, GreenValley, Deluxe
};

enum OriginsOfCoins{
    BankOrigin,PlayerRolledDice,OtherPlayers
};

enum Types{
    wheat, cow, bread, coffee, wheel, tower, factory, apple, boat, suitcase
};

template <typename T> class EnumParser{
    map <string, T> enumMap;
public:
    EnumParser();

    T ParseSomeEnum(const string &value)
    {
        auto iValue = enumMap.find(value);
        if (iValue  == enumMap.end()) {
            throw std::exception();
        }
        return iValue->second;
    }
};

template<> EnumParser<EstablishmentsNames>::EnumParser();
template<> EnumParser<LandmarksNames>::EnumParser();
