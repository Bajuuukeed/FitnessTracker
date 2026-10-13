#include "MainInterface.h"
#include "AdaugaMasa.h"
#include "LogInPage.h"
#include <QVBoxLayout>
#include <QWidget>
#include <QHBoxLayout>
#include <QLayout>
#include <QComboBox>
#include <QFontDatabase>
#include <QPushButton>
#include <QMovie>
#include <QListWidget>
#include <QTime>
#include <QTimer>
#include <QScrollArea>
MainInterface::MainInterface(QWidget*parent): QWidget(parent)
{
    int IDFONT1  = QFontDatabase::addApplicationFont("C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/FontTitluri.ttf");
    QString numelefont1 = QFontDatabase::applicationFontFamilies(IDFONT1).at(0);
    bazaDeDateExercitii["Zi de Push"] = {
        {"1. Impins plan cu haltera (Piept)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/push1.jpg"},
        {"2. Presa Militara din sezut (Umeri)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/push2.jpg"},
        {"3. Extensii la scripete (Triceps)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/push3.jfif"},
        {"4. Fluturari la cabluri (Piept)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/push4.jfif"}
    };

    bazaDeDateExercitii["Zi de Pull"] = {
        {"1. Tractiuni la bara (Spate)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/pull1.jfif"},
        {"2. Ramat cu haltera (Spate)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/pull2.jfif"},
        {"3. Flexii cu haltera (Biceps)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/pull3.jfif"},
        {"4. Face-pulls la cablu (Umeri spate)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/pull4.jfif"}
    };

    bazaDeDateExercitii["Zi de Legs"] = {
        {"1. Genuflexiuni cu haltera (Cvadricops)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/legs1.jfif"},
        {"2. Presa pentru picioare", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/legs2.jfif"},
        {"3. Indreptari romanesti (Biceps Femural)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/legs3.jfif"},
        {"4. Ridicari pe varfuri (Gambe)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/legs4.jfif"}
    };
    bazaDeDateExercitii["Zi de Upper"] = {
        {"1. Impins cu haltera (Piept)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/pull1.jfif"},
        {"2. Ramat din aplecat (Spate)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/pull2.jfif"},
        {"3. Presa cu gantere (Umeri)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/pull3.jfif"},
        {"4. Tractiuni (Spate)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/upper4.jfif"},
    };
    bazaDeDateExercitii["Zi de Lower"] = {
        {"1. Genuflexiuni (Cvadricops)", ""},
        {"2. Indreptari (Posterior/Spate Jos)", ""},
        {"3. Fandari cu gantere", ""},
        {"4. Extensii la aparat (Cvadricops)", ""}
    };
    bazaDeDateExercitii["Zi de Piept"] = {
        {"1. Impins plan cu haltera", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/push1.jpg"},
        {"2. Impins inclinat cu gantere", ""},
        {"3. Fluturari la aparat (Pec Deck)", ""},
        {"4. Flotari la paralele (Dips)", ""}
    };
    bazaDeDateExercitii["Zi de Spate"] = {
        {"1. Indreptari clasice (Deadlift)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/legs3.jfif"},
        {"2. Tractiuni la helcometru", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/upper4.jfif"},
        {"3. Ramat la cablu din sezut", ""},
        {"4. Pullover cu gantera", ""}
    };
    bazaDeDateExercitii["Zi de Umeri"] = {
        {"1. Presa Militara cu haltera", ""},
        {"2. Ridicari laterale cu gantere", ""},
        {"3. Ridicari frontale cu discul", ""},
        {"4. Reverse Pec-Deck (Umeri spate)", ""}
    };
    bazaDeDateExercitii["Zi de Picioare"] = {
        {"1. Genuflexiuni cu haltera", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/legs1.jfif"},
        {"2. Presa pentru picioare", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/legs2.jfif"},
        {"3. Flexii la aparat (Femural)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/legs3.jfif"},
        {"4. Extensii la aparat (Cvadricops)", "C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/legs4.jfif"}
    };
    bazaDeDateExercitii["Zi de Brate"] = {
        {"1. Flexii cu haltera Z (Biceps)", ""},
        {"2. Extensii la cablu deasupra capului (Triceps)", ""},
        {"3. Flexii Hammer cu gantere (Brahial)", ""},
        {"4. Extensii cu funia la cablu (Triceps)", ""}
    };
    bazaDeDateExercitii["Esti un adevarat monstru!"] = {
        {"1. Genuflexiuni (Picioare)", ""},
        {"2. Impins cu haltera (Piept)", ""},
        {"3. Tractiuni (Spate)", ""},
        {"4. Presa Militara (Umeri)", ""},
        {"5. Indreptari (Spate Jos / Picioare)", ""}
    };
    this->setWindowIcon(QIcon("C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/icon.png"));
    setWindowTitle("Fitness Tracking-Calculator");
    this->setFixedHeight(600);
    this->setFixedWidth(900);

    QLabel* fundalgif = new QLabel(this);
    QMovie* animatie = new QMovie("C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/GIFULMEU1.gif");
    fundalgif->setMovie(animatie);
    fundalgif->setScaledContents(true);
    fundalgif->resize(900, 600);
    animatie->start();
    fundalgif->lower();

    QHBoxLayout *layoutprincipal = new QHBoxLayout(this);
    layoutprincipal->setContentsMargins(15, 15, 15, 15);
    layoutprincipal->setSpacing(20);

    QWidget* widgetstanga = new QWidget();
    widgetstanga->setFixedWidth(90);
    widgetstanga->setStyleSheet(
        "background-color: rgba(0, 0, 0, 180);"
        "border: 1px solid white;"
        "border-radius: 15px;"
    );

    QVBoxLayout* meniuri = new QVBoxLayout(widgetstanga);
    meniuri->setContentsMargins(5, 20, 5, 20);
    meniuri->setAlignment(Qt::AlignHCenter);

    QPushButton* meniutracker = new QPushButton();
    QPushButton* meniucalorii = new QPushButton();
    QPushButton* meniutimer = new QPushButton();
    QPushButton* meniuprofil = new QPushButton();
    QPushButton* meniuhidratare = new QPushButton();

    meniutracker->setFixedSize(65, 65);
    meniutracker->setStyleSheet(
     "QPushButton {"
     "    border-image: url(C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/muscleicon.png);"
     "}"
     "QPushButton:hover {"
     "    background-color: rgba(255, 255, 255, 50);"
     "}"
    );

    meniucalorii->setFixedSize(65, 65);
    meniucalorii->setStyleSheet(
    "QPushButton {"
"    border-image: url(C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/foodicon.png);"
"}"
"QPushButton:hover {"
"    background-color: rgba(255, 255, 255, 50);"
"}");
    meniuprofil->setFixedSize(65, 65);
    meniuprofil->setStyleSheet(
    "QPushButton {"
"    border-image: url(C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/profileicon.png);"
"}"
"QPushButton:hover {"
"    background-color: rgba(255, 255, 255, 50);"
"}");
    meniuhidratare->setFixedSize(65, 65);
    meniuhidratare->setStyleSheet(
    "QPushButton {"
"    border-image: url(C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/watericon.png);"
"}"
"QPushButton:hover {"
"    background-color: rgba(255, 255, 255, 50);"
"}");
    meniutimer->setFixedSize(65, 65);
    meniutimer->setStyleSheet(
    "QPushButton {"
"    border-image: url(C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/timericon.png);"
"}"
"QPushButton:hover {"
"    background-color: rgba(255, 255, 255, 50);"
"}");

    meniuri->addWidget(meniutracker);
    meniuri->addSpacing(10);
    meniuri->addWidget(meniucalorii);
    meniuri->addSpacing(10);
    meniuri->addWidget(meniuprofil);
    meniuri->addSpacing(10);
    meniuri->addWidget(meniuhidratare);
    meniuri->addSpacing(10);
    meniuri->addWidget(meniutimer);
    meniuri->addStretch();


    widgetpentrusplituri = new QWidget();
    QVBoxLayout* layoutsplituri = new QVBoxLayout(widgetpentrusplituri);
    layoutsplituri->setContentsMargins(10, 40, 20, 10);

    splituri = new QComboBox();
    splituri->setStyleSheet(
    "QComboBox {"
    "    background-color: black;"
    "    color: white;"
    "    border: 1px solid white;"
    "    border-radius: 8px;"
    "    padding: 10px 15px;"
    "    font-size: 16px;"
    "    font-weight: bold;"
    "}"
    "QComboBox:hover {"
    "    border: 1px solid #ffcccc;"
    "}"
    "QComboBox::drop-down {"
    "    subcontrol-origin: padding;"
    "    subcontrol-position: top right;"
    "    width: 35px;"
    "    border-left: 1px solid white;"
    "}"
    "QComboBox QAbstractItemView {"
    "    background-color: black;"
    "    color: white;"
    "    border: 1px solid white;"
    "    selection-background-color: #575353;"
    "    selection-color: white;"
    "    outline: none;"
    "}"
    );

    splituri->addItem("Alege split-ul tau..");
    splituri->addItem("Push-Pull-Legs");
    splituri->addItem("Upper-Lower");
    splituri->addItem("Bro-Split");
    splituri->addItem("Full Body");

    cezidesplit = new QComboBox();
    cezidesplit->setStyleSheet(splituri->styleSheet());
    cezidesplit->addItem("Adauga split-ul mai intai..");

    layoutsplituri->addWidget(splituri);
    layoutsplituri->addSpacing(15);
    layoutsplituri->addWidget(cezidesplit);

    containerExercitii = new QWidget();
    layoutExercitii = new QVBoxLayout(containerExercitii);
    layoutExercitii->setAlignment(Qt::AlignTop);

    QScrollArea* zonaScroll = new QScrollArea();
    zonaScroll->setWidget(containerExercitii);
    zonaScroll->setWidgetResizable(true);
    zonaScroll->setStyleSheet("background-color: transparent; border: none;");

    layoutsplituri->addWidget(zonaScroll);

    widgetpentrucalorii = new QWidget();
    QVBoxLayout* caloriile = new QVBoxLayout(widgetpentrucalorii);
    caloriile->setContentsMargins(0, 30, 0, 10);

    QLabel* titlu = new QLabel("Evalueaza caloriile");
    titlu->setStyleSheet(
        "font-size: 50px;"
        "font-family: '" + numelefont1 + "';"
        "font-weight: bold;"
        "color: #ffffff;"
        "background-color: transparent;"
    );

    QPushButton* adaugare = new QPushButton("Adauga o mancare si caloriile");
    adaugare->setFixedWidth(350);
    adaugare->setFixedHeight(60);
    adaugare->setStyleSheet(
        "QPushButton {"
        "   color:white;"
        "   border-radius: 9px;"
        "   font-size: 18px;"
        "   font-weight: bold;"
        "   background-color: grey;"
        "   border: 1px solid white;"
        "}"
        "QPushButton:hover {"
        "   background-color:black;"
        "}"
    );

    ceamadaugat = new QListWidget();
    ceamadaugat->setFixedHeight(200);
    ceamadaugat->setStyleSheet(
        "QListWidget {"
        "    background-color: rgba(0, 0, 0, 150);"
        "    border: 1px solid white;"
        "    border-radius: 10px;"
        "    color: white;"
        "    font-size: 18px;"
        "    padding: 10px;"
        "}"
        "QListWidget::item {"
        "    padding: 8px;"
        "    border-bottom: 1px solid black;"
        "}"
    );

    labelTotalCalorii = new QLabel("Total azi: 0 kcal");

    labelTotalCalorii->setStyleSheet(
        "font-size: 26px;"
        "font-weight: bold;"
        "color: white;"
        "background-color: transparent;"
    );
    butonStergeMasa = new QPushButton("🗑Sterge un anumit aliment");
    butonStergeMasa->setFixedWidth(350);
    butonStergeMasa->setFixedHeight(40);
    butonStergeMasa->setStyleSheet(
        "QPushButton {"
        "   background-color: rgba(255, 76, 76, 150);"
        "   color: white; border-radius: 9px; font-weight: bold; border: 1px solid white;"
        "}"
        "QPushButton:hover { background-color: rgba(255, 0, 0, 200); }"
    );





    caloriile->addWidget(titlu, 0, Qt::AlignLeft);
    caloriile->addWidget(adaugare, 0, Qt::AlignLeft);
    caloriile->addWidget(butonStergeMasa);
    caloriile->setSpacing(20);
    caloriile->addWidget(ceamadaugat);
    caloriile->addStretch();
    caloriile->addWidget(labelTotalCalorii, 0, Qt::AlignRight);

    widgetpentruprofil = new QWidget();
    QVBoxLayout* layoutprofil = new QVBoxLayout(widgetpentruprofil);
    layoutprofil->setContentsMargins(0, 40, 0, 20);

    numelalogare = new QLabel();
    numelalogare->setStyleSheet(
        "font-size: 30px;"
        "font-family: '" + numelefont1 + "';"
        "color: white;"
        "font-weight: bold;"
        "background-color: transparent;"
    );


    QWidget* cardFormular = new QWidget();
    cardFormular->setFixedWidth(400);
    cardFormular->setStyleSheet(
        "QWidget {"
        "   background-color: rgba(0, 0, 0, 180);"
        "   border: 1px solid white;"
        "   border-radius: 15px;"
        "}"
        "QLabel {"
        "   border: none;"
        "   background-color: transparent;"
        "}"
    );

    QVBoxLayout* layoutCard = new QVBoxLayout(cardFormular);
    layoutCard->setSpacing(15);
    QString styleLabels = "color: white; font-size: 16px; font-weight: bold;";
    QString styleInputs = "background-color: black; color: white; font-size: 16px; padding: 10px; border: 1px solid white; border-radius: 8px;";
    layoutCard->addWidget(numelalogare,0,Qt::AlignHCenter);
    layoutCard->setContentsMargins(30,30,30,30);
    QLabel* schimbnume = new QLabel("Nume nou:");
    schimbnume->setStyleSheet(styleLabels);
    textschimbnume  = new QLineEdit();
    textschimbnume->setStyleSheet(styleInputs);

    QLabel *parolaLabel = new QLabel("Confirmare prin parola:");
    parolaLabel->setStyleSheet(styleLabels);
    textparola = new QLineEdit();
    textparola->setStyleSheet(styleInputs);
    textparola->setEchoMode(QLineEdit::Password);

    QString styleErori = "color: #ff4c4c; font-size: 14px; font-weight: bold;";

    eroare = new QLabel("! Va rugam sa completati tot !");
    eroare->setStyleSheet(styleErori);
    eroare->hide();

    eroare2 = new QLabel("! Parola este gresita !");
    eroare2->setStyleSheet(styleErori);
    eroare2->hide();


    QPushButton* butonsubmitprof = new QPushButton("Salveaza Modificarile");
    butonsubmitprof->setStyleSheet(
        "QPushButton {"
        "    background-color: grey;"
        "    color: white;"
        "    border: 1px solid white;"
        "    border-radius: 10px;"
        "    padding: 12px;"
        "    font-size: 16px;"
        "    font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "    background-color: black;"
        "    color: white;"
        "}"
    );

    layoutCard->addWidget(numelalogare,0,Qt::AlignHCenter);
    layoutCard->addWidget(schimbnume);
    layoutCard->addWidget(textschimbnume);
    layoutCard->addWidget(parolaLabel);
    layoutCard->addWidget(textparola);

    layoutCard->addWidget(eroare, 0, Qt::AlignHCenter);
    layoutCard->addWidget(eroare2, 0, Qt::AlignHCenter);

    layoutCard->addSpacing(10);
    layoutCard->addWidget(butonsubmitprof);
    layoutprofil->addSpacing(30);
    layoutprofil->addWidget(cardFormular, 0, Qt::AlignHCenter);
    layoutprofil->addStretch();


    widgetpentruapa = new QWidget();
    QVBoxLayout *layoutpentruapa = new QVBoxLayout(widgetpentruapa);
    layoutpentruapa->setContentsMargins(0, 30, 0, 10);

    QLabel* titluApa = new QLabel("Hidratare Zilnica");
    titluApa->setStyleSheet(
        "font-size: 50px;"
        "font-family: '" + numelefont1 + "';"
        "font-weight: bold;"
        "color: #ffffff;"
        "background-color: transparent;"
    );

    adaugapa = new QPushButton("+ Am baut un pahar (250 ml)");
    adaugapa->setFixedHeight(60);
    adaugapa->setStyleSheet(
        "QPushButton {"
        "   color:white;"
        "   border-radius: 9px;"
        "   font-size: 18px;"
        "   font-weight: bold;"
        "   background-color: rgba(0, 0, 0, 180);"
        "   border: 1px solid #4da6ff;"
        "}"
        "QPushButton:hover {"
        "   background-color: rgba(77, 166, 255, 50);"
        "}"
    );

    numaramapa = new QListWidget();
    numaramapa->setStyleSheet(
        "QListWidget {"
        "    background-color: rgba(0, 0, 0, 150);"
        "    border: 1px solid #4da6ff;"
        "    border-radius: 10px;"
        "    color: white;"
        "    font-size: 18px;"
        "    padding: 10px;"
        "}"
        "QListWidget::item {"
        "    padding: 8px;"
        "    border-bottom: 1px solid rgba(255, 255, 255, 50);"
        "}"
    );

    layoutpentruapa->addWidget(titluApa, 0, Qt::AlignLeft);
    layoutpentruapa->addWidget(adaugapa);
    layoutpentruapa->addWidget(numaramapa);

    widgetpentrutimer = new QWidget();
    QVBoxLayout *layoutpentrutimer = new QVBoxLayout(widgetpentrutimer);
    layoutpentrutimer->setContentsMargins(0, 40, 0, 40);

    QLabel* titluTimer = new QLabel("Cronometru Antrenament");
    titluTimer->setStyleSheet(titluApa->styleSheet());

    afisajCronometru = new QLabel("00:00:00");
    afisajCronometru->setAlignment(Qt::AlignCenter);
    afisajCronometru->setStyleSheet(
        "font-size: 120px;"
        "font-weight: bold;"
        "color: white;"
        "background-color: rgba(0, 0, 0, 180);"
        "border: 2px solid #ffcccc;"
        "border-radius: 20px;"
        "padding: 20px;"
    );

    butonStartStop = new QPushButton("START");
    butonStartStop->setFixedSize(250, 70);
    butonStartStop->setStyleSheet(
        "QPushButton {"
        "    background-color: #575353;"
        "    color: white;"
        "    border-radius: 35px;"
        "    font-size: 24px;"
        "    font-weight: bold;"
        "    border: 2px solid white;"
        "}"
        "QPushButton:hover {"
        "    background-color: #ffcccc;"
        "    color: black;"
        "}"
    );

    layoutpentrutimer->addWidget(titluTimer, 0, Qt::AlignHCenter);
    layoutpentrutimer->addStretch();
    layoutpentrutimer->addWidget(afisajCronometru, 0, Qt::AlignHCenter);
    layoutpentrutimer->addSpacing(30);
    layoutpentrutimer->addWidget(butonStartStop, 0, Qt::AlignHCenter);
    layoutpentrutimer->addStretch();

    ceasAntrenament = new QTimer(this);
    connect(ceasAntrenament, &QTimer::timeout, this, &MainInterface::updateazaCronometru);
    connect(butonStartStop, &QPushButton::clicked, this, &MainInterface::apasareButonStartStop);


    layoutprincipal->addWidget(widgetstanga);
    layoutprincipal->addWidget(widgetpentrusplituri);
    layoutprincipal->addWidget(widgetpentrucalorii);
    layoutprincipal->addWidget(widgetpentruprofil);
    layoutprincipal->addWidget(widgetpentruapa);
    layoutprincipal->addWidget(widgetpentrutimer);
    widgetpentruapa->hide();
    widgetpentrutimer->hide();
    widgetpentrucalorii->hide();
    widgetpentruprofil->hide();
    this->setLayout(layoutprincipal);
    connect(cezidesplit, &QComboBox::currentTextChanged, this, &MainInterface::afiseazaExercitii);
    connect(butonStergeMasa, &QPushButton::clicked, this, &MainInterface::stergeRandulSelectat);
    connect(adaugapa,&QPushButton::clicked,this,&MainInterface::adaugaapa);
    connect(meniuprofil,&QPushButton::clicked,this, &MainInterface::schimbarepentruprofil);
    connect(splituri, &QComboBox::currentTextChanged, this, &MainInterface::alegerezidesplit);
    connect(meniutracker, &QPushButton::clicked,this,&MainInterface::schimbarepesplit);
    connect(meniucalorii, &QPushButton::clicked,this,&MainInterface::schimbarepecalorii);
    connect(meniuhidratare,&QPushButton::clicked,this,&MainInterface::schimbarepeapa);
    connect(meniutimer,&QPushButton::clicked,this,&MainInterface::schimbarepetimer);
    connect(adaugare,&QPushButton::clicked,this,&MainInterface::adaugamasa);
    connect(butonsubmitprof,&QPushButton::clicked,this, &MainInterface::submituldelaprofil);
}
void MainInterface::schimbarepecalorii() {
    widgetpentrucalorii->show();
    widgetpentrusplituri->hide();
    widgetpentruprofil->hide();
    widgetpentruapa->hide();
    widgetpentrutimer->hide();

}
void MainInterface::schimbarepeapa() {
    widgetpentrucalorii->hide();
    widgetpentrusplituri->hide();
    widgetpentruprofil->hide();
    widgetpentruapa->show();
    widgetpentrutimer->hide();
}
void MainInterface::schimbarepetimer() {
    widgetpentrucalorii->hide();
    widgetpentrusplituri->hide();
    widgetpentruprofil->hide();
    widgetpentruapa->hide();
    widgetpentrutimer->show();
}
void MainInterface::primesteParola(QString parola) {
    parolaCurenta = parola;
}
void MainInterface::submituldelaprofil() {
    QString textusername = textschimbnume->text();
    QString textparolapusa = textparola->text();

    if (textusername.isEmpty() || textparolapusa.isEmpty()) {
        eroare2->hide();
        eroare->show();
    }
    else {
        if (textparolapusa != parolaCurenta) {
            eroare->hide();
            eroare2->show();
        }
        else {
            eroare->hide();
            eroare2->hide();
            numelalogare->setText("Bine ai revenit\n" + textusername + " !");
            textschimbnume->clear();
            textparola->clear();
        }
    }
}
void MainInterface::adaugaapa() {
    QString textTimp = QTime::currentTime().toString("hh:mm:ss");
    numaramapa->addItem("Ati baut apa la ora : " + textTimp);
}
void MainInterface::schimbarepentruprofil() {
    widgetpentrucalorii->hide();
    widgetpentrusplituri->hide();
    widgetpentruprofil->show();
    widgetpentruapa->hide();
    widgetpentrutimer->hide();
}
void MainInterface::schimbarepesplit() {
    widgetpentrucalorii->hide();
    widgetpentrusplituri->show();
    widgetpentruprofil->hide();
    widgetpentruapa->hide();
    widgetpentrutimer->hide();
}
void MainInterface::alegerezidesplit() {
    cezidesplit->clear();
    QString splitales = splituri->currentText();
    if (splitales == "Alege split-ul tau..") {
        cezidesplit->addItem("Adauga split-ul mai intai..");
    }
    else if (splitales == "Push-Pull-Legs") {
        cezidesplit->addItem("Zi de Push");
        cezidesplit->addItem("Zi de Pull");
        cezidesplit->addItem("Zi de Legs");
    }
    else if (splitales == "Upper-Lower") {
        cezidesplit->addItem("Zi de Upper");
        cezidesplit->addItem("Zi de Lower");
    }
    else if (splitales == "Bro-Split") {
        cezidesplit->addItem("Zi de Piept");
        cezidesplit->addItem("Zi de Spate");
        cezidesplit->addItem("Zi de Umeri");
        cezidesplit->addItem("Zi de Picioare");
        cezidesplit->addItem("Zi de Brate");
    }
    else if (splitales == "Full Body") {
        cezidesplit->addItem("Esti un adevarat monstru!");
    }
}
void MainInterface::adaugamasa() {
    AdaugaMasa* a = new AdaugaMasa();
    a->setAttribute(Qt::WA_DeleteOnClose);
    connect(a, &AdaugaMasa::masaTrimisa, this, &MainInterface::primesteMasa);
    a->show();
}
void MainInterface::primesteMasa(QString nume, int calorii) {
    QString textAfisat = nume + ":" + QString::number(calorii) + " kcal";
    QListWidgetItem* randNou = new QListWidgetItem(textAfisat);
    randNou->setData(Qt::UserRole, calorii);
    ceamadaugat->addItem(randNou);
    totalCaloriiZilnic = totalCaloriiZilnic + calorii;
    labelTotalCalorii->setText("Total azi: " + QString::number(totalCaloriiZilnic) + " kcal");
}
void MainInterface::stergeRandulSelectat() {
    QListWidgetItem* randSelectat = ceamadaugat->currentItem();
    if (randSelectat != nullptr) {
        int caloriiDeScazut = randSelectat->data(Qt::UserRole).toInt();
        totalCaloriiZilnic = totalCaloriiZilnic - caloriiDeScazut;
        labelTotalCalorii->setText("Total azi: " + QString::number(totalCaloriiZilnic) + " kcal");
        delete randSelectat;
    }
}
void MainInterface::primesteNume(QString nume) {
    numelalogare->setText("Bine ai revenit\n " + nume + " !");
}
void MainInterface::updateazaCronometru() {
    secundeTrecute++;
    int ore = secundeTrecute / 3600;
    int minute = (secundeTrecute % 3600) / 60;
    int secunde = secundeTrecute % 60;
    QString textTimp = QTime(ore, minute, secunde).toString("hh:mm:ss");
    afisajCronometru->setText(textTimp);
}
void MainInterface::apasareButonStartStop() {
    if (cronometruMerge == false) {
        ceasAntrenament->start(1000);
        cronometruMerge = true;
        butonStartStop->setText("STOP");
        butonStartStop->setStyleSheet(
            "QPushButton { background-color: #ff4c4c; color: white; border-radius: 35px; font-size: 24px; font-weight: bold; border: 2px solid white; }"
            "QPushButton:hover { background-color: #cc0000; }"
        );
    }
    else {
        ceasAntrenament->stop();
        cronometruMerge = false;
        butonStartStop->setText("START");
        butonStartStop->setStyleSheet(
            "QPushButton { background-color: #575353; color: white; border-radius: 35px; font-size: 24px; font-weight: bold; border: 2px solid white; }"
            "QPushButton:hover { background-color: #ffcccc; color: black; }"
        );
    }
}
QWidget* MainInterface::creeazaCardExercitiu(QString nume, QString calePoza) {
    QWidget* card = new QWidget();
    card->setFixedHeight(200);
    card->setStyleSheet("background-color: rgba(0,0,0,150); border: 2px solid white; border-radius: 12px;");
    QHBoxLayout* layoutCard = new QHBoxLayout(card);
    layoutCard->setContentsMargins(15, 15, 15, 15);
    QLabel* poza = new QLabel();
    poza->setFixedSize(160, 160);
    poza->setStyleSheet("border-image: url(" + calePoza + "); border-radius: 8px; border: none;");
    QLabel* textNume = new QLabel(nume);
    textNume->setStyleSheet("color: white; font-size: 26px; font-weight: bold; border: none; background-color: transparent;");
    textNume->setWordWrap(true);
    layoutCard->addWidget(poza);
    layoutCard->addSpacing(30);
    layoutCard->addWidget(textNume);
    layoutCard->addStretch();
    return card;
}
void MainInterface::afiseazaExercitii(QString zi) {
    QLayoutItem* item;
    while ((item = layoutExercitii->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    if (bazaDeDateExercitii.contains(zi)) {
        QList<Exercitiu> exercitiileZilei = bazaDeDateExercitii[zi];
        for (int i = 0; i < exercitiileZilei.size(); i++) {
            QString numeAles = exercitiileZilei[i].nume;
            QString pozaAleasa = exercitiileZilei[i].calePoza;
            QWidget* card = creeazaCardExercitiu(numeAles, pozaAleasa);
            layoutExercitii->addWidget(card);
        }
    }
}