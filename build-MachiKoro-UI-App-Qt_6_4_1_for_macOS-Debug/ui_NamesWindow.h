/********************************************************************************
** Form generated from reading UI file 'NamesWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAMESWINDOW_H
#define UI_NAMESWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NamesWindow
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *NamesWindow)
    {
        if (NamesWindow->objectName().isEmpty())
            NamesWindow->setObjectName("NamesWindow");
        NamesWindow->resize(400, 300);
        pushButton = new QPushButton(NamesWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 130, 100, 32));

        retranslateUi(NamesWindow);

        QMetaObject::connectSlotsByName(NamesWindow);
    } // setupUi

    void retranslateUi(QDialog *NamesWindow)
    {
        NamesWindow->setWindowTitle(QCoreApplication::translate("NamesWindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("NamesWindow", "YES", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NamesWindow: public Ui_NamesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAMESWINDOW_H
