
#include <map>
#include <vector>
#include "../Card/Card.hpp"

class  Establishment;
class Landmark;


using namespace std;

class Hand{
private:
    map<Establishment*,size_t> establishments;
    map<LandmarksNames,Landmark*> landmarks;
public:
    Hand(Expansions myExpansion);
    void addEstablishment(Establishment*);
    void removeEstablishment(Establishment*);
    vector<Establishment*> getColorCards(Colors);
    map<LandmarksNames, Landmark*> getLandmarks() const {return landmarks;}
    ~Hand();
   };

