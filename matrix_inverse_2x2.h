#ifndef MATRIX_INVERSE_2X2_H
#define MATRIX_INVERSE_2X2_H

#include <QDialog>

namespace Ui {
class matrix_inverse_2x2;
}

class matrix_inverse_2x2 : public QDialog
{
    Q_OBJECT

public:
    explicit matrix_inverse_2x2(QWidget *parent = 0);
    ~matrix_inverse_2x2();

    void getMatrixWithoutRowAndCol(double **matrix, int size, int row, int col, double **newMatrix);
    double matrixDet(double **matrix, int size);
    double** InverseMatrix(double **a, double **b, bool &error, int size);

private slots:
    void on_pushButton_clear_clicked();

    void on_pushButton_clear_res_clicked();

    void on_pushButton_inverse_2x2_clicked();

private:
    Ui::matrix_inverse_2x2 *ui;
};

#endif // MATRIX_INVERSE_2X2_H
