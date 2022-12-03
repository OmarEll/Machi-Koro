#include <map>
#include <vector>
#include "../Card.hpp"
#include "Enums.hpp"
#include "../UTILS/Enums.hpp"
using namespace std;
class Hand{
private:
    map<Card,size_t> establishments;
    vector<Card> landmarks;
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
    vector <Card> GetLandmarks() {return landmarks;}
    ~Hand();
   };
