#include "AdaugaMasa.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QIntValidator> // Adaugam asta pt a forta doar numere la calorii

AdaugaMasa::AdaugaMasa(QWidget*parent): QWidget(parent) {
    this->setWindowTitle("Fitness Tracker - Adauga Masa");
    this->setWindowIcon(QIcon("C:/Users/Cata/Documents/InformaticaFacultate/ForGitHub/FitnessTracker/icon.jpg"));
    this->setFixedHeight(350);
    this->setFixedWidth(400);
    this->setStyleSheet("background-color: #121212; color: white;");

    QVBoxLayout* layoutprincipal = new QVBoxLayout(this);
    layoutprincipal->setContentsMargins(30, 30, 30, 30);
    layoutprincipal->setSpacing(15);

    // Stiluri refolosibile
    QString styleLabels = "font-size: 16px; font-weight: bold; color:white;";
    QString styleInputs = "background-color: black; color: white; font-size: 16px; padding: 10px; border: 1px solid white; border-radius: 8px;";

    QLabel* adaugamancare = new QLabel("Ce ai mancat azi?");
    adaugamancare->setStyleSheet(styleLabels);
    mancaretext = new QLineEdit();
    mancaretext->setStyleSheet(styleInputs);

    QLabel* adaugacalorii = new QLabel("Numar calorii:");
    adaugacalorii->setStyleSheet(styleLabels);
    caloriitext = new QLineEdit();
    caloriitext->setStyleSheet(styleInputs);
    caloriitext->setValidator(new QIntValidator(0, 10000));

    QPushButton* submitbutton = new QPushButton("Adauga Masa");
    submitbutton->setStyleSheet(
        "QPushButton {"
        "    background-color: #575353;"
        "    color: white;"
        "    border-radius: 10px;"
        "    padding: 12px;"
        "    font-size: 18px;"
        "    font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "    background-color:black;"
        "    color: white;"
        "}"
    );

    layoutprincipal->addWidget(adaugamancare);
    layoutprincipal->addWidget(mancaretext);
    layoutprincipal->addWidget(adaugacalorii);
    layoutprincipal->addWidget(caloriitext);
    layoutprincipal->addSpacing(10);
    layoutprincipal->addWidget(submitbutton);

    connect(submitbutton,&QPushButton::clicked,this,&AdaugaMasa::dausubmit);
}

void AdaugaMasa::dausubmit() {
    QString nume = mancaretext->text();
    QString caloriiStr = caloriitext->text();

    if (!nume.isEmpty() && !caloriiStr.isEmpty()) {
        int calorii = caloriiStr.toInt();
        emit masaTrimisa(nume, calorii);
        this->close();
    }
}