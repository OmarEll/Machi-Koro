/********************************************************************************
** Form generated from reading UI file 'gameinterface.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEINTERFACE_H
#define UI_GAMEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameInterface
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *boardLayout;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *playerName_lbl;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *balance_lbl;
    QTableWidget *actions;

    void setupUi(QDialog *GameInterface)
    {
        if (GameInterface->objectName().isEmpty())
            GameInterface->setObjectName("GameInterface");
        GameInterface->setEnabled(true);
        GameInterface->resize(1305, 694);
        GameInterface->setSizeIncrement(QSize(0, 0));
        GameInterface->setBaseSize(QSize(0, 0));
        gridLayoutWidget = new QWidget(GameInterface);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 170, 541, 521));
        boardLayout = new QGridLayout(gridLayoutWidget);
        boardLayout->setObjectName("boardLayout");
        boardLayout->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_2 = new QWidget(GameInterface);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(550, 430, 361, 261));
        gridLayout = new QGridLayout(gridLayoutWidget_2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(GameInterface);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(550, 400, 101, 16));
        gridLayoutWidget_3 = new QWidget(GameInterface);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(550, 60, 361, 321));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(GameInterface);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(550, 40, 101, 16));
        label_6 = new QLabel(GameInterface);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 150, 101, 16));
        label_7 = new QLabel(GameInterface);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 0, 101, 16));
        pushButton = new QPushButton(GameInterface);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(220, 110, 100, 32));
        layoutWidget = new QWidget(GameInterface);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(710, 0, 201, 51));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        playerName_lbl = new QLabel(layoutWidget);
        playerName_lbl->setObjectName("playerName_lbl");

        horizontalLayout_2->addWidget(playerName_lbl);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_4);

        balance_lbl = new QLabel(layoutWidget);
        balance_lbl->setObjectName("balance_lbl");

        horizontalLayout->addWidget(balance_lbl);


        verticalLayout->addLayout(horizontalLayout);

        actions = new QTableWidget(GameInterface);
        if (actions->columnCount() < 1)
            actions->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        actions->setHorizontalHeaderItem(0, __qtablewidgetitem);
        actions->setObjectName("actions");
        actions->setGeometry(QRect(920, 0, 381, 691));

        retranslateUi(GameInterface);

        QMetaObject::connectSlotsByName(GameInterface);
    } // setupUi

    void retranslateUi(QDialog *GameInterface)
    {
        GameInterface->setWindowTitle(QCoreApplication::translate("GameInterface", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("GameInterface", "Landmarks:", nullptr));
        label_3->setText(QCoreApplication::translate("GameInterface", "Establishments:", nullptr));
        label_6->setText(QCoreApplication::translate("GameInterface", "Board:", nullptr));
        label_7->setText(QCoreApplication::translate("GameInterface", "Dice :", nullptr));
        pushButton->setText(QCoreApplication::translate("GameInterface", "Roll", nullptr));
        label->setText(QCoreApplication::translate("GameInterface", "Current player :", nullptr));
        playerName_lbl->setText(QCoreApplication::translate("GameInterface", "name", nullptr));
        label_4->setText(QCoreApplication::translate("GameInterface", "Balance :", nullptr));
        balance_lbl->setText(QCoreApplication::translate("GameInterface", "balance", nullptr));
        QTableWidgetItem *___qtablewidgetitem = actions->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("GameInterface", "Action", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameInterface: public Ui_GameInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEINTERFACE_H
