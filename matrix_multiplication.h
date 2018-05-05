#ifndef MATRIX_MULTIPLICATION_H
#define MATRIX_MULTIPLICATION_H

#include <QDialog>

namespace Ui {
class matrix_multiplication;
}

class matrix_multiplication : public QDialog
{
    Q_OBJECT

public:
    explicit matrix_multiplication(QWidget *parent = 0);
    ~matrix_multiplication();

    int i;
    int o;
    int p;
    int a, b, c;

    double **MultiplicationMatrix(double **a, double **b, int lsize, int msize, int nsize);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::matrix_multiplication *ui;
};

#endif // MATRIX_MULTIPLICATION_H
