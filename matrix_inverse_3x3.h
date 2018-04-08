#ifndef MATRIX_INVERSE_3X3_H
#define MATRIX_INVERSE_3X3_H

#include <QDialog>

namespace Ui {
class matrix_inverse_3x3;
}

class matrix_inverse_3x3 : public QDialog
{
    Q_OBJECT

public:
    explicit matrix_inverse_3x3(QWidget *parent = 0);
    ~matrix_inverse_3x3();

private slots:
    void on_pushButton_clear_clicked();

    void on_pushButton_clear_res_clicked();

private:
    Ui::matrix_inverse_3x3 *ui;
};

#endif // MATRIX_INVERSE_3X3_H
