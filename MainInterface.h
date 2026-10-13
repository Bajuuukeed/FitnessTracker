
#ifndef FITNESSTRACKER_MAININTERFACE_H
#define FITNESSTRACKER_MAININTERFACE_H
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
struct Exercitiu {
    QString nume;
    QString calePoza;
};
class MainInterface : public QWidget {
    Q_OBJECT
public:
     MainInterface(QWidget*parent = nullptr);
    void primesteNume(QString nume);
    void primesteParola(QString parola);
    void submituldelaprofil();
private:
    QMap<QString, QList<Exercitiu>> bazaDeDateExercitii;
    QLabel* afisajCronometru;
    QPushButton* butonStartStop;
    QTimer* ceasAntrenament;
    int secundeTrecute = 0;
    bool cronometruMerge = false;
    QString parolaCurenta;
    QComboBox* splituri;
    QComboBox* cezidesplit;
    QPushButton *adaugapa;
    QWidget* widgetpentrusplituri;
    QWidget* widgetpentrucalorii;
    QWidget* widgetpentruprofil;
    QWidget* widgetpentruapa;
    QWidget *widgetpentrutimer;
    QListWidget* ceamadaugat;
    QLabel* labelTotalCalorii;
    QLabel* numelalogare;
    QLabel* eroare;
    QLabel*eroare2;
    QLineEdit*textparola;
    QListWidget* numaramapa;
    QLineEdit* textschimbnume;
    int totalCaloriiZilnic = 0;
    QPushButton* butonStergeMasa;
    QWidget* containerExercitii;
    QVBoxLayout* layoutExercitii;

private slots:
    void updateazaCronometru();
    void apasareButonStartStop();
    void adaugaapa();
    void schimbarepeapa();
    void schimbarepetimer();
    void primesteMasa(QString nume, int calorii);
    void alegerezidesplit();
    void schimbarepecalorii();
    void schimbarepentruprofil();
    void schimbarepesplit();
    void adaugamasa();
    void stergeRandulSelectat();
    void afiseazaExercitii(QString zi);
    QWidget* creeazaCardExercitiu(QString nume, QString calePoza);









};


#endif //FITNESSTRACKER_MAININTERFACE_H