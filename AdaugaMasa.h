#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>

class AdaugaMasa : public QWidget {
    Q_OBJECT
public:
    explicit AdaugaMasa(QWidget* parent = nullptr);
    signals:
    void masaTrimisa(QString nume, int calorii);

private slots:
    void dausubmit();

private:
    QLineEdit* mancaretext;
    QLineEdit* caloriitext;
};