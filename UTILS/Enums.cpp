//
// Created by mabur on 20/12/2022.
//
#include "Enums.hpp"

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

template<> EnumParser<LandmarksNames>::EnumParser()
{
    enumMap["Radio Tower"] = RadioTower;
    enumMap["Train Station"] = TrainStation;
    enumMap["Shopping Mall"] = ShoppingMall;
    enumMap["Amusement Park"] = AmusementPark;
    enumMap["City Hall"] = CityHall;
    enumMap["Harbor Card"] = HarborCard;
    enumMap["Airport"] = Airport;
}
std::string getExpansionName(Expansions expansion)
{
    switch (expansion) {
        case Standard: return "Standard";
        case Harbor: return "Harbor";
        case GreenValley: return "Green Valley";
        case Deluxe: return "Deluxe";
        default: return "Unknown";
    }
}
