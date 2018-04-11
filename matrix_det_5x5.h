#ifndef MATRIX_DET_5X5_H
#define MATRIX_DET_5X5_H

#include <QDialog>

namespace Ui {
class matrix_det_5x5;
}

class matrix_det_5x5 : public QDialog
{
    Q_OBJECT

public:
    explicit matrix_det_5x5(QWidget *parent = 0);
    ~matrix_det_5x5();

    void getMatrixWithoutRowAndCol(double **matrix, int size, int row, int col, double **newMatrix);
    double matrixDet(double **matrix, int size);

private slots:
    void on_pushButton_clear_clicked();

    void on_pushButton_det_5x5_clicked();

private:
    Ui::matrix_det_5x5 *ui;
};

#endif // MATRIX_DET_5X5_H
