/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *new_btn;
    QTableWidget *tableOfNames;
    QPushButton *next_btn;
    QLabel *label_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QTextEdit *nom_edt;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(915, 694);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(380, 0, 141, 51));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 30, 261, 51));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);
        new_btn = new QPushButton(centralwidget);
        new_btn->setObjectName("new_btn");
        new_btn->setGeometry(QRect(20, 190, 100, 32));
        tableOfNames = new QTableWidget(centralwidget);
        if (tableOfNames->columnCount() < 2)
            tableOfNames->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableOfNames->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableOfNames->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableOfNames->setObjectName("tableOfNames");
        tableOfNames->setGeometry(QRect(260, 110, 581, 321));
        tableOfNames->setSelectionMode(QAbstractItemView::SingleSelection);
        tableOfNames->setRowCount(0);
        next_btn = new QPushButton(centralwidget);
        next_btn->setObjectName("next_btn");
        next_btn->setGeometry(QRect(260, 530, 171, 51));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 120, 101, 16));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 150, 201, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        nom_edt = new QTextEdit(widget);
        nom_edt->setObjectName("nom_edt");

        horizontalLayout->addWidget(nom_edt);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Hello! ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Welcome to Machi Koro game simulator!", nullptr));
        new_btn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableOfNames->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableOfNames->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Action", nullptr));
        next_btn->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Add new player", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        nom_edt->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
