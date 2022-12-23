#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include "ui_gameinterface.h"
#include <QDialog>
#include "../Game/StandardExpansion.h"
#include "../UTILS/Enums.hpp"

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
    }

    void chooseGame(){
        if(expansion=="Standard"){
            //game=new StandardExpansion();
        }else if(expansion=="Harbor"){
        }
        else if(expansion=="Deluxe"){
        }
        else if(expansion=="Green Valley"){
        }
    }

    void constructInterface(){
        setWindowTitle("Machi koro: "+expansion);
        chooseGame();
        ui->actions->setColumnWidth(0, 400);
        ui->boardLayout->setSpacing(0);
         ui->boardLayout->setContentsMargins(0,0,0,0);

        //ui->actions->insertRow(ui->actions->rowCount());
        //QTableWidgetItem* itemName= new QTableWidgetItem("Omar activated his Harbor Card and gained 3 coins.");
        //ui->actions->setItem( ui->actions->rowCount()-1, 0,itemName);
        QPixmap pixmap;
        pixmap.load("/Users/omarelloumi/Documents/MachiKoroV1/build-MachiKoro-UI-App-Qt_6_4_1_for_macOS-Debug/CardImages/forest.bmp");
        pixmap=pixmap.scaled(100, 150);

        QLabel* label = new QLabel;
        QLabel* label1 = new QLabel;
        QLabel* label2 = new QLabel;
        QLabel* label3 = new QLabel;
        QLabel* label4 = new QLabel;
        QLabel* label5 = new QLabel;

        QLabel* label11 = new QLabel;
        QLabel* label22 = new QLabel;
        QLabel* label33 = new QLabel;
        QLabel* label44 = new QLabel;
        QLabel* label55 = new QLabel;

        label->setPixmap(pixmap);
        label1->setPixmap(pixmap);
        label2->setPixmap(pixmap);
        label3->setPixmap(pixmap);
        label4->setPixmap(pixmap);
        label5->setPixmap(pixmap);
label->setMargin(0);
        label11->setPixmap(pixmap);
        label22->setPixmap(pixmap);
        label33->setPixmap(pixmap);
        label44->setPixmap(pixmap);
        label55->setPixmap(pixmap);
label11->setMargin(0);
        ui->boardLayout->addWidget(label, 0, 0);
        ui->boardLayout->addWidget(label1, 0, 1);
        ui->boardLayout->addWidget(label2, 0, 2);
        ui->boardLayout->addWidget(label3, 0, 3);
        ui->boardLayout->addWidget(label5, 0, 4);

        ui->boardLayout->addWidget(label11, 1, 0);
        ui->boardLayout->addWidget(label22, 1, 1);
        ui->boardLayout->addWidget(label33, 1, 2);
        ui->boardLayout->addWidget(label44, 1, 3);
        ui->boardLayout->addWidget(label55, 1,4);

        /*ui->boardLayout->addWidget(label, 2, 0);
        ui->boardLayout->addWidget(label, 3, 0);
        ui->boardLayout->addWidget(label, 4, 0);

        ui->boardLayout->addWidget(label, 0, 1);
        ui->boardLayout->addWidget(label, 1, 1);
        ui->boardLayout->addWidget(label, 2, 1);
        ui->boardLayout->addWidget(label, 3, 1);
        ui->boardLayout->addWidget(label, 4, 1);*/
    }
    ~GameInterface();

private:
    Ui::GameInterface *ui;
    Game* game=nullptr;
    QString expansion;
    QStringList names;
};

#endif // GAMEINTERFACE_H
