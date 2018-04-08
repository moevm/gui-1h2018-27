#ifndef MATRIX_H
#define MATRIX_H

#include <QDialog>

namespace Ui {
class matrix;
}

class matrix : public QDialog
{
    Q_OBJECT

public:
    explicit matrix(QWidget *parent = 0);
    ~matrix();

private slots:
    void on_pushButton_matrix_det_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::matrix *ui;
};

#endif // MATRIX_H
