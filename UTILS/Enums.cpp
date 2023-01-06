//
// Created by mabur on 20/12/2022.
//
#include "Enums.hpp"


template<> EnumParser<EstablishmentsNames>::EnumParser()
{
    enumMap["Tv Station"] = TvStation;
    enumMap["Wheat Field"] = WheatField;
    enumMap["Ranch"] = Ranch;
    enumMap["Livestock Farm"] = LivestockFarm;
    enumMap["Bakery"] = Bakery;
    enumMap["Cafe"] = Cafe;
    enumMap["Convenience Store"] = ConvenienceStore;
    enumMap["Forest"] = Forest;
    enumMap["Stadium"] = Stadium;
    enumMap["Office"] = Office;
    enumMap["Cheese Factory"] = CheeseFactory;
    enumMap["Furniture Factory"] = FurnitureFactory;
    enumMap["Mine"] = Mine;
    enumMap["Restaurant"] = Restaurant;
    enumMap["Apple Orchard"] = AppleOrchard;
    enumMap["Produce Market"] = ProduceMarket;
    enumMap["Flower Garden"] = FlowerGarden;
    enumMap["Mackerel Boat"] = MackerelBoat;
    enumMap["Tuna Boat"] = TunaBoat;
    enumMap["Flower Shop"] = FlowerShop;
    enumMap["Food Warehouse"] = FoodWarehouse;
    enumMap["Sushi Bar"] = SushiBar;
    enumMap["Pizza Joint"] = PizzaJoint;
    enumMap["Hamburger Stand"] = HamburgerStand;
    enumMap["Publisher"] = Publisher;
    enumMap["Tax Office"] = TaxOffice;
    enumMap["Diamine"] = Diamine;
    enumMap["International Exhibit Hall"] = InternationalExhibitHall;
    enumMap["Vineyard"] = Vineyard;
    enumMap["Family Restaurant"] = FamilyRestaurant;
    enumMap["Tech Startup"] =TechStartup;
    enumMap["Corn Field"] = CornField;
    enumMap["General Store"] = GeneralStore;
    enumMap["Moving Company"] = MovingCompany;
    enumMap["Loan Office"] = LoanOffice;
    enumMap["Demolition Company"] = DemolitionCompany;
    enumMap["Soda Bottling Plant"] =SodaBottlingPlant;
    enumMap["French Restaurant"] = FrenchRestaurant;
    enumMap["Members Only Club"] = MembersOnlyClub;
    enumMap["Park"] = Park;
    enumMap["Renovation Company"] = RenovationCompany;
    enumMap["Winery"] = Winery;
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
    enumMap["Moon Tower"]= MoonTower;
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
