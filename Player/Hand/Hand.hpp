#ifndef HAND_H_INCLUDED
#define HAND_H_INCLUDED

#include <map>
#include <vector>
#include "../Card/Card.hpp"
#include "../Card/Establishment/Establishment.h"
#include "../Card/Landmark/Landmark.h"


class  Establishment;
class Landmark;


using namespace std;

class Hand{

private:
    map<EstablishmentsNames,stack<Establishment*>> establishments;
    map<LandmarksNames,Landmark*> landmarks;
public:
    friend class Establishment;
    Hand(Expansions myExpansion);
    void addEstablishment(EstablishmentsNames);
    void removeEstablishment(EstablishmentsNames);
    vector<Establishment*> getColorCards(Colors);
    vector<Establishment*> getTypeCards(Types);
    map<LandmarksNames, Landmark*> getLandmarks() const {return landmarks;}
    map<EstablishmentsNames,pair<Establishment*,size_t>> getEstablishments() const {return establishments;}
    //1 methode qui permet d'acceder à tout les noms des cartes qu'il y a dans la main
    //1 methode qui permet d'acceder à tout les types des cartes qu'il y a dans la main
    //1 methode qui permet d'acceder à toute les couleurs qu'il y a dans la main
    ~Hand();
   };

#endif //HAND_H_INCLUDED