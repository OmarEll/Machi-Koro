#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QTextEdit>
#include <string>
#include<ctype.h>
#include <QMessageBox>
#include <cctype>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_delete_btn_clicked()
{
    //sender(): QPushButton
    QWidget *w = qobject_cast<QWidget *>(sender()->parent());
     if(w){
         int row = ui->tableOfNames->indexAt(w->pos()).row();
         QString s = QString::number(row);
         ui->nom_edt->setText(s);
         ui->tableOfNames->removeRow(row);
         ui->tableOfNames->setCurrentCell(0, 0);
     }
}

QWidget* MainWindow::createDeleteButton(){
    QWidget* pWidget = new QWidget();
    QPushButton* btn_remove = new QPushButton();
    btn_remove->setText("Remove");
    connect(btn_remove, &QPushButton::clicked, this, &MainWindow::on_delete_btn_clicked);
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

}

