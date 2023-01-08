//
// Created by mabur on 02/12/2022.
//

#include "GreenValleyExpansion.h"
#include "Human/Human.h"
#include "Board.h"
#include "Bank.hpp"

GreenValleyExpansion::GreenValleyExpansion(Collection_GreenValley &col) {
    vector<Player*> Gamer;
    //POUR TEST
    int nbJoueurs = 2;
    Gamer.push_back(new Human("Julie",col));
    Gamer.push_back(new Human("Sarah",col));

    /*
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
    } */
    players = Gamer;
    establishments = col.GetEstablishment();
    expansionName = GreenValley;
    landmarks = col.GetLandmark();
    minPlayers = 2;
    maxPlayers = 4;
    board_Game = Board::getInstance(col,expansionName);
    dices.push_back(Dice());
    dices.push_back(Dice());
    bank_game = Bank::getInstance(players);
    Activation_order.push_back(RED);
    Activation_order.push_back(BLUE);
    Activation_order.push_back(GREEN);
    Activation_order.push_back(PURPLE);

}

GreenValleyExpansion::GreenValleyExpansion(Collection_GreenValley & col, vector<Player *> joueur) {
    players = joueur;
    establishments = col.GetEstablishment();
    landmarks = col.GetLandmark();
    minPlayers = 2;
    maxPlayers = 4;
    expansionName = GreenValley;
    board_Game = Board::getInstance(col,expansionName);
    dices.push_back(Dice());
    dices.push_back(Dice());
    bank_game = Bank::getInstance(joueur,2);
    Activation_order.push_back(RED);
    Activation_order.push_back(BLUE);
    Activation_order.push_back(GREEN);
    Activation_order.push_back(PURPLE);

}

void GreenValleyExpansion::DoTurn(Player &current_player) {
    // Variables
    int dice = 0;
    string choice;
    // Fonction
    for (auto pl : players) {
        cout << pl->getName() << " dispose de " << bank_game->getBalance(pl->getId()) << endl;
    }

    // Lance le dés
    cout << "\n\nC'est au tour de " << current_player.getName() << endl;
    for (auto car : current_player.getHand()->getEstablishments())
        cout <<"\n" <<  car.second.top()->getCardName() << "\t quantite : " << car.second.size() << "\n" << endl;

    for (auto pl : players){
        cout << pl->getName()<< " dispose de "<< bank_game->getBalance(pl->getId()) << endl;
    }
    dice = 10; // POUR TEST***************************************************************************************************************
    //dice = dice_turn(current_player);
    if (current_player.hasLandmark(RadioTower) != nullptr){
        cout << "Voulez vous relancer vos des ?" << endl;
        cin >> choice;
        if (choice == "oui"){
            dice = dice_turn(current_player);
        }
    }

    //gestion du landmark Shopping Mall
    //comment verifier qu'on n'augmente pas plusieurs fois les coins gagne par une carte si le joueur en a plusieurs dans sa main
    for (auto other_player : players) {
        if (other_player->hasLandmark(ShoppingMall) != nullptr) {
            for (const auto &card: other_player->getHand()->getEstablishments()) { // Si la carte est de type 'bread' ou 'coffee' elle permet de gagner 1 coin de plus
                Establishment *est = (other_player->getHand()->getEstablishments()[card.first].top());
                if (est->getType() == bread || est->getType() == coffee) {
                    est->setNumberOfCoinsEarned(est->getEarnedCoins()+1);
                }
            }
        }
    }

    // On regarde les cartes rouges des autres joueurs
    for (auto other_player : players){
        if (other_player->getId() != current_player.getId()) {

            // On regarde si le nombre correspond à la carte rouge d'un autre joueur;
            for (auto rcard : other_player->getHand()->getEstablishments()){
                if (rcard.second.top()->getColor() == RED){
                    stack<Establishment*> te = rcard.second;
                    while (!te.empty()){
                        Establishment* red_card = te.top();
                        if (red_card->activate(dice) && !red_card->getRenovation()){
                            if (red_card->getCardName_Enum() != FrenchRestaurant && red_card->getCardName_Enum() != MembersOnlyClub){
                                int balance_current= getBank()->getBalance(current_player.getId());
                                if (balance_current >= red_card->getEarnedCoins()) { //le joueur qui doit payer a assez de coins pour payer
                                    cout << red_card->getOwner()->getName() << " recoit " << red_card->getEarnedCoins() << " de " << current_player.getName() << " par " << red_card->getCardName() << endl;
                                } else {                                    //le joueur qui doit payer n'a pas assez de coins pour payer donc il donne ce qu'il a
                                    cout << red_card->getOwner()->getName() << " recoit uniquement " << balance_current << " de " << current_player.getName() << " par " << red_card->getCardName() << " parce que ce joueur n'a pas assee pour payer entierement" << endl;

                                }
                            }
                            red_card->launchEffect(*this, current_player);
                        }
                        else {
                            if (red_card->activate(dice) && red_card->getRenovation()){
                                red_card->setRenovation(false);
                            }
                        }
                        te.pop();
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
            stack <Establishment*> tet = pair_cards.second;
            while (!tet.empty()){
                Establishment* cards = tet.top();

                // Si le joueur est le current player et que sa cartes n'est pas rouge et doit être activé
                if (current_player.getId() == all_players->getId() && cards->getColor() != RED && cards->activate(dice) && !cards->getRenovation()){
                    if (cards->getColor() != PURPLE && cards->getCardName_Enum() != FurnitureFactory && cards->getCardName_Enum() != CheeseFactory && cards->getCardName_Enum() != ProduceMarket && cards->getCardName_Enum() != CornField && cards->getCardName_Enum() != GeneralStore && cards->getCardName_Enum() != DemolitionCompany){
                        cards->launchEffect(*this,current_player);
                        cout << current_player.getName() << " gagne " << cards->getEarnedCoins() << " coins grace a " << cards->getCardName()<< endl;
                    }
                    else {

                            cards->launchEffect(*this,current_player); //si la carte est violette ou verte avec un gain avec type l'affichage est gérée directement dans le launch effect

                    }
                }
                else {
                    if (cards->activate(dice) && cards->getRenovation() && current_player.getId() == all_players->getId() && cards->getColor() != RED){
                        cards->setRenovation(false);
                    }
                }

                // Si le joueur est différent du current player et que la carte est bleue et qu'elle doit être activé
                if (current_player.getId() != all_players->getId() &&
                    cards->getColor() == BLUE &&
                    cards->activate(dice) &&
                    !cards->getRenovation()){
                    cards->launchEffect(*this,*all_players);
                    cout << all_players->getName() << " gagne " << cards->getEarnedCoins() << " coins " <<cards->getCardName()<< endl;

                }
                else {
                    if (cards->activate(dice) && cards->getRenovation() && current_player.getId() != all_players->getId() && cards->getColor() == BLUE){
                        cards->setRenovation(false);
                    }
                }
                tet.pop();
            }
        }
    }

    for (auto other_player : players) {
        if (other_player->hasLandmark(ShoppingMall) != nullptr) {
            for (const auto &card: other_player->getHand()->getEstablishments()) { // Si la carte est de type 'bread' ou 'coffee' elle permet de gagner 1 coin de plus
                Establishment *est = (other_player->getHand()->getEstablishments()[card.first].top());
                if (est->getType() == bread || est->getType() == coffee) {
                    est->setNumberOfCoinsEarned(est->getEarnedCoins() - 1);
                }
            }
        }
    }

    // On regarde si le joueur veut acheter un landmark
    choice = "";
    cout << current_player.getName() << " vous disposez de " << bank_game->getBalance(current_player.getId()) << " coins" << endl;
    if(bank_game->getBalance(current_player.getId()) >= 0){
        cout<< "Voulez-vous acheter un etablissement ou un landmark ?\nEstablishment\nLandmark\nNothing" << endl;
        cin >> choice;
        if (choice == "Establishment"){
            int test = 0;
            while(test == 0) {
                cout << "Quel Establishment voulez-vous acheter ? (si vous ne voulez plus acheter d'etablisssemnt taper 'exit')" << endl;
                board_Game->displayCards();
                ::fflush(stdin);
                getline(cin, choice);
                if (choice == "exit"){
                    test = 1;
                }
                else {
                    Establishment *tmp = board_Game->foundEstablishmentOnBoard(choice);
                    if (tmp == board_Game->foundEstablishmentOnBoard("Loan Office")){
                        getBank()->withdraw(current_player.getId(),5);
                        cout << "En achetant Loan Office, " << current_player.getName() << " gagne 5 coins" << endl;
                    }
                    if (tmp != nullptr && bank_game->getBalance(current_player.getId()) - tmp->getCost() >= 0) {
                        current_player.getHand()->addEstablishment(tmp, current_player);
                        bank_game->deposit(current_player.getId(), tmp->getCost());
                        test = 1;
                    } else
                        cout << "L'etablissement n'existe pas ou il n'a pas assez de money ou c'est une carte violette qu'il possede deja " << endl;
                }
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
                        cout << "Impossible : soit le landmark n'existe pas soit vous n'avez pas l'argent" << endl;
                    }
                }
            }
            else
                cout << "Vous choisissez de ne faire aucune action" << endl;
        }
    }
    else cout << "Vous n'avez pas d'argent pour faire une action" << endl;


    if (current_player.hasEstablishment(TechStartup) != nullptr && bank_game->getBalance(current_player.getId()) >= 1){
        cout << current_player.hasEstablishment(TechStartup)->getEarnedCoins() << endl;
        cout << "Voulez vous investir dans la startup ? Il y a "<< current_player.hasEstablishment(TechStartup)->getEarnedCoins()<< " coins deja investis"  << endl;
        cin >> choice;
        if (choice == "oui"){
            cout << "on est la " <<endl;
            Establishment * tc = current_player.hasEstablishment(TechStartup);
            cout << "on est ici " <<endl;
            dynamic_cast<class TechStartup*> (tc)->oneCoinInvestment();
            cout << "on est a cet endroit " <<endl;
            bank_game->deposit(current_player.getId(),1);
            cout << "on est a la fin de la boucle " <<endl;
        }
        else{
            cout << current_player.getName() << " choisit de ne pas investir " << endl;
        }
    }

}

void GreenValleyExpansion::Do_Game() {
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

void GreenValleyExpansion::initGame() {
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
            //joueur->getHand()->addEstablishment(baker->Clone(),*joueur);
            joueur->getHand()->addEstablishment(wheat->Clone(),*joueur);
    }

    //POUR TEST
    Establishment* wheat1= nullptr;

    for (auto bak : establishments){
        if (bak->getCardName_Enum() == TechStartup){
            baker = bak;
        }
        if (bak->getCardName_Enum() == WheatField)
            wheat = bak;
        if (bak->getCardName_Enum() == FrenchRestaurant)
            wheat1 = bak;
    }
    for(auto joueur : players){
        joueur->getHand()->addEstablishment(baker->Clone(),*joueur);
        joueur->getHand()->addEstablishment(wheat->Clone(),*joueur);
        joueur->getHand()->addEstablishment(wheat1->Clone(),*joueur);
        //joueur->getHand()->addLandmark(TrainStation);
        //joueur->getHand()->addLandmark(AmusementPark);
        joueur->getHand()->addLandmark(ShoppingMall);
    }


}
