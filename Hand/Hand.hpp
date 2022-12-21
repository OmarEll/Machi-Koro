#include "Player.hpp"
#include "Card.hpp"
#include <map>
#include <vector>
#include "Enums.hpp"
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
    void activateColorCards(Color);
    vector <Card> GetLandmarks() {return landmarks;}
    ~Hand();
   };
