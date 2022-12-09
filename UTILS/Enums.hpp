#ifndef MACHIKORO_FICHIER_ENUMS_H
#define MACHIKORO_FICHIER_ENUMS_H

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
enum Expansions{
    Standard, Harbor, GreenValley, Deluxe
};

enum OriginsOfCoins{
    Bank,PlayerRolledDice,OtherPlayers
};

enum Types{
    wheat, cow, bread, coffee, wheel, tower, factory, apple, boat
};

#endif //MACHIKORO_FICHIER_ENUMS_H
