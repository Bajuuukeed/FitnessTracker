#ifndef FITNESSTRACKER_LOGINPAGE_H
#define FITNESSTRACKER_LOGINPAGE_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QLineEdit>
class LogInPage : public QWidget {
    Q_OBJECT
public:
    LogInPage(QWidget *parent = nullptr);

signals:
    void trimitenume(QString username);
    void trimiteparola(QString parola);
private:
    QLabel* fundalAnimat;
    QVBoxLayout* layoutprincipal;
    QLabel* titlu;
    QString stilLabel;
    QLineEdit* username;
    QLineEdit* parola;
    QLabel* eroare;
private slots:
    void LogarePagina();
    void CreareCont();



};


#endif //FITNESSTRACKER_LOGINPAGE_H