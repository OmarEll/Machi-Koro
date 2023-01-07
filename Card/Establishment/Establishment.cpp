#include "Establishment.h"
#include "../Player/Player.hpp"
#include "../Game/Game.h"
#include "../../UTILS/Enums.hpp"
#include "../Dice/Dice.h"
#include "GreenValleyBoard.h"
#include "Bank.hpp"
#include "Landmark.h"
#include "Enums.hpp"
#include <ostream>
#include <string>

bool Establishment::activate(int diceRolled){

    for(auto activationNumber : activationNumbers) {
        if (activationNumber == diceRolled)
            return true;
    }
    return false;
}


/* Definition de l'effet de base d'un etablissement (recevoir de l'argent de la banque ou d'un joueur) */

void Establishment::launchEffect(Game& g,Player& currentPlayer) { //ne gère pas les cartes violette, a gerer dans des classes filles spécifiques
    int id_Owner=getOwner()->getId();
    if (getOrigin() == BankOrigin && Card::getOwner()!=nullptr)
        g.getBank()->withdraw(id_Owner,getEarnedCoins());

    int id_current=currentPlayer.getId();
    int balance_current=g.getBank()->getBalance(id_current);
    if ((getOrigin() == PlayerRolledDice) && getOwner()!=nullptr) { //on va prendre des coins du joueur qui a lancé le dé et le donner à celui qui possède cette carte
        if (balance_current >= getEarnedCoins()) { //le joueur qui doit payer a assez de coins pour payer
            g.getBank()->playerPaysPlayer(id_current, id_Owner, getEarnedCoins());
        } else {                                    //le joueur qui doit payer n'a pas assez de coins pour payer donc il donne ce qu'il a
            g.getBank()->playerPaysPlayer(id_current, id_Owner, balance_current);
        }
    }
}

/* Definition de méthodes qui permetterons de redefinir des effets pour plusieurs cartes */

int Establishment::numberGainWithType(Player& currentPlayer, vector<Types> t) const{  //fonction à utiliser pour les cartes comme cheese factory
    // ici on calcule le nb de cartes d'un certain type que possède un joueur et on le multiplie par le gain de la carte
    int nb = getEarnedCoins();
    int sum=0;
    if(getOrigin()==BankOrigin){
        for (auto& it : t){
            sum += getOwner()->getHand()->getTypeCards(it).size();
        }
    }
    else{
        for (auto& it : t){
            sum += currentPlayer.getHand()->getTypeCards(it).size();
        }
    }
    return sum*nb;
}

bool Establishment::hasHarbor(){ //fonction qui permet de regarder si le joueur propriétaire de la carte possède un Harbor dans sa main
    //utilisée pour les effets avec "If you have a harbor"
    return getOwner()->hasLandmark(HarborCard) != nullptr;
}

int Establishment::numberOfLandmarks(Player* p){
    return p->getHand()->getLandmarks().size();
};

int Establishment::numberOfLandmarks(Player& p){
    return p.getHand()->getLandmarks().size();
}

Establishment *Establishment::Clone() {
    Establishment* res = new Establishment();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
};


/* Redefinition des effets des cartes violettes standard */

void Stadium::launchEffect(Game& g, Player& currentPlayer){ //méthode redefinie pour permettre de recevoir des coins de la part de l'ensemble des adversaires
    int id_Owner=getOwner()->getId();
    int coinsEarned = 0;
    for (const auto& other_player : g.getPlayers()){
        int id_other = other_player->getId();
        if (id_Owner != id_other){
            int balance_other=g.getBank()->getBalance(id_other);
            if ((getOrigin() == OtherPlayers) && getOwner()!=nullptr) { //on va prendre les coins des joueurs adverse et le donner à celui qui possède cette carte (qui est aussi le current_player)
                if (balance_other >= getEarnedCoins()) { //le joueur qui doit payer a assez de coins pour payer
                    g.getBank()->playerPaysPlayer(id_other, id_Owner, getEarnedCoins());
                    coinsEarned = coinsEarned + getEarnedCoins();
                } else {                                    //le joueur qui doit payer n'a pas assez de coins pour payer donc il donne ce qu'il a
                    g.getBank()->playerPaysPlayer(id_other, id_Owner, balance_other);
                    coinsEarned = coinsEarned + balance_other;
                }
            }
        }
    }
    cout << currentPlayer.getName() << " gagne " << coinsEarned << " coins grace a Stadium"<< endl;
}

class Stadium* Stadium::Clone() {
    Stadium* res = new Stadium();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void TvStation::launchEffect(Game& g, Player& currentPlayer){ //méthode redefinie pour permettre de choisir l'adversaire qui donne les coins au propriétaire de la carte (automatique si 2 joueurs)
    string nameOfPayer;
    int id_payer = -1;
    int balance_payer = 0;
    int id_Owner=getOwner()->getId();
    while (id_payer==-1){
        cout<<"Choississez le joueur qui doit vous payer :\n";
        for (const auto& other_player : g.getPlayers()){
            if (other_player->getName() != currentPlayer.getName()){
                cout<<other_player->getName()<<" "; //affiche la liste des joueurs adverses
            }
        }
        cout<<"\n";
        ::fflush(stdin);
        getline(cin,nameOfPayer);

        for (const auto& other_player : g.getPlayers()){
            if(nameOfPayer==other_player->getName()){
                id_payer = other_player->getId();
            }
        }
    }
    balance_payer = g.getBank()->getBalance(id_payer);
    int earnedCoins = 0;
    if (balance_payer >= getEarnedCoins()) { //le joueur qui doit payer a assez de coins pour payer
        g.getBank()->playerPaysPlayer(id_payer, id_Owner, getEarnedCoins());
        earnedCoins = getEarnedCoins();
    } else {                                    //le joueur qui doit payer n'a pas assez de coins pour payer donc il donne ce qu'il a
        g.getBank()->playerPaysPlayer(id_payer, id_Owner, balance_payer);
        earnedCoins = balance_payer;
    }
    cout << currentPlayer.getName() << " gagne " << earnedCoins << " coins grace a Tv Station"<< endl;
}

class TvStation *TvStation::Clone() {
    TvStation* res = new TvStation();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}


void Office::launchEffect(Game& g, Player& currentPlayer){ //echange une carte avec un autre joueur sauf de type tower (ie.les cartes violettes)
    Establishment* CardExchanger= nullptr;
    Establishment* CardOwner= nullptr;
    Player* playerExchanger= nullptr;
    string nameOfExchanger;
    string nameOfCardExchanger;
    string nameOfCardOwner;
    while (playerExchanger == nullptr){
        cout<<"Entrez le nom du joueur avec qui vous voulez echanger une carte :\n";
        ::fflush(stdin);
        getline(cin,nameOfExchanger);
        for ( auto& other_player : g.getPlayers()){
            if(nameOfExchanger==other_player->getName() && nameOfExchanger != owner->getName()){
                playerExchanger = other_player;
            }
        }
        if (playerExchanger == nullptr){
            cout << "Le nom du joueur n'existe pas ou c'est vous meme et vous ne pouvez pas echanger de carte avec vous meme" << endl;
        }
    }

    while (CardOwner== nullptr) {
        cout<<"Entrez le nom de la carte que vous souhaitez donner (elle ne doit pas etre de type tower) :\n";
        ::fflush(stdin);
        getline(cin,nameOfCardOwner);
        //Owner
        CardOwner = nullptr;
        for (const auto &card: currentPlayer.getHand()->getEstablishments()) { // On verifie que la carte choisi est dans la main du joueur et qu'elle n'est pas de type tower
            Establishment *est = (getOwner()->getHand()->getEstablishments()[card.first].top());
            if ((nameOfCardOwner == est->getCardName()) && (est->getType() != tower)) {
                CardOwner = est;
            }
        }
        if (CardOwner == nullptr){
            cout << "1. La carte n'est pas dans votre main ou est de type tower" << endl;
        }
    }

    while (CardExchanger== nullptr) {
        cout << "Entrez le nom de la carte que vous souhaitez recuperer (elle ne doit pas etre de type tower) :\n";
        ::fflush(stdin);
        getline(cin,nameOfCardExchanger);
        //Exchanger
        /*
        EnumParser<EstablishmentsNames> fieldTypeParser;
        EstablishmentsNames val = fieldTypeParser.ParseSomeEnum(nameOfCardExchanger);
        Establishment* tmp = nullptr;
        for (auto establishment : cards){
            if (val == establishment.first){
                tmp = establishment.second.top();
                this->cards[val].pop();
                return tmp;
            }
        }
        return nullptr;
        */
        CardExchanger=nullptr;
        for (const auto&  card : playerExchanger->getHand()->getEstablishments()){ // On verifie que la carte choisi est dans la main du joueur et qu'elle n'est pas de type tower
            Establishment* est= (playerExchanger->getHand()->getEstablishments()[card.first].top());
            if((nameOfCardExchanger==est->getCardName()) && (est->getType()!=tower) ){
                CardExchanger=est;
            }
        }
        if (CardExchanger == nullptr) {
            cout << "2. La carte n'est pas dans la main de" << playerExchanger->getName() << "ou est de type tower" << endl;
        }
    }
    //add
    currentPlayer.getHand()->addEstablishment(CardExchanger,currentPlayer);
    playerExchanger->getHand()->addEstablishment(CardOwner,*playerExchanger);
    //remove
    currentPlayer.getHand()->removeEstablishment(CardOwner);
    playerExchanger->getHand()->removeEstablishment(CardExchanger);
    cout<< currentPlayer.getName()<<" a echange sa carte " << CardOwner->getCardName() << " avec la carte " << CardExchanger->getCardName() << " de " << playerExchanger->getName() <<endl;
}

class Office *Office::Clone() {
    Office* res = new Office();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}


/* Redefinition des establishments avec un effet de type "For each of your 'type' establishments, gain x coins"*/
//Standard
void CheeseFactory::launchEffect(Game& g, Player& currentPlayer){
    setNumberOfCoinsEarned(numberGainWithType(currentPlayer, {cow}));
    Establishment::launchEffect(g, currentPlayer);
    cout << currentPlayer.getName() << " gagne " << getEarnedCoins() << " coins grace a "<< getCardName() << endl;
}

class CheeseFactory *CheeseFactory::Clone() {
    CheeseFactory* res = new CheeseFactory();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void FurnitureFactory::launchEffect(Game& g, Player& currentPlayer){
    setNumberOfCoinsEarned(numberGainWithType(currentPlayer, {wheel}));
    Establishment::launchEffect(g, currentPlayer);
    cout << currentPlayer.getName() << " gagne " << getEarnedCoins() << " coins grace a "<< getCardName() << endl;
}

class FurnitureFactory *FurnitureFactory::Clone() {
    FurnitureFactory* res = new FurnitureFactory();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void ProduceMarket::launchEffect(Game& g, Player& currentPlayer){
    setNumberOfCoinsEarned(numberGainWithType(currentPlayer, {wheat}));
    Establishment::launchEffect(g, currentPlayer);
    cout << currentPlayer.getName() << " gagne " << getEarnedCoins() << " coins grace a "<< getCardName() << endl;
}

class ProduceMarket *ProduceMarket::Clone() {
    ProduceMarket* res = new ProduceMarket();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

//Harbor
void FoodWarehouse::launchEffect(Game& g, Player& currentPlayer){
    setNumberOfCoinsEarned(numberGainWithType(currentPlayer, {coffee}));
    Establishment::launchEffect(g, currentPlayer);
    cout << currentPlayer.getName() << " gagne " << getEarnedCoins() << " coins grace a "<< getCardName() << endl;
}

class FoodWarehouse *FoodWarehouse::Clone() {
    FoodWarehouse* res = new FoodWarehouse();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void FlowerShop::launchEffect(Game& g, Player& currentPlayer){
    //Get 1 coin from the bank for each Flower Garden you own, on your turn only.
    auto establishments=getOwner()->getHand()->getEstablishments();
    if (getOwner()->getHand()->getEstablishments().find(FlowerGarden)!=getOwner()->getHand()->getEstablishments().end()){
        setNumberOfCoinsEarned(getOwner()->getHand()->getEstablishments()[FlowerGarden].size()); //Le nombre de coins gagné est le nombre de flower garden possédé
    }
    else {
        setNumberOfCoinsEarned(0); //Le joueur ne possède pas de flower garden
    }
    g.getBank()->withdraw(getOwner()->getId(), getEarnedCoins());
}

class FlowerShop *FlowerShop::Clone() {
    FlowerShop* res = new FlowerShop();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

/* Redefinition des establishments avec un effet de type "If you have a Harbor, gain x coins"*/
void MackerelBoat::launchEffect(Game& g, Player& currentPlayer){
    if (hasHarbor()) {
        cout << currentPlayer.getName() << " gagne " << getEarnedCoins()<< " coins grace a " << getCardName()<< endl;
        Establishment::launchEffect(g, currentPlayer);
    }
    else{
        cout << currentPlayer.getName() << " ne possedant pas de Harbor Card, iel ne gagne pas de coins avec " << getCardName() <<endl;
    };
}

class MackerelBoat *MackerelBoat::Clone() {
    MackerelBoat* res = new MackerelBoat();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void SushiBar::launchEffect(Game& g, Player& currentPlayer){
    if (hasHarbor()) {
        int balance_current= g.getBank()->getBalance(currentPlayer.getId());
        if (balance_current >= getEarnedCoins()) { //le joueur qui doit payer a assez de coins pour payer
            cout << getOwner()->getName() << " recoit " << getEarnedCoins() << " de " << currentPlayer.getName() << " par " << getCardName() << endl;
        } else {                                    //le joueur qui doit payer n'a pas assez de coins pour payer donc il donne ce qu'il a
            cout << getOwner()->getName() << " recoit uniquement " << balance_current << " de " << currentPlayer.getName() << " par " << getCardName() << " parce que ce joueur n'a pas assee pour payer entierement" << endl;
        }
        Establishment::launchEffect(g, currentPlayer);
    }
    else{
        cout << currentPlayer.getName() << " ne possedant pas de Harbor Card, iel ne gagne pas de coins avec " << getCardName() <<endl;
    };
}

class SushiBar *SushiBar::Clone() {
    SushiBar* res = new SushiBar();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void TunaBoat::launchEffect(Game& g, Player& currentPlayer){
    //On anyone's turn: The current player rolls 2 dice. If you have a harbor you get as many coins as the dice total.
    list<Dice> tab = g.GetDices();
    setNumberOfCoinsEarned( tab.front().GetResult() + tab.back().GetResult());
    //if (hasHarbor() && tab.back().GetResult() != 0) Establishment::launchEffect(g, currentPlayer);

    if (hasHarbor()) {
        cout << currentPlayer.getName() << " gagne " << getEarnedCoins()<< " coins grace a " << getCardName()<< endl;
        Establishment::launchEffect(g, currentPlayer);
    }
    else{
        cout << currentPlayer.getName() << " ne possedant pas de Harbor Card, iel ne gagne pas de coins avec " << getCardName() <<endl;
    };
}

class TunaBoat *TunaBoat::Clone() {
    TunaBoat* res = new TunaBoat();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

/* Redéfinition des cartes violettes HARBOR */

void Publisher::launchEffect(Game& g, Player& currentPlayer){ //A REVOIR
    //Take 1 coins from each opponent for each 'coffee' and 'bread' type establishment they own
    int id_Owner=getOwner()->getId();
    for (auto& other_player : g.getPlayers()){
        int id_other = other_player->getId();
        if (id_Owner != id_other){
            int balance_other=g.getBank()->getBalance(id_other);
            if ((getOrigin() == OtherPlayers) && getOwner()!=nullptr) { //on va prendre les coins des joueurs adverse et le donner à celui qui possède cette carte (qui est aussi le current_player)
                setNumberOfCoinsEarned(numberGainWithType(*other_player, {coffee,bread})); //On definit le nombre de piece que le joueur adverse doit payer
                if (balance_other >= getEarnedCoins()) { //le joueur qui doit payer a assez de coins pour payer
                    g.getBank()->playerPaysPlayer(id_other, id_Owner, getEarnedCoins());
                    cout << getOwner()->getName() << " recoit " << getEarnedCoins() << " de " << other_player->getName() << " par " << getCardName() << endl;
                } else {                                    //le joueur qui doit payer n'a pas assez de coins pour payer donc il donne ce qu'il a
                    g.getBank()->playerPaysPlayer(id_other, id_Owner, balance_other);
                    cout << getOwner()->getName() << " recoit uniquement " << balance_other << " de " << other_player->getName() << " par " << getCardName() << " parce que ce joueur n'a pas assee pour payer entierement" << endl;
                }
            }
        }
    }
}

class Publisher *Publisher::Clone() {
    Publisher* res = new Publisher();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void TaxOffice::launchEffect(Game& g, Player& currentPlayer){
    //From each opponent with 10 or more coins: take half their coins, rounded down. This only applies in your turn.
    int id_Owner=getOwner()->getId();
    for (const auto& other_player : g.getPlayers()){
        int id_other = other_player->getId();
        if (id_Owner != id_other && g.getBank()->getBalance(id_other)>=10){ //le joueur possède au moins 10 coins
            int balance_other=g.getBank()->getBalance(id_other);
            g.getBank()->playerPaysPlayer(id_other, id_Owner, balance_other/2); //On prend la moitié de la balance arrondi à l'inférieur (le reste de la divison est ignorée)
            cout << getOwner()->getName() << " recoit " << g.getBank()->getBalance(id_other) << " de " << other_player->getName() << " par " << getCardName() << endl;
        }
    }

}

class TaxOffice *TaxOffice::Clone() {
    TaxOffice* res = new TaxOffice();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

/* Redéfinition des cartes violettes GREEN VALLEY */

void Park::launchEffect(Game& g, Player& currentPlayer) {
    //Redistribute all players' coins evenly among all players, on your turn only. If there is an uneven amount of coins, take coins from the bank to make up the difference.
    int total;
    int new_balance;

    for (const auto& all_player : g.getPlayers()){ //On calcul la somme de toutes les balances des joueurs
        total += g.getBank()->getBalance(all_player->getId());
    }

    if(total % g.getPlayers().size() == 0){ //On calcul quel va être la nouvelle balance de tout les joueurs
        new_balance = total/g.getPlayers().size();
    }
    else{
        new_balance = (total/g.getPlayers().size())+1; //si le modulo n'est pas egale a zero cela veux dire qu'il reste au moins une pièce et la banque complète pour tout le monde donc tout le monde a une pièce en plus
    }

    for (const auto& all_player : g.getPlayers()){ //On met à jour toutes les balances
        g.getBank()->setBalance(all_player->getId(), new_balance);
    }
}

class Park *Park::Clone() {
    Park* res = new Park();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void RenovationCompany::launchEffect(Game& g, Player& currentPlayer) {
    //Choose a non-tower type building. All buildings owned by any player of that type are closed for renovations.
    // Get 1 coin from each player for each of their buildings closed for renovation, on your turn only.
    string cardRenov;
    bool cardok=false;
    while (!cardok) {
        cout << "Entrez le nom de la carte que vous souhaitez mettre en rénovation (pas de type tower):\n";
        ::fflush(stdin);
        getline(cin,cardRenov);
        if(g.getEstablishmentByName(cardRenov)!= nullptr){
            if(g.getEstablishmentByName(cardRenov)->getType()!=tower)
                cardok= true;
            else{
                cout<<"\nErreur: choisir une carte d'un type non tower"<<endl;
            }
        }else{
            cout<<"\nErreur: verifiez l'orthographe de la carte tape"<<endl;
        }
    }
    EnumParser<EstablishmentsNames> fieldTypeParser;
    EstablishmentsNames val = fieldTypeParser.ParseSomeEnum(cardRenov);

    for (const auto& player : g.getPlayers()){
        if (player->hasEstablishment(cardRenov) != nullptr){
            stack <Establishment*> tmp = player->getHand()->getEstablishments().find(val)->second;
            while (!tmp.empty()){
                Establishment * card = tmp.top();
                if (!card->getRenovation()){
                    card->setRenovation(true);
                }
                tmp.pop();
            }
        }
    }
}

class RenovationCompany *RenovationCompany::Clone() {
    RenovationCompany* res = new RenovationCompany();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void TechStartup::launchEffect(Game& g, Player& currentPlayer) { //A Gerer dans game pour l'investissement
    //At the end of each of your turns, you may place 1 coin on this card. The total placed here is your investment. When activated, get an amount equal to your investment from all player, on your turn only.
    for(auto& player : g.getPlayers()){
        g.getBank()->playerPaysPlayer(player->getId(),currentPlayer.getId(),getEarnedCoins());
    }
}

class TechStartup *TechStartup::Clone() {
    TechStartup* res = new TechStartup();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void InternationalExhibitHall::launchEffect(Game& g, Player& currentPlayer) {
    //You may choose to activate another of your non tower type establishments in place of this one, on your turn only. If you do, return this card to the market.
    string cardAct;
    bool cardok=false;
    while (!cardok) {
        cout << "Entrez le nom de la carte que vous souhaitez activer (pas de type tower), ecrire 'non' pour ne rien faire:\n";
        ::fflush(stdin);
        getline(cin,cardAct);
        if (cardAct=="non") return;
        if(g.getEstablishmentByName(cardAct)!= nullptr){
            if(g.getEstablishmentByName(cardAct)->getType()!=tower)
                cardok= true;
            else{
                cout<<"\nErreur: choisir une carte d'un type non tower"<<endl;
            }
        }else{
            cout<<"\nErreur: verifiez l'orthographe de la carte tape"<<endl;
        }
    }
    Establishment* est=currentPlayer.hasEstablishment(cardAct);
    est->launchEffect(g,currentPlayer);
    currentPlayer.getHand()->removeEstablishment(est);
    GreenValleyBoard* board = dynamic_cast<GreenValleyBoard*>(g.getBoard());
    board->addEstablishmentToBoard(est);
}

class InternationalExhibitHall *InternationalExhibitHall::Clone() {
    InternationalExhibitHall* res = new InternationalExhibitHall();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

/* Redéfinition des cartes spéciales GREEN VALLEY */

void CornField::launchEffect(Game& g, Player& currentPlayer) {
    //If you have less than 2 landmarks built, get 1 coin from the bank
    if(getOwner()->getHand()->numberOfConstructedLandmarks()<2) {
        Establishment::launchEffect(g, currentPlayer);
        cout << currentPlayer.getName() << " gagne " << getEarnedCoins() << " coins grace a " << getCardName()<< endl;
    }
    else{
        cout << getCardName() << " ne permet pas de gagner de coins car " << getOwner()->getName() << " possedent au moins 2 landmarks" <<endl;
    }
}

class CornField *CornField::Clone() {
    CornField* res = new CornField();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void GeneralStore::launchEffect(Game& g, Player& currentPlayer) {
    //If you have less than 2 constructed landmarks, get 2 coins from the bank, on your turn only
    if(getOwner()->getHand()->numberOfConstructedLandmarks()<2) {
        Establishment::launchEffect(g, currentPlayer);
        cout << currentPlayer.getName() << " gagne " << getEarnedCoins() << " coins grace a " << getCardName()<< endl;
    }
    else{
        cout << getCardName() <<" ne permet pas de gagner de coins car " << getOwner()->getName() << " possedent au moins 2 landmarks" <<endl;
    }
}

class GeneralStore *GeneralStore::Clone() {
    GeneralStore* res = new GeneralStore();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void MembersOnlyClub::launchEffect(Game& g, Player& currentPlayer) {
    //If the player who rolled this number has 3 or more constructed landmarks, get all of their coins
    if(numberOfLandmarks(currentPlayer)>=3) {
        int id_current = currentPlayer.getId();
        int balance_current=g.getBank()->getBalance(id_current);
        g.getBank()->playerPaysPlayer(id_current, getOwner()->getId(), balance_current);
    };
}

class MembersOnlyClub *MembersOnlyClub::Clone() {
    MembersOnlyClub* res = new MembersOnlyClub();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void FrenchRestaurant::launchEffect(Game& g, Player& currentPlayer) {
    //If the player who rolled this number has 2 or more constructed landmarks, get 5 coins from the player who rolled the dice
    if(numberOfLandmarks(getOwner())<=2) {
        Establishment::launchEffect(g, currentPlayer);
    }
    else{
        cout << getCardName() <<" ne permet pas de gagner de coins car " << getOwner()->getName() << " possedent au moins 2 landmarks" <<endl;
    }
}

class FrenchRestaurant *FrenchRestaurant::Clone() {
    FrenchRestaurant* res = new FrenchRestaurant();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void SodaBottlingPlant::launchEffect(Game& g, Player& currentPlayer) {
    //Get 1 coin from the bank for each coffee type establishments owned by all players (on your turn only)
    int id_Owner=getOwner()->getId();
    int total = 0;
    for (auto& other_player : g.getPlayers()){
        total += numberGainWithType(*other_player, {coffee});
    }
    setNumberOfCoinsEarned(total);
    g.getBank()->withdraw(id_Owner,getEarnedCoins());
}

class SodaBottlingPlant *SodaBottlingPlant::Clone() {
    SodaBottlingPlant* res = new SodaBottlingPlant();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void DemolitionCompany::launchEffect(Game& g, Player& currentPlayer) {
    //Demolish 1 of your built landmarks (flip it back over). When you do, get 8 coins from the bank (your turn only)"
    string choice;
    LandmarksNames val;
    do {
        cout << "Quel monument voulez vous détruire ?" << endl;
        ::fflush(stdin);
        getline(cin,choice);
        EnumParser<LandmarksNames> fieldTypeParser;
        val = fieldTypeParser.ParseSomeEnum(choice);
    } while (!getOwner()->hasLandmark(val));
    Landmark* land_;
    for (auto Land : getOwner()->getHand()->getLandmarks()){
        if (Land.first == val)
            land_ = Land.second;
    }
    land_->setDemolition();
    g.getBank()->withdraw(getOwner()->getId(),getEarnedCoins());
}

class DemolitionCompany *DemolitionCompany::Clone() {
    DemolitionCompany* res = new DemolitionCompany();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void MovingCompany::launchEffect(Game& g, Player& currentPlayer) {
    //You must give a non-tower type building that you own to another player. When you do so, get 4 coins from the bank, on your turn only
    Establishment* CardGiver= nullptr;
    Player* playerReceiver= nullptr;
    string nameOfReceiver;
    string nameOfCardReciver;
    string nameOfCardGiver;
    while (playerReceiver == nullptr || nameOfReceiver==getOwner()->getName()){
        cout<<"Entrez le nom du joueur a qui voulez vous donner votre carte :\n";
        ::fflush(stdin);
        getline(cin, nameOfReceiver);
        for ( auto& other_player : g.getPlayers()){
            if(nameOfReceiver==other_player->getName()){
                playerReceiver = other_player;
            }
        }
    }

    while (CardGiver== nullptr){

        cout<<"Entrez le nom de la carte que vous souhaitez donner (elle ne doit pas etre de type tower) :\n";
        ::fflush(stdin);
        getline(cin, nameOfCardGiver);

        //Giver
        for (const auto&  card : currentPlayer.getHand()->getEstablishments()){ // On verifie que la carte choisi est dans la main du joueur et qu'elle n'est pas de type tower
            Establishment* est= (getOwner()->getHand()->getEstablishments()[card.first].top());
            if((nameOfCardGiver==est->getCardName()) && (est->getType()!=tower) ){
                CardGiver=est;
            }
        }
    }
    //add
    playerReceiver->getHand()->addEstablishment(CardGiver,*playerReceiver);
    //remove
    currentPlayer.getHand()->removeEstablishment(CardGiver);

    g.getBank()->withdraw(getOwner()->getId(),getEarnedCoins());

}

class MovingCompany *MovingCompany::Clone() {
    MovingCompany* res = new MovingCompany();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}


void Winery::launchEffect(Game& g, Player& currentPlayer) {
    //Get 6 coins for each vineyard you own, on your turn only. Then, close this building for renovation.
    auto establishments=getOwner()->getHand()->getEstablishments();
    if (getOwner()->getHand()->getEstablishments().find(Vineyard)!=getOwner()->getHand()->getEstablishments().end()){
        setNumberOfCoinsEarned(getOwner()->getHand()->getEstablishments()[Vineyard].size()); //Le nombre de coins gagné est le nombre de vineyard possédées
    }
    else {
        setNumberOfCoinsEarned(0); //Le joueur ne possède pas de winery
    }
    g.getBank()->withdraw(getOwner()->getId(), getEarnedCoins());
    setRenovation(true);
}

class Winery *Winery::Clone() {
    Winery* res = new Winery();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}

void LoanOffice::launchEffect(Game& g, Player& currentPlayer) {
    if (g.getBank()->getBalance(getOwner()->getId() == 1)){
        g.getBank()->deposit(getOwner()->getId(), 1);
    }
    else if (g.getBank()->getBalance(getOwner()->getId() >= 2)){
        g.getBank()->deposit(getOwner()->getId(), -getEarnedCoins());
    }
    ;
}

class LoanOffice *LoanOffice::Clone() {
    LoanOffice* res = new LoanOffice();
    res->cardName = this->getCardName();
    res->description = this->getDescription();
    res->owner = this->getOwner();
    res->cost = this->getCost();
    res->expansion = this->getExpansion();
    res->type=this->getType();
    res->color = this->getColor();
    res->activationNumbers = this->getActivationNumbers();
    res->originOfCoinsEarned = this->getOrigin();
    res->numberOfCoinsEarned = this ->getEarnedCoins();
    res->underRenovation = this->getRenovation();
    return res;
}
