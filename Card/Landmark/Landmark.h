//
// Created by Omar Elloumi on 08/12/2022.
//

#ifndef MACHI_KORO_LANDMARK_H
#define MACHI_KORO_LANDMARK_H

#include "../Card.hpp"

class Card;

//Déclaration des landmarks

class Landmark : public Card {
protected:
    bool constructed;
public:
    Landmark(string name, string desc, int cos, Expansions exp):Card( name,  desc, cos,  exp),constructed(false){}
    bool isConstructed() const {return constructed;};
    void setConstruction() { constructed=true; }
};

//Landmark STANDARD
class TrainStation : public Landmark {
public:
    TrainStation(): Landmark("Train Station","You may roll 1 or 2 dice.",4,Standard){}
    void Card::launchEffect(Game g,Player& currentPlayer) override;
    //You may roll 1 or 2 dice
};

class ShoppingMall : public Landmark {
public:
    ShoppingMall(): Landmark("Shopping Mall", "Your 'coffee cup' and 'bread toast' establishments earn +1 coin when activated", 10, Standard){}
    void Card::launchEffect(Game g,Player& currentPlayer) override;
    //Every time you collect for one of your buildings containing a 'coffee cup' symbol or the 'bread' symbol, you gain extra coins.
};

class AmusementPark : public Landmark {
public:
    AmusementPark(): Landmark("Amusement Park", "If you roll doubles, take another turn after this one.",16,Standard){}
    void launchEffect(Game g,Player& currentPlayer) override;
    //If you roll doubles, take another turn after this one.
};

class RadioTower : public Landmark {
public:
    RadioTower(): Landmark("Radio Tower", "Once every turn, you can choose to re-roll your dice.",22,Standard){}
    void launchEffect(Game g,Player& currentPlayer) override;
    //Once every turn, you can choose to re-roll your dice
};

//Landmark HARBOR

class CityHall : public Landmark {
public:
    CityHall(): Landmark("City Hall", "Immediately before buying establishments, if you have 0 coins, get 1 from the bank.",0,Harbor){}
    void launchEffect(Game g,Player& currentPlayer) override;
    //Immediately before buying establishments, if you have 0 coins, get 1 from the bank.
};

class Harbor : public Landmark {
public:
    Harbor(): Landmark("Harbor","If the dice total is 10 or more, you may add 2 to the total, on your turn only.",2,Harbor){}
    void launchEffect(Game g,Player& currentPlayer) override;
    //If the dice total is 10 or more, you may add 2 to the total, on your turn only.
};

class Airport : public Landmark {
public:
    Airport():Landmark("Airport","If you build nothing on your turn, you get 10 coins from the bank.",30,Harbor){}
    void launchEffect(Game g,Player& currentPlayer) override;
    //If you build nothing on your turn, you get 10 coins from the bank.
};

#endif //MACHI_KORO_LANDMARK_H
