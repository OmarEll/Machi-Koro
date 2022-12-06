
#include <map>
#include <vector>
#include "../Card/Card.hpp"

class  Card;
using namespace std;
class Hand{
private:
    map<Card,size_t> establishments;
    map<LandmarksNames,Card> landmarks;
public:
    Hand(Expansions myExpansion);
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

