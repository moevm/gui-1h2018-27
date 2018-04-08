#ifndef MATRIX_DET_2X2_H
#define MATRIX_DET_2X2_H

#include <QDialog>

namespace Ui {
class matrix_det_2x2;
}

class matrix_det_2x2 : public QDialog
{
    Q_OBJECT

public:
    explicit matrix_det_2x2(QWidget *parent = 0);
    ~matrix_det_2x2();

private slots:
    void on_pushButton_clear_clicked();

    void on_pushButton_det_2x2_clicked();

private:
    Ui::matrix_det_2x2 *ui;
};

#endif // MATRIX_DET_2X2_H
