#ifndef MATRIX_DET_4X4_H
#define MATRIX_DET_4X4_H

#include <QDialog>

namespace Ui {
class matrix_det_4x4;
}

class matrix_det_4x4 : public QDialog
{
    Q_OBJECT

public:
    explicit matrix_det_4x4(QWidget *parent = 0);
    ~matrix_det_4x4();

private slots:
    void on_pushButton_clear_clicked();

    void on_pushButton_det_4x4_clicked();

private:
    Ui::matrix_det_4x4 *ui;
};

#endif // MATRIX_DET_4X4_H
