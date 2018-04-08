#ifndef MATRIX_INVERSE_H
#define MATRIX_INVERSE_H

#include <QDialog>

namespace Ui {
class matrix_inverse;
}

class matrix_inverse : public QDialog
{
    Q_OBJECT

public:
    explicit matrix_inverse(QWidget *parent = 0);
    ~matrix_inverse();

private slots:
    void on_pushButton_clicked();

private:
    Ui::matrix_inverse *ui;
};

#endif // MATRIX_INVERSE_H
