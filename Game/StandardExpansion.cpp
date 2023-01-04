#include "../Card/Establishment/Establishment.h"
#include "../Card/Landmark/Landmark.h"
#include "../UTILS/Enums.hpp"
#include "../Player/Player.hpp"
#include "../Board/Board.h"
#include "../Bank/Bank.hpp"
#include "../Card/Card.hpp"
#include "StandardExpansion.h"


StandardExpansion::StandardExpansion (vector<Player*> joueur, Collection_standard& col){
    players = joueur;
    establishments = col.GetEstablishment();
    landmarks = col.GetLandmark();
    minPlayers = 2;
    maxPlayers = 4;
    board_Game = Board::getInstance(col);
    dices.push_back(Dice());
    dices.push_back(Dice());
    bank_game = Bank::getInstance(joueur,2);
    Activation_order.push_back(RED);
    Activation_order.push_back(BLUE);
    Activation_order.push_back(GREEN);
    Activation_order.push_back(PURPLE);
    expansionName = Standard;

}

void StandardExpansion::DoTurn(Player &current_player) {
    // Variables
    int dice = 0;
    string choice;
    // Fonction
    for (auto pl : players) {
        cout << pl->getName() << " dispose de " << bank_game->getBalance(pl->getId()) << endl;
    }
    //bank_game->playerPaysPlayer(current_player.getId(),players.at(2)->getId(),1);
    // Lance le dés
cout << "\n\nC'est au tour de " << current_player.getName() << endl;
for (auto car : current_player.getHand()->getEstablishments())
    cout <<"\n" <<  car.second.top()->getCardName() << "\t quantite : " << car.second.size() << "\n" << endl;

for (auto pl : players){
    cout << pl->getName()<< " dispose de "<< bank_game->getBalance(pl->getId()) << endl;
}
    dice = dice_turn(current_player);
    if (current_player.hasLandmark(RadioTower) != nullptr){
        cout << "Voulez vous relancer vos des ?" << endl;
        cin >> choice;
        if (choice == "oui"){
            dice = dice_turn(current_player);
        }
    }

    if (current_player.hasLandmark(ShoppingMall) != nullptr){
        for (const auto&  card : current_player.getHand()->getEstablishments()){ // Si la carte est de type 'bread' ou 'coffee' elle permet de gagner 1 coin de plus
            Establishment* est= (current_player.getHand()->getEstablishments()[card.first].top());
            if(est->getType() == bread || est->getType() == coffee){
                est->setNumberOfCoinsEarned(est->getEarnedCoins() + 1);
                cout << "je suis passée pour augmenter \n";
            }
        }
    }

    // On regarde les cartes rouges des autres joueurs
    for (auto other_player : players){
        if (other_player->getId() != current_player.getId()) {

            // On regarde si le nombre correspond à la carte rouge d'un autre joueur;
            for (auto red_card : other_player->getHand()->getColorCards(RED)){
                if (red_card->activate(dice)){
                    int balance_current= getBank()->getBalance(current_player.getId());
                    if (balance_current >= red_card->getEarnedCoins()) { //le joueur qui doit payer a assez de coins pour payer
                        cout << red_card->getOwner()->getName() << " recoit " << red_card->getEarnedCoins() * other_player->getHand()->
                                getEstablishments()[red_card->getCardName_Enum()].size() << " de " << current_player.getName() << " par " << red_card->getCardName() << endl;
                    } else {                                    //le joueur qui doit payer n'a pas assez de coins pour payer donc il donne ce qu'il a
                        cout << red_card->getOwner()->getName() << " recoit uniquement " << balance_current << " de " << current_player.getName() << " par " << red_card->getCardName() << " parce que ce joueur n'a pas assee pour payer entierement" << endl;

                    }
                    for (int i = 0 ; i < other_player->getHand()->getEstablishments()[red_card->getCardName_Enum()].size();i++){
                        red_card->launchEffect(*this, current_player);
                    }
                }
            }
        }
    }
    // On a finit de regarder les cartes rouges des autres joueurs
    // Maintenant, on va activer toutes les cartes bleus des autres joueurs (current player compris)
    // Et toutes les cartes du current player qui doivent être activés
    for (auto all_players : players){

        // On regarde les établissement de tout le monde
        for ( auto pair_cards : all_players->getHand()->getEstablishments()){
            Establishment* cards = pair_cards.second.top();

            // Si le joueur est le current player et que sa cartes n'est pas rouge et doit être activé
            if (current_player.getId() == all_players->getId() && cards->getColor() != RED && cards->activate(dice)){
                if (cards->getColor() != PURPLE && cards->getCardName_Enum() != FurnitureFactory && cards->getCardName_Enum() != CheeseFactory && cards->getCardName_Enum() != ProduceMarket){
                    cout << current_player.getName() << " gagne " << cards->getEarnedCoins() * current_player.getHand()->getEstablishments()[cards->getCardName_Enum()].size() << " coins grace a " << cards->getCardName()<< endl;
                    for (int i = 0 ; i < current_player.getHand()->getEstablishments()[cards->getCardName_Enum()].size();i++){
                        cards->launchEffect(*this,current_player);
                    }
                }
                else { //a tester
                    for (int i = 0 ; i < current_player.getHand()->getEstablishments()[cards->getCardName_Enum()].size();i++){
                        cards->launchEffect(*this,current_player); //si la carte est violette ou verte avec un gain avec type l'affichage est gérée directement dans le launch effect
                    }
                }
            }

            // Si le joueur est différent du current player et que la carte est bleue et qu'elle doit être activé
            if (current_player.getId() != all_players->getId() &&
                cards->getColor() == BLUE &&
                cards->activate(dice)){
                cout << all_players->getName() << " gagne " << cards->getEarnedCoins() * (all_players->getHand()->getEstablishments()[cards->getCardName_Enum()].size()) << " coins " <<cards->getCardName()<< endl;
                for (int i = 0 ; i < all_players->getHand()->getEstablishments()[cards->getCardName_Enum()].size();i++)
                    cards->launchEffect(*this,*all_players);
            }
        }
    }
    // On regarde si le joueur veut acheter un landmark
    choice = "";
    cout << current_player.getName() << " vous disposez de " << bank_game->getBalance(current_player.getId()) << " coins" << endl;
    if(bank_game->getBalance(current_player.getId()) > 0){
        cout<< "Voulez-vous acheter un etablissement ou un landmark ?\nEstablishment\nLandmark\nNothing" << endl;
        cin >> choice;
        if (choice == "Establishment"){
            int test = 0;
            while(test == 0) {
                cout << "Quel Establishment voulez-vous acheter ?" << endl;
                board_Game->displayCards();
                ::fflush(stdin);
                getline(cin, choice);
                Establishment *tmp = board_Game->foundEstablishmentOnBoard(choice);
                if (tmp != nullptr && bank_game->getBalance(current_player.getId()) - tmp->getCost() >= 0) {
                    current_player.getHand()->addEstablishment(tmp, current_player);
                    bank_game->deposit(current_player.getId(), tmp->getCost());
                    test = 1;
                } else
                    cout << "L'etablissement n'existe pas ou il n'a pas assez de money ! " << endl;
            }
        }
        else {
            if (choice == "Landmark") {
                int test = 0;
                while (test == 0) {
                    cout << "Quel Landmark voulez-vous acheter ?" << endl;
                    for (auto Land: current_player.getHand()->getLandmarks()) {
                        if (!Land.second->isConstructed()) {
                            cout << Land.second->getCardName() << "\nPrix = " << Land.second->getCost() << endl;
                        }
                    }
                    ::fflush(stdin);
                    getline(cin, choice);
                    EnumParser<LandmarksNames> fieldTypeParser;
                    LandmarksNames val = fieldTypeParser.ParseSomeEnum(choice);
                    // On regarde si l'établissement existe et qu'il a l'argent nécessaire
                    if (!current_player.hasLandmark(val) &&
                        bank_game->getBalance(current_player.getId()) - GetCostLandmark(val) >= 0) {
                        current_player.getHand()->addLandmark(val);
                        bank_game->deposit(current_player.getId(), GetCostLandmark(val));
                        test = 1;
                    } else {
                        cout << "Impossible : soit l'etablissement n'existe pas soit vous n'avez pas l'argent" << endl;
                    }
                }
        } else
            cout << "Vous choisissez de ne faire aucune action" << endl;
        }
    }
    else cout << "Vous n'avez pas d'argent pour faire une action" << endl;

    if (current_player.hasLandmark(ShoppingMall) != nullptr){
        for (const auto&  card : current_player.getHand()->getEstablishments()){ // Si la carte est de type 'bread' ou 'coffee' elle permet de gagner 1 coin de plus
            Establishment* est= (current_player.getHand()->getEstablishments()[card.first].top());
            if(est->getType() == bread || est->getType() == coffee){
                est->setNumberOfCoinsEarned(est->getEarnedCoins() - 1);
                cout << "je suis passée pour diminuer \n";
            }
        }
    }

}

void StandardExpansion::Do_Game() {
    initGame();
    Player* test = nullptr;
    vector <Player*>::iterator current_player = players.begin();
    do{
        if (current_player == players.end()){
            current_player = players.begin();
        }
        test = *current_player;
        DoTurn(**current_player);
        if ((*current_player)->hasLandmark(AmusementPark) &&
            dices.front().GetResult() == dices.back().GetResult()){
            cout << "Vous avez joue un double et vous possedez Amusement Park, vous avez donc droit a un tour supplementaire " <<endl;
            DoTurn(**current_player);
        }
        current_player++;
    } while (!Iswin(*test));
}

void StandardExpansion::initGame() {
    Establishment* baker= nullptr;
    Establishment* wheat= nullptr;

    // A ENELVER A LA FIN
    Establishment* stad= nullptr;
    Establishment* cheese= nullptr;
    Establishment* ran = nullptr;


    for (auto bak : establishments){
        if (bak->getCardName_Enum() == Bakery){
            baker = bak;
        }
        if (bak->getCardName_Enum() == WheatField)
            wheat = bak;

        // POUR TEST A ENLEVER A LA FIN
        if (bak->getCardName_Enum() == Cafe)
            stad = bak;
        if (bak->getCardName_Enum() == ProduceMarket)
            cheese = bak;
        if (bak->getCardName_Enum() == Forest)
            ran = bak;
    }
    for(auto joueur : players){
        joueur->getHand()->addEstablishment(baker->Clone(),*joueur);
        joueur->getHand()->addEstablishment(wheat->Clone(),*joueur);

        // A SUPPRIMER
        joueur->getHand()->addEstablishment(stad->Clone(),*joueur);
        joueur->getHand()->addEstablishment(cheese->Clone(),*joueur);
        joueur->getHand()->addEstablishment(ran->Clone(),*joueur);
        joueur->getHand()->addLandmark(ShoppingMall);
        //joueur->getHand()->addLandmark(TrainStation);
        }
}




// Fin du tour d'un joueur


