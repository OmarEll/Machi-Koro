//
// Created by mabur on 02/12/2022.
//

#include "HarborExpansion.h"
#include "../Collection/Collection_harbor.h"
#include "../Board/Harbor/HarborBoard.h"
#include "../Bank/Bank.hpp"
#include "Human/Human.h"

HarborExpansion::HarborExpansion( Collection_harbor &col) {
    vector<Player*> Gamer;
    int nbJoueurs = 0;
    cout << "Quel est le nombre de joueurs ?\n";
    ::fflush(stdin);
    cin >> nbJoueurs;
    for (int i = 1; i <= nbJoueurs; i++){
        string nomJoueur;
        cout << "Entrez le nom du " << i << "e joueur : \n";
        ::fflush(stdin);
        getline(cin,nomJoueur);
        Gamer.push_back(new Human(nomJoueur,col));
    }
    players = Gamer;
    establishments = col.GetEstablishment();
    landmarks = col.GetLandmark();
    expansionName = Harbor;
    minPlayers = 2;
    maxPlayers = 5;
    board_Game = Board::getInstance(col,expansionName);
    dices.push_back(Dice());
    dices.push_back(Dice());
    dices.push_back(Dice());
    bank_game = Bank::getInstance(players,2);
    Activation_order.push_back(RED);
    Activation_order.push_back(BLUE);
    Activation_order.push_back(GREEN);
    Activation_order.push_back(PURPLE);

}

void HarborExpansion::DoTurn(Player &current_player) {
    // Variables
    int dice = 0;
    string choice;
    // Fonction
    for (auto pl : players) {
        cout << pl->getName() << " dispose de " << bank_game->getBalance(pl->getId()) << endl;
    }
    //bank_game->playerPaysPlayer(current_player.getId(),players.at(2)->getId(),1);
    // Lance le dés
    cout << "\n\nC est au tour de " << current_player.getName() << endl;
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

    // On regarde les cartes rouges des autres joueurs
    for (auto other_player : players){
        if (other_player->getId() != current_player.getId()) {

            // On regarde si le nombre correspond à la carte rouge d'un autre joueur;
            for (auto red_card : other_player->getHand()->getColorCards(RED)){
                if (red_card->activate(dice)){
                    cout << red_card->getOwner()->getName() << " recoit " << red_card->getEarnedCoins() * other_player->getHand()->
                            getEstablishments()[red_card->getCardName_Enum()].size() << " de " << current_player.getName() << "par" << red_card->getCardName() << endl;
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
                else {
                    cards->launchEffect(*this,current_player); //si la carte est violette ou verte avec un gain avec type l'affichage est gérée directement dans le launch effect
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
                cout << "L etablissement n'existe pas && il n'a pas assez de money ! " << endl;
        }
    }
    else {
        if (choice == "Landmark"){
            int test = 0;
            while(test == 0) {
                cout << "Quel Landmark voulez-vous acheter ?" << endl;
                for (auto Land : current_player.getHand()->getLandmarks()){
                    if (!Land.second->isConstructed()){
                        cout << Land.second->getCardName() << "\nPrix = " << Land.second->getCost() << endl;
                    }
                }
                ::fflush(stdin);
                getline(cin,choice);
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
        }
        else
            cout << "Vous choisissez de ne faire aucune action" << endl;
    }
}

void HarborExpansion::Do_Game() {
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
            DoTurn(**current_player);
        }
        current_player++;
    } while (!Iswin(*test));
}

void HarborExpansion::initGame() {
    Establishment* baker= nullptr;
    Establishment* wheat= nullptr;

    for (auto bak : establishments){
        if (bak->getCardName_Enum() == Bakery){
            baker = bak;
        }
        if (bak->getCardName_Enum() == WheatField)
            wheat = bak;
    }
    for(auto joueur : players){
        joueur->getHand()->addEstablishment(baker->Clone(),*joueur);
        joueur->getHand()->addEstablishment(wheat->Clone(),*joueur);
        joueur->getHand()->addLandmark(CityHall);
    }

}

int HarborExpansion::dice_turn(Player &current_player) {
    string choice;
    dices.front().rollDice();
    cout << " Le resultat du de donne " << dices.front().GetResult() << endl;
    if (current_player.hasLandmark(TrainStation)){
        cout << "Voulez vous lancer un autre de ? " << endl;
        cin >> choice;
        if (choice == "oui"){
            dices.back().rollDice();
            if (current_player.hasLandmark(MoonTower)){
                auto l = dices.begin();
                //advance()
            }
            cout << " Le resultat des des donnent " << dices.front().GetResult()+dices.back().GetResult() << endl;
            if (dices.front().GetResult()+dices.back().GetResult() >= 10 && current_player.hasLandmark(harbor)){
                cout << "Vu que vous avez harbor on rajoute +2 ce qui donne " << 2+dices.front().GetResult()+dices.back().GetResult() << endl;
                return 2+dices.front().GetResult()+dices.back().GetResult() ;
            }
            else{
                return dices.front().GetResult()+dices.back().GetResult() ;
            }
        }
    }
    return dices.front().GetResult();
}
