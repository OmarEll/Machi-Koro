#pragma once
#include <map>
#include <vector>
#include <stack>
//-------------
#include "../UTILS/Enums.hpp"
#include "../Collection/Collection_standard.h"

class  Establishment;
class Landmark;

using namespace std;

class Hand{

private:
    map<EstablishmentsNames,stack<Establishment*> > establishments;
    map<LandmarksNames,Landmark*> landmarks;
public:
    friend class Establishment;
    Hand(Collection_standard&);
    void addEstablishment(Establishment*, Player&);
    void removeEstablishment(Establishment*);
    void addLandmark(LandmarksNames name);

    /* GETTERS & SETTERS */
    vector<Establishment*> getColorCards(Colors);
    vector<Establishment*> getTypeCards(Types);
    map<LandmarksNames, Landmark*> getLandmarks() const {return landmarks;}
    map<EstablishmentsNames,stack<Establishment*>> getEstablishments() const {return establishments;}
    ~Hand() = default;
};

