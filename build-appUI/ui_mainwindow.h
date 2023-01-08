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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QTableWidget *tableOfNames;
    QPushButton *next_btn;
    QLabel *label_img;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QComboBox *expansions_cb;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QTextEdit *nom_edt;
    QPushButton *new_btn;
    QPushButton *pushButton;

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
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 30, 381, 51));
        label_2->setFont(font);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);
        tableOfNames = new QTableWidget(centralwidget);
        if (tableOfNames->columnCount() < 2)
            tableOfNames->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableOfNames->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableOfNames->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableOfNames->setObjectName("tableOfNames");
        tableOfNames->setGeometry(QRect(10, 190, 211, 441));
        tableOfNames->setSelectionMode(QAbstractItemView::SingleSelection);
        tableOfNames->setRowCount(0);
        next_btn = new QPushButton(centralwidget);
        next_btn->setObjectName("next_btn");
        next_btn->setGeometry(QRect(720, 640, 171, 41));
        label_img = new QLabel(centralwidget);
        label_img->setObjectName("label_img");
        label_img->setGeometry(QRect(260, 80, 631, 481));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(430, 570, 221, 61));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);

        expansions_cb = new QComboBox(layoutWidget);
        expansions_cb->setObjectName("expansions_cb");

        verticalLayout->addWidget(expansions_cb);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 80, 211, 101));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");
        QFont font1;
        font1.setBold(true);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        nom_edt = new QTextEdit(layoutWidget1);
        nom_edt->setObjectName("nom_edt");
        nom_edt->setMaximumSize(QSize(200, 100));

        horizontalLayout->addWidget(nom_edt);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        new_btn = new QPushButton(layoutWidget1);
        new_btn->setObjectName("new_btn");

        verticalLayout_3->addWidget(new_btn);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 40, 91, 32));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Hello! ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Welcome to Machi Koro game simulator!", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableOfNames->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableOfNames->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Action", nullptr));
        next_btn->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        label_img->setText(QCoreApplication::translate("MainWindow", "img", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Choose expansion", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Add new player", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        nom_edt->setPlaceholderText(QString());
        new_btn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "add AI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
