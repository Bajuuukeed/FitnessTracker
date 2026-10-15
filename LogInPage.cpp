#include "LogInPage.h"
#include "MainInterface.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMovie>
#include "SignUpPage.h"
#include <QImageReader>
#include <QIcon>
#include <QFontDatabase>
#include <QFont>
LogInPage::LogInPage(QWidget* parent) : QWidget(parent) {
    int IDFONT1  = QFontDatabase::addApplicationFont("C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/FontTitluri.ttf");
    QString numelefont1 = QFontDatabase::applicationFontFamilies(IDFONT1).at(0);

    this->setWindowIcon(QIcon("C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/icon.png"));

    setWindowTitle("Fitness Tracking-Calculator");
    QIcon*icon = new QIcon("");



    this->setFixedHeight(500);
    this->setFixedWidth(550);

    fundalAnimat = new QLabel(this);
    QMovie* animatie = new QMovie("C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/GIFULMEU.gif");
    fundalAnimat->setMovie(animatie);
    fundalAnimat->resize(this->size());
    fundalAnimat->setScaledContents(true);
    animatie->start();


    QVBoxLayout* layoutprincipal = new QVBoxLayout();
    layoutprincipal->setSpacing(20);
    layoutprincipal->setContentsMargins(40, 20, 40, 30);

    QLabel* titlu = new QLabel("Log-In");
    titlu->setStyleSheet(
        "font-size: 60px;"
         "font-family: '" + numelefont1 + "';"
        "font-weight: bold;"
        "color: #ffffff;"
    );
    layoutprincipal->addWidget(titlu, 0, Qt::AlignHCenter);




    QString stilLabel = "color: white; font-size: 16px; font-weight: bold;";

    QLabel* textusername = new QLabel("Adauga numele tau");
    textusername->setStyleSheet(stilLabel);
    layoutprincipal->addWidget(textusername);

    username = new QLineEdit();
    username->setStyleSheet(
        " background-color:black;"
        "    color: white;"
        "    font-size: 18px;"
        "    padding: 10px 15px;"
        "    border: 1px solid white;"
        "    border-radius: 8px;");
    username->setMinimumHeight(45);
    layoutprincipal->addWidget(username);

    QLabel* textparola = new QLabel("Adauga parola ta");
    textparola->setStyleSheet(stilLabel);
    layoutprincipal->addWidget(textparola);

    parola = new QLineEdit();
    parola->setStyleSheet(  " background-color:black;"
        "    color: white;"
        "    font-size: 18px;"
        "    padding: 10px 15px;"
        "    border: 1px solid white;"
        "    border-radius: 8px;");
    parola->setMinimumHeight(45);
    parola->setEchoMode(QLineEdit::Password);
    layoutprincipal->addWidget(parola);


    QPushButton* linkNuAiCont = new QPushButton("Nu ai cont? Creează unul.");
    linkNuAiCont->setCursor(Qt::PointingHandCursor);
    linkNuAiCont->setStyleSheet(
        "QPushButton {"
        "    color: #ffcccc;"
        "    background-color: transparent;"
        "    border: none;"
        "    font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "    color: white;"
        "    text-decoration: underline;"
        "}"
    );

    layoutprincipal->addWidget(linkNuAiCont, 0, Qt::AlignLeft);

    layoutprincipal->addSpacing(15); 
    
    QPushButton* butonLogare = new QPushButton("Log in");
    butonLogare->setStyleSheet(
        "QPushButton {"
        "    background-color: #575353;"
        "    color: white;"
        "    border-radius: 15px;"
        "    padding: 12px 50px;"
        "    font-size: 18px;"
        "    font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "    background-color: #121111;"
        "}"
    );

    eroare = new QLabel("!Va rugam sa completati toate campurile!");
    eroare->setStyleSheet(
    "color:#ff4c4c;"
      "font-size:15px;"
      "font-weight:bold;"
        );
    eroare->hide();
    layoutprincipal->addWidget(eroare,0,Qt::AlignCenter);


    layoutprincipal->addWidget(butonLogare, 0, Qt::AlignCenter);



    layoutprincipal->addStretch();

    this->setLayout(layoutprincipal);


    connect(butonLogare,&QPushButton::clicked,this,&LogInPage::LogarePagina);
    connect(linkNuAiCont,&QPushButton::clicked,this,&LogInPage::CreareCont);
}


void LogInPage::CreareCont() {
     SignUpPage* crearepagina = new SignUpPage();
     this->hide();
      crearepagina->show();
}
void LogInPage::LogarePagina(){
    QString ceusernameampus = username->text();
    QString ceparolaampus = parola->text();
    if ( ceusernameampus.isEmpty() || ceparolaampus.isEmpty()) {
       eroare->show();
    }
    else {
        eroare->hide();
        this->hide();
        MainInterface* PaginaFitness = new MainInterface();
        connect(this, &LogInPage::trimitenume, PaginaFitness, &MainInterface::primesteNume);
        connect(this, &LogInPage::trimiteparola, PaginaFitness, &MainInterface::primesteParola); 
        emit trimitenume(ceusernameampus);
        emit trimiteparola(ceparolaampus);
        PaginaFitness->show();
    }
}
