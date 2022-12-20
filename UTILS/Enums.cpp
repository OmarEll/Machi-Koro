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