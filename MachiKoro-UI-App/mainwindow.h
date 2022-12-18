#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    QWidget* createDeleteButton();

    void on_delete_btn_clicked();

    void on_new_btn_clicked();

    void on_next_btn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
