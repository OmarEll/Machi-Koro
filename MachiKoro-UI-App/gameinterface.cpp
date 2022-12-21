#include "gameinterface.h"
#include "ui_gameinterface.h"
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
