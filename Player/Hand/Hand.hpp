
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
    vector<Establishment*> getTypeCards(Types);
    map<LandmarksNames, Landmark*> getLandmarks() const {return landmarks;}
    map<Establishment*, size_t> getEstablishments() const {return establishments;}
    //1 methode qui permet d'acceder à tout les noms des cartes qu'il y a dans la main
    //1 methode qui permet d'acceder à tout les types des cartes qu'il y a dans la main
    //1 methode qui permet d'acceder à toute les couleurs qu'il y a dans la main
    ~Hand();
   };