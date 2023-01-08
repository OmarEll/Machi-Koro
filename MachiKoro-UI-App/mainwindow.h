#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "gameinterface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int count;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    QWidget* createDeleteButton();

    void on_deleteBtnClicked();

    void on_new_btn_clicked();

    void on_next_btn_clicked();

    void initWindow();

    void on_expansions_cb_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    GameInterface *game;

};
#endif // MAINWINDOW_H
