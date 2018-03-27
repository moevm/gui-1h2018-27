#ifndef MATRIX_DET_3X3_H
#define MATRIX_DET_3X3_H

#include <QDialog>

namespace Ui {
class matrix_det_3x3;
}

class matrix_det_3x3 : public QDialog
{
    Q_OBJECT

public:
    explicit matrix_det_3x3(QWidget *parent = 0);
    ~matrix_det_3x3();

private slots:
    void on_pushButton_clear_clicked();

private:
    Ui::matrix_det_3x3 *ui;
};

#endif // MATRIX_DET_3X3_H
