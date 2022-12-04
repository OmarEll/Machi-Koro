#ifndef MACHIKORO_FICHIER_HAND_H
#define MACHIKORO_FICHIER_HAND_H

#include <map>
#include <vector>
#include "../Card.hpp"

using namespace std;
class Hand{
private:
    map<Card,size_t> establishments;
    map<LandmarksNames,Card> landmarks;
public:
    Hand();
    void addEstablishment(Card);
    void addLandmark(Card);
    void removeEstablishment(Card);
    vector<Card> getRedCards();
    vector<Card> getGreenCards();
    vector<Card> getPurpleCards();
    vector<Card> getBlueCards();
    void activateColorCards(Colors);
    map<LandmarksNames, Card> getLandmarks() const {return landmarks;}
    ~Hand();
   };

#endif //MACHIKORO_FICHIER_HAND_H