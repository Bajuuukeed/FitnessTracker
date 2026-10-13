//
// Created by Cata on 10/9/2026.
//

#ifndef FITNESSTRACKER_SIGNUPPAGE_H
#define FITNESSTRACKER_SIGNUPPAGE_H
#include <QWidget>
#include <QLabel>
class SignUpPage : public QWidget{
    Q_OBJECT
public:
    SignUpPage(QWidget*parent = nullptr);
private:
    QLabel* fundalgif;
private slots:
    void amdejacont();
    void submitlacont();
};


#endif //FITNESSTRACKER_SIGNUPPAGE_H