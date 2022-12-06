<<<<<<< Updated upstream

#include <map>
#include <vector>
#include "../Card.hpp"

class  Card;
=======
#include "../Card.hpp"
#include "../UTILS/Enums.hpp"
#include <map>
#include <vector>

>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
    void activateColorCards(Colors);
    map<LandmarksNames, Card> getLandmarks() const {return landmarks;}
=======
    vector<Card> getLandmarks();
    void activateColorCards(Color);
    vector <Card> GetLandmarks() {return landmarks;}
>>>>>>> Stashed changes
    ~Hand();
   };

