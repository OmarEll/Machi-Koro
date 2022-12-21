//
// Created by sarah on 21/12/2022.
//
#include <stack>
#include "HarborBoard.h"


/*
5x Airport
5x Harbor
5x City Hall
6x Flower Garden
6x Mackerel Boat
6x Tuna Boat
6x Flower Shop
6x Food Warehouse
6x Hamburger Stand
6x Pizza Joint
6x Sushi Bar
5x Publisher
5x Tax Office
 */

HarborBoard::HarborBoard(int nb, map<EstablishmentsNames,stack<Establishment*>> cards):Board() {
        setNbCardsMax(nb);   // inutile dans le standard non?
        // a faire quand on a les méthodes de board
    }
