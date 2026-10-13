#include "SignUpPage.h"
#include "LogInPage.h"
#include <QWidget>
#include <QLabel>
#include <QMovie>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFontDatabase>
SignUpPage::SignUpPage(QWidget*parent):QWidget(parent) {
    int IDFONT1  = QFontDatabase::addApplicationFont("C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/FontTitluri.ttf");
    QString numelefont1 = QFontDatabase::applicationFontFamilies(IDFONT1).at(0);


    this->setWindowIcon(QIcon("C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/icon.png"));
    this->setFixedHeight(500);
    this->setFixedWidth(550);
    this->setContentsMargins(40,0,40,10);



    fundalgif = new QLabel(this);
    QMovie* animatie = new QMovie("C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/GIFULMEU.gif");
    fundalgif->setMovie(animatie);
    fundalgif->setScaledContents(true);
    fundalgif->resize(this->size());
    animatie->start();




    QVBoxLayout* layoutprincipal = new QVBoxLayout();
    layoutprincipal->addSpacing(20);


    QLabel *titlu = new QLabel("Sign-up");
    titlu->setStyleSheet(
       "font-size: 60px;"
        "font-family: '" + numelefont1 + "';"
       "font-weight: bold;"
       "color: #ffffff;"
   );
    layoutprincipal->addWidget(titlu, 0 , Qt::AlignHCenter);


    QLabel* username = new QLabel("Adauga username");
    username->setStyleSheet(
    "color: white;"
    "font-size: 16px;"
    "font-weight: bold;"
    );

    layoutprincipal->addWidget(username);


    QLineEdit* textuser = new QLineEdit();
    textuser->setStyleSheet(
    " background-color:black;"
 "    color: white;"
 "    font-size: 18px;"
 "    padding: 10px 15px;"
 "    border: 1px solid white;"
 "    border-radius: 8px;"
    );
    layoutprincipal->addWidget(textuser);

    QLabel*email = new QLabel("Adauga email");
    email->setStyleSheet(username->styleSheet());
    layoutprincipal->addWidget(email);

    QLineEdit* textemail = new QLineEdit();
    textemail->setStyleSheet(textuser->styleSheet());
    layoutprincipal->addWidget(textemail);


    QLabel *parola = new QLabel("Adauga parola");
    parola->setStyleSheet(username->styleSheet());
    layoutprincipal->addWidget(parola);

    QLineEdit* textpar = new QLineEdit();
    textpar->setStyleSheet(textuser->styleSheet());
    textpar->setEchoMode(QLineEdit::Password);
    layoutprincipal->addWidget(textpar);


    QLabel *confirmareparola = new QLabel("Confirma parola");
    confirmareparola->setStyleSheet(username->styleSheet());
    layoutprincipal->addWidget(confirmareparola);

    QLineEdit* textconfirmpar = new QLineEdit();
    textconfirmpar->setStyleSheet(textuser->styleSheet());

    textconfirmpar->setEchoMode(QLineEdit::Password);
    layoutprincipal->addWidget(textconfirmpar);

    QPushButton* alreadyhave = new QPushButton("Ai deja un cont?");

    alreadyhave->setStyleSheet(
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

    layoutprincipal->addWidget(alreadyhave,0,Qt::AlignLeft);
    QPushButton* submitbutton = new QPushButton("Submit");
    submitbutton->setStyleSheet(
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
  "}");
    layoutprincipal->addWidget(submitbutton,0,Qt::AlignCenter);
this->setLayout(layoutprincipal);

    connect(submitbutton,&QPushButton::clicked,this,&SignUpPage::submitlacont);
    connect(alreadyhave,&QPushButton::clicked,this,&SignUpPage::amdejacont);

}
void SignUpPage::amdejacont() {
    LogInPage* amdeja = new LogInPage();
    this->hide();
    amdeja->show();
}

void SignUpPage::submitlacont() {
    LogInPage* amdeja = new LogInPage();
    this->hide();
    amdeja->show();
}