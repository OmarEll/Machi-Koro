#ifndef MACHIKORO_FICHIER_ENUMS_H
#define MACHIKORO_FICHIER_ENUMS_H
#include <string>
#include <map>
using namespace std;

template <typename T> class EnumParser{
    map <string, T> enumMap;
public:
    EnumParser(){};

    T ParseSomeEnum(const string &value)
    {
        auto iValue = enumMap.find(value);
        if (iValue  == enumMap.end())
            throw runtime_error("");
        return iValue->second;
    }
};

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
    RadioTower,TrainStation,ShoppingMall,AmusementPark, CityHall, HarborCard, Airport
};
enum EstablishmentsNames{
    WheatField, LivestockFarm, Bakery, Cafe, ConvenienceStore, Forest, Stadium, TvStation, Office, CheeseFactory,
    FurnitureFactory, Mine, Restaurant, AppleOrchard, ProduceMarket, FlowerGarden, MackerelBoat, TunaBoat, FlowerShop,
    FoodWarehouse, SushiBar, PizzaJoint, HamburgerStand, Publisher, TaxOffice, Diamine, InternationalExhibitHall
};
template<> EnumParser<EstablishmentsNames>::EnumParser()
{
    enumMap["Wheat Field"] = WheatField;
    enumMap["Livestock Farm"] = LivestockFarm;
    enumMap["Bakery"] = Bakery;
    enumMap["Cafe"] = Cafe;
    enumMap["Convenience Store"] = ConvenienceStore;
    enumMap["Forest"] = Forest;
    enumMap["Stadium"] = Stadium;
}
enum Expansions{
    Standard, Harbor, GreenValley, Deluxe
};

enum OriginsOfCoins{
    BankOrigin,PlayerRolledDice,OtherPlayers
};

enum Types{
    wheat, cow, bread, coffee, wheel, tower, factory, apple, boat
};


#endif //MACHIKORO_FICHIER_ENUMS_H
