#ifndef MATRIX_DET_H
#define MATRIX_DET_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class matrix_det;
}

class matrix_det : public QDialog
{
    Q_OBJECT

private:

    QLineEdit *line1;
    QLineEdit *line2;
    QLineEdit *line3;
    QLineEdit *line4;
    QLineEdit *line5;

    QLineEdit *line6;
    QLineEdit *line7;
    QLineEdit *line8;
    QLineEdit *line9;
    QLineEdit *line10;

    QLineEdit *line11;
    QLineEdit *line12;
    QLineEdit *line13;
    QLineEdit *line14;
    QLineEdit *line15;

    QLineEdit *line16;
    QLineEdit *line17;
    QLineEdit *line18;
    QLineEdit *line19;
    QLineEdit *line20;

    QLineEdit *line21;
    QLineEdit *line22;
    QLineEdit *line23;
    QLineEdit *line24;
    QLineEdit *line25;

public:
    explicit matrix_det(QWidget *parent = 0);

    ~matrix_det();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::matrix_det *ui;
};

#endif // MATRIX_DET_H
