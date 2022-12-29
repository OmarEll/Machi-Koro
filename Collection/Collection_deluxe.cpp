//
// Created by sarah on 29/12/2022.
//

#include "Collection_deluxe.h"

Collection_deluxe::Collection_deluxe() {
    Establishment_Collection.push_back(new class CornField());
    Establishment_Collection.push_back(new class Vineyard());
    Establishment_Collection.push_back(new class GeneralStore());
    Establishment_Collection.push_back(new class MovingCompany());
    Establishment_Collection.push_back(new class LoanOffice());
    Establishment_Collection.push_back(new class Winery());
    Establishment_Collection.push_back(new class DemolitionCompany());
    Establishment_Collection.push_back(new class SodaBottlingPlant());
    Establishment_Collection.push_back(new class FrenchRestaurant());
    Establishment_Collection.push_back(new class MembersOnlyClub());
    Establishment_Collection.push_back(new class Park());
    Establishment_Collection.push_back(new class RenovationCompany());
    Establishment_Collection.push_back(new class TechStartup());
    Establishment_Collection.push_back(new class InternationalExhibitHall());
}
