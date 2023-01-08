#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H
#include <QMessageBox>
#include <QMouseEvent>
#include "ui_gameinterface.h"
#include <string.h>
#include <QDialog>
#include "../Game/StandardExpansion.h"
#include "../Player/Human/Human.h"
#include "../UTILS/Enums.hpp"
#include "../Collection/Collection_standard.h"
#include "../Bank/Bank.hpp"
#include "../Board/Board.h"
#include <QTimer>
namespace Ui {
class GameInterface;
}

class GameInterface : public QDialog
{
    Q_OBJECT

public:
    explicit GameInterface(QWidget *parent = nullptr);

    void receiveData(QString expansion, QStringList names){
        this->expansion = expansion;
        this->names=names;
        connect(this, &GameInterface::startGame, this, &GameInterface::playerTurn);
    }

    void chooseGame(){
        if(expansion=="Standard"){

        }else if(expansion=="Harbor"){
        }
        else if(expansion=="Deluxe"){
        }
        else if(expansion=="Green Valley"){
        }
    }

    void constructInterface();
    void fillBoard();
    void initPlayers();
    //void startGame();
    int dice_turn(Player& current_player);
    void DoTurn(Player* current_player);
    ~GameInterface();
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent *event)
       {
            auto current_player=game->getPlayers().at(this->current_player);
            QWidget * const widget = childAt(event->pos());
            if(buyEstablishment==1){
                //qDebug() << "child widget" << widget;
                const int index = ui->boardLayout->layout()->indexOf(widget);
                //qDebug() << "layout index" << index;
                if (index >=0) {
                    Establishment *tmp = boardCards.at(index);
                    if(nbBoardCards[index]>0){
                        nbBoardCards[index]--;
                        if (tmp != nullptr && (game->getBank()->getBalance(current_player->getId()) - tmp->getCost() >= 0)) {
                            current_player->getHand()->addEstablishment(tmp, *current_player);
                            game->getBank()->deposit(current_player->getId(), tmp->getCost());
                        } else
                            insertAction("L'etablissement n'existe pas ou il n'a pas assez de money ! ");
                    }else{
                        insertAction(tmp->getCardName()+" est en rupture! vous ne pouvez plus achetez cette carte");
                    }
                }
                ui->boardLayout->layout()->setEnabled(false);
                buyEstablishment=-1;
                updatePlayerData();
                //clear(ui->boardLayout);
                //updateBoard();
                if (current_player->hasLandmark(AmusementPark) && (dice_result1 == dice_result2)){
                    DoTurn(current_player);
                    return;
                }
                if(!this->game->Iswin(*current_player)){
                   this->current_player++;
                    if (this->current_player == (game->getPlayers().size())){
                        this->current_player=0;
                    }
                   ui->roll_btn->setDisabled(false);
                   QTimer::singleShot(2000, this, &GameInterface::playerTurn);
                }else{
                    QMessageBox::information(nullptr, "Félècitions!", QString::fromStdString(current_player->getName()+" à gagner cette partie."));
                }
            }else if(buyEstablishment==0){
                    const int index = ui->landmarks_layout->layout()->indexOf(widget);
                    // On regarde si l'établissement existe et qu'il a l'argent nécessaire
                    string s=playerLandmarks.at(index)->getCardName();
                    EnumParser<LandmarksNames> fieldTypeParser;
                    LandmarksNames val = fieldTypeParser.ParseSomeEnum(s);
                        if (!current_player->hasLandmark(val) &&
                                             game->getBank()->getBalance(current_player->getId()) - game->GetCostLandmark(val) >= 0) {
                                             current_player->getHand()->addLandmark(val);
                                             game->getBank()->deposit(current_player->getId(), game->GetCostLandmark(val));
                        } else {
                            insertAction("Impossible : soit l'etablissement n'existe pas soit vous n'avez pas l'argent");
                        }
                    //ui->landmarks_layout->layout()->setEnabled(false);
                        buyEstablishment=-1;
                        updatePlayerData();
                        //clear(ui->boardLayout);
                        //updateBoard();
                        if (current_player->hasLandmark(AmusementPark) && (dice_result1 == dice_result2)){
                            DoTurn(current_player);
                            return;
                        }
                        if(!this->game->Iswin(*current_player)){
                           this->current_player++;
                            if (this->current_player == (game->getPlayers().size())){
                                this->current_player=0;
                            }
                           ui->roll_btn->setDisabled(false);
                           QTimer::singleShot(2000, this, &GameInterface::playerTurn);
                        }else{
                            QMessageBox::information(nullptr, "Félècitions!", QString::fromStdString(current_player->getName()+" à gagner cette partie."));
                        }
            }else{
                if ((current_player->hasLandmark(AmusementPark)!=nullptr) && (dice_result1 == dice_result2)){
                    DoTurn(current_player);
                    return;
                }
                if(!this->game->Iswin(*current_player)){
                   this->current_player++;
                    if (this->current_player == (game->getPlayers().size())){
                        this->current_player=0;
                    }
                   ui->roll_btn->setDisabled(false);
                   QTimer::singleShot(2000, this, &GameInterface::playerTurn);
                }else{
                    QMessageBox::information(nullptr, "Félècitions!", QString::fromStdString(current_player->getName()+" à gagner cette partie."));
                }
            }

        }

private slots:
    void on_roll_btn_clicked();
public slots:
    void startGame();
    void playerTurn();
private:
    bool isAI(string name){
        string first_two = name.substr(0, 2);
        return first_two.compare("IA")==0;
    }
    void clear(QLayout* layout){
        if (! layout)
           return;
        while (auto item = layout->takeAt(0)) {
           delete item->widget();
           clear(item->layout());
        }
    }
    void updateBoard(){
        int k=0;
                    for(auto card : boardCards){
                            nbLabels[k]->setText(QString::fromStdString(to_string(nbBoardCards[k])));
                            k++;
                }
    }
    void updatePlayerData(){
        Player* current=game->getPlayers().at(this->current_player);
        ui->playerName_lbl->setText(QString::fromStdString(current->getName()));
        ui->balance_lbl->setText(QString::fromStdString(to_string(game->getBank()->getBalance(current->getId()))));
        clear(ui->establishment_layout);
        clear(ui->landmarks_layout);
        clear(ui->dice_labels);
        int j, i=j=0;
        playerLandmarks.clear();
        for (auto card : current->getHand()->getLandmarks()){
            playerLandmarks.push_back(card.second);
            QPixmap pixmap;
            string cardName=card.second->getCardName();
            string path;
            if(card.second->isConstructed())
                path="/Users/omarelloumi/Desktop/MachiKoro/MachiKoro-UI-App/CardImages/"+cardName+".bmp";
            else
                path="/Users/omarelloumi/Desktop/MachiKoro/MachiKoro-UI-App/CardImages/"+cardName+"2.bmp";
            pixmap.load(QString::fromStdString(path));
            pixmap=pixmap.scaled(100, 150);
            QLabel* label = new QLabel;
            label->setPixmap(pixmap);
             ui->landmarks_layout->addWidget(label, i, j);
            if(j==4){
                i++;
                j=0;
            }else{
                j++;
            }
        }
        connect(ui->landmarks_layout,SIGNAL(clicked()),this,SLOT(mousePressEvent()));
        i=j=0;
            for (auto card : current->getHand()->getEstablishments()){
                QPixmap pixmap;
                string cardName=card.second.top()->getCardName();
                string path="/Users/omarelloumi/Desktop/MachiKoro/MachiKoro-UI-App/CardImages/"+cardName+".bmp";
                pixmap.load(QString::fromStdString(path));
                pixmap=pixmap.scaled(100, 150);
                QLabel* label = new QLabel;
                label->setPixmap(pixmap);
                ui->establishment_layout->addWidget(label, i, j);
                if(j==3){
                    i++;
                    j=0;
                }else{
                    j++;
                }
            }


    }
    void insertAction(string ch){
        int row = ui->actions->rowCount();
        QString str=QString::fromStdString(ch);
        ui->actions->insertRow(row);
        ui->actions->setItem(row, 0, new QTableWidgetItem(str));
        ui->actions->scrollToBottom();
    }

    Ui::GameInterface *ui;
    Game* game;
    int buyEstablishment=-1;
    int current_player=0;
    int dice_result1=-1;
    int dice_result2=-2;
    bool dice_rolled=false;
    bool end_turn=false;
    bool firstRound=true;
    vector<Establishment*> boardCards;
    vector<size_t> nbBoardCards;
    vector<Landmark*> playerLandmarks;
    vector<QLabel*> nbLabels;
    QString expansion;
    QStringList names;
};

#endif // GAMEINTERFACE_H
