#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include "ui_gameinterface.h"
#include <QDialog>
//#include "../Game/Game.h"
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
    }
    ~GameInterface();

private:
    Ui::GameInterface *ui;
    //Game* game=nullptr;
    QString expansion;
    QStringList names;
};

#endif // GAMEINTERFACE_H
