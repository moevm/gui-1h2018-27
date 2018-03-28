#include "matrix_inverse.h"
#include "ui_matrix_inverse.h"

matrix_inverse::matrix_inverse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matrix_inverse)
{
    ui->setupUi(this);


}

matrix_inverse::~matrix_inverse()
{
    delete ui;
}
