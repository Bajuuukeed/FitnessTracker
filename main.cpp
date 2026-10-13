#include <QApplication>
#include <QDebug>
#include <QWidget>
#include "MainInterface.h"
#include "LogInPage.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    LogInPage*pagprinc = new LogInPage();
    pagprinc->show();
    return QApplication::exec();
}