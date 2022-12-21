#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QFile file("/Users/omarelloumi/Documents/MachiKoroV1/build-MachiKoro-UI-App-Qt_6_4_1_for_macOS-Debug/style.css");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        app.setStyleSheet(styleSheet);
        file.close();
    }
    MainWindow w;
    w.show();

    return app.exec();
}












