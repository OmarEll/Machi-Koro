//
// Created by Omar Elloumi on 04/12/2022.
//
#include "Hand.hpp"

Hand::Hand(Expansions myExpansion){
    switch (myExpansion) {
        case Standard:
            //establishments : add bakery + wheat field
            //landmarks: Train Station, Shopping Mall, Amusement Park & Radio Tower – face down (Under Construction).
            break;
        case Harbor:
            //establishments : add bakery + wheat field
            //landmarks: city hall (already built), harbor, airport, Train Station, Shopping Mall, Amusement Park & Radio Tower
            break;
        case GreenValley:
            //establishments : add bakery + wheat field
            //landmarks: Train Station, Shopping Mall, Amusement Park & Radio Tower – face down (Under Construction).
            break;
        case Deluxe:
            //landmarks: Train Station, Shopping Mall, Amusement Park & Radio Tower – face down (Under Construction).
            break;
        default:break;
    }
}
