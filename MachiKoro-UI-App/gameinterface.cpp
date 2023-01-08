#include "gameinterface.h"
#include "ui_gameinterface.h"
#include "../Board/Standard/StandardBoard.h"
#include "../Bank/Bank.hpp"
#include "../Player/Player.hpp"
#include <string>
#include <QVector>
#include <vector>

#include <iostream>
GameInterface::GameInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameInterface)
{
    ui->setupUi(this);
}

GameInterface::~GameInterface()
{
    delete ui;
}

void GameInterface::initPlayers(){
    auto* col = new Collection_standard();
    Establishment* baker= nullptr;
    Establishment* wheat= nullptr;
    vector<Player*> players;
    foreach (QString name, names) {
      players.push_back(new Human(name.toStdString(), *col));
    }
    game=new StandardExpansion(players,*col);
    for (auto bak : game->getEstablishments()){
            if (bak->getCardName_Enum() == Bakery){
                baker = bak;
            }
            if (bak->getCardName_Enum() == WheatField)
                wheat = bak;
    }
    foreach (auto player, players) {
      player->getHand()->addEstablishment(baker->Clone(),*player);
      player->getHand()->addEstablishment(wheat->Clone(),*player);
    }
}


void GameInterface::constructInterface(){
    setWindowTitle("Machi koro: "+expansion);
    ui->actions->setColumnWidth(0,400);
    initPlayers();
    fillBoard();
    startGame();
}


void GameInterface::DoTurn(Player* current_player){
    insertAction("-----------------------");
    int dice = dice_result1+dice_result2;
    end_turn=false;

    //print balance of each player
    for (auto pl : game->getPlayers()) {
        insertAction((pl->getName() + " dispose de " +
                      std::to_string(game->getBank()->getBalance(pl->getId()))));
    }
    //print current player
    insertAction(("C'est au tour de "+ current_player->getName()));
    if (current_player->hasLandmark(RadioTower) != nullptr){
        if(isAI(current_player->getName())==false){
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Des", "Voulez vous relancer vos des ?" ,
                                          QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                ui->roll_btn->setDisabled(false);
            }
        }}

    //gestion du landmark Shopping Mall
    //comment verifier qu'on n'augmente pas plusieurs fois les coins gagne par une carte si le joueur en a plusieurs dans sa main
    for (auto other_player : game->getPlayers()) {
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
    for (auto other_player : game->getPlayers()){
        if (other_player->getId() != current_player->getId()) {

            // On regarde si le nombre correspond à la carte rouge d'un autre joueur;
            for (auto red_card : other_player->getHand()->getColorCards(RED)){
                if (red_card->activate(dice)){
                    int balance_current= game->getBank()->getBalance(current_player->getId());
                    if (balance_current >= red_card->getEarnedCoins()) { //le joueur qui doit payer a assez de coins pour payer
                        insertAction(red_card->getOwner()->getName() + " recoit " + to_string(red_card->getEarnedCoins() * other_player->getHand()->
                                     getEstablishments()[red_card->getCardName_Enum()].size()) + " de " + current_player->getName() + " par " + red_card->getCardName());
                    } else {                                    //le joueur qui doit payer n'a pas assez de coins pour payer donc il donne ce qu'il a
                        insertAction(red_card->getOwner()->getName() + " recoit uniquement " + to_string(balance_current) + " de " + current_player->getName() + " par " + red_card->getCardName() + " parce que ce joueur n'a pas assee pour payer entierement" );

                    }
                    for (int i = 0 ; i < other_player->getHand()->getEstablishments()[red_card->getCardName_Enum()].size();i++){
                        red_card->launchEffect(*game, *current_player);
                    }
                }
            }
        }
    }
    for (auto all_players : game->getPlayers()){

        // On regarde les établissement de tout le monde
        for ( auto pair_cards : all_players->getHand()->getEstablishments()){
            Establishment* cards = pair_cards.second.top();

            // Si le joueur est le current player et que sa cartes n'est pas rouge et doit être activé
            if (current_player->getId() == all_players->getId() && cards->getColor() != RED && cards->activate(dice)){
                if (cards->getColor() != PURPLE && cards->getCardName_Enum() != FurnitureFactory && cards->getCardName_Enum() != CheeseFactory && cards->getCardName_Enum() != ProduceMarket){
                    insertAction(current_player->getName() + " gagne " + to_string(cards->getEarnedCoins() * current_player->getHand()->getEstablishments()[cards->getCardName_Enum()].size()) + " coins grace a " + cards->getCardName());
                    for (int i = 0 ; i < current_player->getHand()->getEstablishments()[cards->getCardName_Enum()].size();i++){
                        cards->launchEffect(*game,*current_player);
                    }
                }
                else { //a tester
                    for (int i = 0 ; i < current_player->getHand()->getEstablishments()[cards->getCardName_Enum()].size();i++){
                        cards->launchEffect(*game,*current_player); //si la carte est violette ou verte avec un gain avec type l'affichage est gérée directement dans le launch effect
                    }
                }
            }

            // Si le joueur est différent du current player et que la carte est bleue et qu'elle doit être activé
            if (current_player->getId() != all_players->getId() &&
                cards->getColor() == BLUE &&
                cards->activate(dice)){
                insertAction(all_players->getName() + " gagne " + to_string(cards->getEarnedCoins() * (all_players->getHand()->getEstablishments()[cards->getCardName_Enum()].size())) + " coins " +cards->getCardName());
                for (int i = 0 ; i < all_players->getHand()->getEstablishments()[cards->getCardName_Enum()].size();i++)
                    cards->launchEffect(*game,*all_players);
            }
        }
    }
    for (auto other_player : game->getPlayers()) {
        if (other_player->hasLandmark(ShoppingMall) != nullptr) {
            for (const auto &card: other_player->getHand()->getEstablishments()) { // Si la carte est de type 'bread' ou 'coffee' elle permet de gagner 1 coin de plus
                Establishment *est = (other_player->getHand()->getEstablishments()[card.first].top());
                if (est->getType() == bread || est->getType() == coffee) {
                    est->setNumberOfCoinsEarned(est->getEarnedCoins() - 1);
                }
            }
        }
    }
    ui->balance_lbl->setText(QString::fromStdString(to_string(game->getBank()->getBalance(current_player->getId()))));
    if(isAI(current_player->getName())){
        emit on_roll_btn_clicked();
    }
}
int GameInterface::dice_turn(Player& current_player) {

    string choice;
    auto dices=game->GetDices();

    //dices.back().reset_dice();
    //dices.front().rollDice();
    dice_result1=rand()%6+1;
    dice_result2=0;
    //------insert dice image
    QPixmap pixmap;
    string path="/Users/omarelloumi/Desktop/MachiKoro/MachiKoro-UI-App/diceImages/"+to_string(dice_result1)+".png";
    pixmap.load(QString::fromStdString(path));
    pixmap=pixmap.scaled(50, 50);
    QLabel* label = new QLabel;
    label->setPixmap(pixmap);
    ui->dice_labels->addWidget(label);
    //------
    string str=(" Le resultat du de donne "+ to_string(dice_result2+dice_result1));
    insertAction(str);
    if (current_player.hasLandmark(TrainStation)){
        QMessageBox::StandardButton reply;
        if(isAI(current_player.getName())==false){
            reply = QMessageBox::question(this, "Des", "Voulez vous lancer un autre de ?",
                                          QMessageBox::Yes|QMessageBox::No);
            }
            if ((isAI(current_player.getName())) || (reply == QMessageBox::Yes)) {
                dice_result2=rand()%6+1;
                str="Vous avez lance " + to_string(dice_result1) + " + " + to_string(dice_result2);
                insertAction(str);
                str="Le resultat des des donnent " + to_string(dice_result1+dice_result2);
                insertAction(str);
                //------insert dice image
                QPixmap pixmap;
                string path="/Users/omarelloumi/Desktop/MachiKoro/MachiKoro-UI-App/diceImages/"+to_string(dice_result2)+".png";
                pixmap.load(QString::fromStdString(path));
                pixmap=pixmap.scaled(50, 50);
                QLabel* label = new QLabel;
                label->setPixmap(pixmap);
                ui->dice_labels->addWidget(label);
            }

    }
}
void GameInterface::startGame(){
    emit playerTurn();
}
void GameInterface::playerTurn(){
        auto current_player=game->getPlayers().at(this->current_player);
        updatePlayerData();
        DoTurn(current_player);
}

void GameInterface::fillBoard(){
    StandardBoard* board=dynamic_cast<StandardBoard*> (game->getBoard());
    auto cards=board->getCards();
    int i=0;
    int j=0;
    int k=0;
    connect(ui->boardLayout,SIGNAL(clicked()),this,SLOT(mousePressEvent()));
        for(auto card : cards){
            QPixmap pixmap;
                    boardCards.push_back(card.second.top());
                    nbBoardCards.push_back(card.second.size());
                    string cardName=card.second.top()->getCardName();
                    string path="/Users/omarelloumi/Desktop/MachiKoro/MachiKoro-UI-App/cardImages/"+cardName+".bmp";
                    pixmap.load(QString::fromStdString(path));
                    pixmap=pixmap.scaled(100, 150);
                    QLabel* label = new QLabel;
                    label->setMouseTracking(true);
                    label->setPixmap(pixmap);
                    ui->boardLayout->addWidget(label,i,j);
                    if(j==4){
                        i++;
                        j=0;
                    }else{
                        j++;
                    }

        firstRound=false;
    }
}


void GameInterface::on_roll_btn_clicked()
{
    //to clear layout before using it
    QLayoutItem *child;
    dice_rolled=true;
    while ((child = ui->dice_labels->takeAt(0)) != 0);
    auto current_player=game->getPlayers().at(this->current_player);

    dice_turn(*current_player);
    //ui->roll_btn->setDisabled(true);
    insertAction(current_player->getName() + " vous disposez de " + to_string(game->getBank()->getBalance(current_player->getId())) + " coins");
    if(game->getBank()->getBalance(current_player->getId()) > 0){
        if(isAI(current_player->getName())==false){
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Achats", "Click: \nYes pour acheter un Establishment,\nOk pour Landmark, \nNo pour rien?",
                                          QMessageBox::Yes|QMessageBox::No|QMessageBox::Ok);
            if (reply == QMessageBox::Yes) {
                insertAction("Quel Establishment voulez-vous acheter ? Cliquer sur la carte.");
                buyEstablishment=1;
                ui->boardLayout->layout()->setEnabled(true);
            }
            else if (reply == QMessageBox::Ok){
                insertAction("Quel Landmark voulez-vous acheter ?");
                buyEstablishment=0;
                ui->landmarks_layout->layout()->setEnabled(true);
            }else if (reply == QMessageBox::No){
                    insertAction(current_player->getName()+" a choisi de rien acheter");
                    buyEstablishment=-1;
                    this->current_player++;
                     if (this->current_player == (game->getPlayers().size())){
                         this->current_player=0;
                     }
                    QTimer::singleShot(2000, this, &GameInterface::playerTurn);
            }
            else insertAction("Vous n'avez pas d'argent pour faire une action");
        }else{
            auto landCards=current_player->getHand()->getLandmarks();
            bool bought=0;
            for(auto landmark: landCards){
                string s=landmark.second->getCardName();
                EnumParser<LandmarksNames> fieldTypeParser;
                LandmarksNames val = fieldTypeParser.ParseSomeEnum(s);
                if((!landmark.second->isConstructed()) && (landmark.second->getCost()<=game->getBank()->getBalance(current_player->getId()))){
                    insertAction(current_player->getName()+" a choisi d'acheter "+landmark.second->getCardName());
                    current_player->getHand()->addLandmark(val);
                    game->getBank()->deposit(current_player->getId(), game->GetCostLandmark(val));
                    bought=1;
                    break;
                }
            }
            if(bought==false){
                int index=0;
                for(auto establishment: boardCards){
                    if((nbBoardCards[index]>0) && (establishment->getCost()<=game->getBank()->getBalance(current_player->getId()))){
                        nbBoardCards[index]--;
                        insertAction(current_player->getName()+" a choisi d'acheter "+establishment->getCardName());
                         current_player->getHand()->addEstablishment(establishment, *current_player);
                         game->getBank()->deposit(current_player->getId(), establishment->getCost());
                         bought=1;
                         break;
                    }
                    index++;
                }
            }
            buyEstablishment=-1;
            updatePlayerData();
            if(!this->game->Iswin(*current_player)){
               this->current_player++;
                if (this->current_player == (game->getPlayers().size())){
                    this->current_player=0;
                }
               ui->roll_btn->setDisabled(false);
               QTimer::singleShot(2000, this, &GameInterface::playerTurn);
            }
           return;

}
    }else{
        if(isAI(current_player->getName())){
            insertAction(current_player->getName()+" a choisi de rien acheter ");
            buyEstablishment=-1;
            updatePlayerData();
            // insérer test amusment park?
            if(!this->game->Iswin(*current_player)){
               this->current_player++;
                if (this->current_player == (game->getPlayers().size())){
                    this->current_player=0;
                }
               ui->roll_btn->setDisabled(false);
               QTimer::singleShot(2000, this, &GameInterface::playerTurn);
            }
        }
    }

}

