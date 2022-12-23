#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QTextEdit>
#include <string>
#include<ctype.h>
#include <QMessageBox>
#include <cctype>
#include <QComboBox>
#include "../UTILS/Enums.cpp"
#include <QPixmap>
#include <QDir>
#include "../Player/Player.hpp"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initWindow();

}

MainWindow::~MainWindow()
{
    delete ui;
}
//-----------------------Special functions---------------------------
void MainWindow::initWindow(){
    for(int exp=Standard;exp<=Deluxe;exp++){
        Expansions expName=static_cast<Expansions> (exp);
        QString str=QString::fromStdString(getExpansionName(expName));
        ui->expansions_cb->addItem(str);
    }

}
//--------------------Listeners------------------------------
void MainWindow::on_deleteBtnClicked()
{
    //sender(): QPushButton
    QWidget *w = qobject_cast<QWidget *>(sender()->parent());
     if(w){
         int row = ui->tableOfNames->indexAt(w->pos()).row();
         QString s = QString::number(row);
         ui->nom_edt->setText("");
         ui->tableOfNames->removeRow(row);
         ui->tableOfNames->setCurrentCell(0, 0);
     }
}

QWidget* MainWindow::createDeleteButton(){
    QWidget* pWidget = new QWidget();
    QPushButton* btn_remove = new QPushButton();
    btn_remove->setText("Remove");
    connect(btn_remove, &QPushButton::clicked, this, &MainWindow::on_deleteBtnClicked);
    QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
    pLayout->addWidget(btn_remove);
    pLayout->setAlignment(Qt::AlignCenter);
    pLayout->setContentsMargins(0, 0, 0, 0);
    pWidget->setLayout(pLayout);
    return pWidget;
}

bool checkAlpha(QString str){
    for(int i = 0; i < str.size(); i++)
        if( (!str.at(i).isLetter()) && !str.at(i).isSpace()){
            return false;
        }
    return true;
}
void MainWindow::on_new_btn_clicked()
{
 QString name=ui->nom_edt->toPlainText();
 if(name!=""){
     if(checkAlpha(name)){
         ui->tableOfNames->insertRow(ui->tableOfNames->rowCount());
         QTableWidgetItem* itemName= new QTableWidgetItem(name);
         QWidget* btn=createDeleteButton();
         ui->tableOfNames->setItem( ui->tableOfNames->rowCount()-1, 0,itemName);
         ui->tableOfNames->setCellWidget(ui->tableOfNames->rowCount()-1, 1, btn);
         ui->nom_edt->clear();
     }else{
         QMessageBox::warning(this,"Warning","Name have to be alphabetic");
     }
 }else{
       QMessageBox::warning(this,"Warning","Name can't be empty");
 }

}

void MainWindow::on_next_btn_clicked()
{


    QStringList names;
    //Fill names from QTableWidget
    for (int row = 0; row < ui->tableOfNames->rowCount(); row++) {
        QTableWidgetItem *item = ui->tableOfNames->item(row, 0);
        names << item->text();
    }
    game=new GameInterface(this);
    /*vector<Player> players;
    vector<Establishment*> est;
    vector<Landmark*> land;
    for(auto name : names){
        Player* p=new Player(name,est,land);
    }*/
    game->receiveData(ui->expansions_cb->currentText(),names);
    game->constructInterface();
    this->hide();
    game->show();

}


void MainWindow::on_expansions_cb_currentTextChanged(const QString &arg1)
{


    QString fileName = "/Users/omarelloumi/Documents/MachiKoroV1/build-MachiKoro-UI-App-Qt_6_4_1_for_macOS-Debug/Pictures/"+arg1+".png";

    if (!QFile::exists(fileName)) {
        ui->label_img->setText("Can't find image, try again later.");

    }else{
        QPixmap img(fileName);
       ui->label_img->setPixmap(img);
    }
    ui->label_img->setScaledContents(true);
    ui->label_img->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->label_img->setMinimumSize(1, 1);
}

